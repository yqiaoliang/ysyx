#include <stdio.h>
#include <stdint.h> 
#include <stdlib.h>
#include <string.h> // 用于内存复制

int pc = 0;
int32_t GPR[32];
int8_t RAM[1 << 22];  // 1MB RAM（字节数组）
int8_t ROM[1 << 22];  // 1MB ROM（字节数组）

// 32位字节序转换函数
uint32_t swap_uint32(uint32_t value) {
    return ((value >> 24) & 0x000000FF) |
           ((value >> 8)  & 0x0000FF00) |
           ((value << 8)  & 0x00FF0000) |
           ((value << 24) & 0xFF000000);
}

int load_bin_to_mem(const char *bin_path) {
    FILE *bin_file = fopen(bin_path, "rb");
    if (!bin_file) {
        fprintf(stderr, "Failed to open file: %s\n", bin_path);
        return -1;
    }

    // 获取文件大小
    fseek(bin_file, 0, SEEK_END);
    long file_size = ftell(bin_file);
    fseek(bin_file, 0, SEEK_SET);
    
    // 检查文件是否过大
    if (file_size > sizeof(ROM)) {
        fprintf(stderr, "File too large (%ld bytes), memory size is %zu bytes\n", 
               file_size, sizeof(ROM));
        fclose(bin_file);
        return -1;
    }
    
    // 直接读取到ROM
    size_t read_bytes = fread(ROM, 1, file_size, bin_file);
    fclose(bin_file);
    
    if (read_bytes != file_size) {
        fprintf(stderr, "Read incomplete, expected %ld bytes, got %zu bytes\n", 
               file_size, read_bytes);
        return -1;
    }
    
    // 复制到RAM
    memcpy(RAM, ROM, read_bytes);
    
    // 打印前4字节进行调试（原始数据）
    printf("Raw data at address 0x0: ");
    for (int i = 0; i < 4 && i < read_bytes; i++) {
        printf("%02x ", ROM[i]);
    }
    printf("\n");
    
    // 字节序转换 - 处理所有4字节对齐的字
    for (size_t i = 0; i < read_bytes; i += 4) {
        if (i + 3 >= read_bytes) break;
        
        // 创建无符号32位值
        uint32_t word = *(uint32_t*)&ROM[i];
        uint32_t swapped_word = swap_uint32(word);
        
        // 写回ROM
        *(uint32_t*)&ROM[i] = swapped_word;
        
        // 写回RAM
        *(uint32_t*)&RAM[i] = swapped_word;
        
        // 调试输出
        if (i == 0) {
            printf("After conversion at 0x0: ROM[0..3] = ");
            for (int j = 0; j < 4; j++) {
                printf("%02x ", ROM[j]);
            }
            printf(" (0x%08x)\n", swapped_word);
        }
    }
    
    // 打印转换后的ROM内容
    printf("Converted ROM data at address 0x0: 0x%02x%02x%02x%02x\n", 
           ROM[0], ROM[1], ROM[2], ROM[3]);
    
    return read_bytes;
}

int32_t sign_extend(uint32_t value, int bits) {
    int32_t mask = 1 << (bits - 1);
    if (value & mask) {
        value |= ~((1 << bits) - 1);
    }
    return value;
}

int32_t extract_bits(int left, int right, int32_t value) {
    int width = right - left + 1;
    int result = (value >> left) & ((1 << width) - 1);
    // 符号扩展
    if (result & (1 << (width - 1))) {
        result |= ~((1 << width) - 1);
    }
    return result;
}

uint32_t extract_bits_unsigned(int left, int right, int32_t value) {
    int width = right - left + 1;
    return (value >> left) & ((1 << width) - 1);
}

void inst_cycle(){
    // 使用无符号转换处理每个字节
    int32_t inst = ( ((uint8_t)ROM[pc])        ) |
                ( ((uint8_t)ROM[pc + 1]) << 8  ) |
                ( ((uint8_t)ROM[pc + 2]) << 16 ) |
                ( ((uint8_t)ROM[pc + 3]) << 24 );

    printf("pc: %0x\n", pc);
    printf("inst: %0x\n", inst);
    printf("\n");

    int32_t opcode = extract_bits(0, 6, inst);
    int32_t rd = extract_bits(7, 11, inst);
    int32_t funct3 = extract_bits(12, 14, inst);
    int32_t rs1 = extract_bits(15, 19, inst);
    int32_t rs2 = extract_bits(20, 24, inst);
    int32_t funct7 = extract_bits(25, 31, inst);

    if (pc == 0x2bc){
        printf("opcode: %0x\n", opcode);
        printf("rd: %0x\n", rd);
        printf("funct3: %0x\n", funct3);
        printf("rs1: %0x\n", rs1);
        printf("rs2: %0x\n", rs2);
        printf("funct7: %0x\n", funct7);
    }
    

    // lui
    if (opcode == 0x37) {
        GPR[rd] = extract_bits_unsigned(12,31,inst) << 12;
        pc += 4;
    }
    // jalr
    else if (opcode == 0x67 && funct3 == 0x0) {
        int32_t this_next_pc = pc + 4;
        pc = (GPR[rs1] + extract_bits(20, 31, inst)) & ~1;
        printf("pc: %0x\n", pc);
        GPR[rd] = this_next_pc;
        
    }
    else if (opcode == 0x03) {
        // lw
        if (funct3 == 0x2){
            int32_t addr_base = GPR[rs1] + extract_bits(20, 31, inst);
            GPR[rd] = (((uint8_t)RAM[addr_base]) << 0) | (((uint8_t)RAM[addr_base+1]) << 8) | (((uint8_t)RAM[addr_base+2]) <<16) | (((uint8_t)RAM[addr_base+3]) << 24);
            pc += 4;
        }
        // lbu
        else if (funct3 == 0x4){
            int32_t RAM_data = RAM[GPR[rs1] + extract_bits(20, 31, inst)];
            GPR[rd] = (int32_t)(int8_t)(RAM_data);
            pc += 4;
        }
        else pc += 4;
    }
    else if (opcode == 0x23) {
        // sb
        if (funct3 == 0x0) {
            int32_t imm = (extract_bits_unsigned(25, 31, inst) << 5) | extract_bits_unsigned(7, 11, inst);
            imm = sign_extend(imm, 12);
            if (pc == 0x2bc) {
                printf("sb: pc: %0x, imm: %0x\n", pc, imm);
                printf("addr: %d\n", GPR[rs1]);
            }
            RAM[GPR[rs1] + imm ] = (int8_t)(GPR[rs2]);
            pc += 4;
        }
        // sw
        else if (funct3 == 0x2){
            int32_t imm = (extract_bits_unsigned(25, 31, inst) << 5) | extract_bits_unsigned(7, 11, inst);
            imm = sign_extend(imm, 12);
            RAM[GPR[rs1] + imm] = (int8_t)GPR[rs2];
            RAM[GPR[rs1] + imm + 1] = (int8_t)(GPR[rs2] >> 8);
            RAM[GPR[rs1] + imm + 2] = (int8_t)(GPR[rs2] >> 16);
            RAM[GPR[rs1] + imm + 3] = (int8_t)(GPR[rs2] >> 24);
            pc += 4;
        }
        else pc += 4;
    }
    else if (opcode == 0x13) {
        // addi
        if (funct3 == 0x0) {
            GPR[rd] = GPR[rs1] + (int32_t)extract_bits(20, 31, inst);
            pc += 4;
        }
        else pc += 4;
    }
    // add
    else if (opcode == 0x33 && funct3 == 0x0 && funct7 == 0x0) {
        GPR[rd] = GPR[rs1] + GPR[rs2];
        pc += 4;
    }
    else pc += 4;

    GPR[0] = 0;
}

int main(int argc, char *argv[]) {
    char *bin_path = argv[1];
    char command[512];
    sprintf(command, 
            "tail -n +2 %s | sed -e 's/.*: //' | tr -d '\\n' | sed -e 's/\\(..\\)/\\1 /g' | xxd -r -p > temp.bin", 
            bin_path);
    system(command);    

    int loaded = load_bin_to_mem("temp.bin");
    if (loaded < 0) return EXIT_FAILURE;
    printf("load success %d bytes to rom\n", loaded);

    // pc = 1;

    // if (pc == 1){
    //     uint32_t inst = ROM[pc];
    //     printf("inst: %0x\n", inst);

    //     for(int i = 31 ; i >= 0; i--) {
    //         printf("%d", extract_bits(i, i, inst));
    //     }
    //     printf("\n");

    //     uint32_t opcode = extract_bits(0, 6, inst);
    //     uint32_t rd = extract_bits(7, 11, inst);
    //     uint32_t funct3 = extract_bits(12, 14, inst);
    //     uint32_t rs1 = extract_bits(15, 19, inst);
    //     uint32_t rs2 = extract_bits(20, 24, inst);
    //     uint32_t funct7 = extract_bits(25, 31, inst);

    //     printf("opcode: %0x\n", opcode);
    //     printf("rd: %0x\n", rd);
    //     printf("funct3: %0x\n", funct3);
    //     printf("rs1: %0x\n", rs1);
    //     printf("rs2: %0x\n", rs2);
    //     printf("funct7: %0x\n", funct7);
    // }

    pc = 0;

    for (int i = 0; i < 6000; i++) {
        inst_cycle();
    }

    printf("pc: %0x\n", pc);
    printf("inst: %0x\n", ( ((uint8_t)ROM[pc])        ) |
                ( ((uint8_t)ROM[pc + 1]) << 8  ) |
                ( ((uint8_t)ROM[pc + 2]) << 16 ) |
                ( ((uint8_t)ROM[pc + 3]) << 24 ));
    printf("GPR[0]: %u\n", GPR[0]);
    printf("GPR[1]: %u\n", GPR[1]);
    printf("GPR[2]: %u\n", GPR[2]);
    printf("GPR[3]: %u\n", GPR[3]);
    printf("GPR[4]: %u\n", GPR[4]);
    printf("GPR[5]: %u\n", GPR[5]);
    printf("GPR[6]: %u\n", GPR[6]);
    printf("GPR[7]: %u\n", GPR[7]);
    printf("GPR[8]: %u\n", GPR[8]);
    printf("GPR[9]: %u\n", GPR[9]);
    printf("GPR[10]: %u\n", GPR[10]);
    printf("GPR[11]: %u\n", GPR[11]);
    printf("GPR[12]: %u\n", GPR[12]);
    printf("GPR[13]: %u\n", GPR[13]);
    printf("GPR[14]: %u\n", GPR[14]);
    printf("GPR[15]: %u\n", GPR[15]);

    printf("ROM[0] %0x\n", ROM[0]);
    printf("ROM[1] %0x\n", ROM[1]);



    return 0;
}