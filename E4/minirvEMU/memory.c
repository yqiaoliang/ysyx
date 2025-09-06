#include "riscv_sim.h"
#include <string.h>


void mem_init_my_E4(Memory_my_E4 * mem){
    memset(mem->ram, 0, MEM_SIZE);
    memset(mem->rom, 0, MEM_SIZE);
}

int load_bin_to_mem_my_E4(Memory_my_E4 *mem, const char *bin_path) {
    FILE *bin_file = fopen(bin_path, "rb");
    if (!bin_file) {
        fprintf(stderr, "Failed to open file: %s\n", bin_path);
        return -1;
    }

    // 获取文件大小
    fseek(bin_file, 0, SEEK_END);
    long file_size = ftell(bin_file);
    fseek(bin_file, 0, SEEK_SET);
    
    // 检查文件大小
    if (file_size > MEM_SIZE) {
        fprintf(stderr, "File too large (%ld bytes), max size %d bytes\n", 
               file_size, MEM_SIZE);
        fclose(bin_file);
        return -1;
    }
    
    // 读取到ROM
    size_t read_bytes = fread(mem->rom, 1, file_size, bin_file);
    fclose(bin_file);
    
    if (read_bytes != (size_t)file_size) {
        fprintf(stderr, "Read incomplete: expected %ld, got %zu bytes\n", 
               file_size, read_bytes);
        return -1;
    }
    
    // 字节交换：假设二进制文件是大端格式，转换为小端格式
    // 遍历每4字节，交换字节顺序
    for (int i = 0; i < file_size; i += 4) {
        // 确保有足够的字节可供交换
        if (i + 3 < file_size) {
            uint8_t byte0 = mem->rom[i];
            uint8_t byte1 = mem->rom[i+1];
            uint8_t byte2 = mem->rom[i+2];
            uint8_t byte3 = mem->rom[i+3];
            mem->rom[i] = byte3;
            mem->rom[i+1] = byte2;
            mem->rom[i+2] = byte1;
            mem->rom[i+3] = byte0;
        }
    }
    
    // 复制到RAM
    memcpy(mem->ram, mem->rom, read_bytes);
    printf("load bin to mem success\n");
    
    return (int)read_bytes;
}

int32_t mem_read_my_E4(Memory_my_E4 *mem, uint32_t addr, int32_t size) {
    // if (addr + size > mem->mem_size) {
    //     fprintf(stderr, "Memory read out of bounds: addr=0x%08x, size=%zu\n", addr, size);
    //     return 0;
    // }
    printf("addr: %0x \n" ,addr);
    if (addr + size > MEM_SIZE) {
        printf("ERROR: Memory write out of bounds: addr=0x%08x, size=%d\n", addr, size);
        return -1;
    }
    
    int32_t data = 0;
    for (int32_t i = 0; i < size; i++) {
        data |= mem->ram[addr + i] << (i * 8);
    }
    return data;
}

int32_t mem_write_my_E4(Memory_my_E4 *mem, uint32_t addr, int32_t size, int32_t data) {
    // if (addr + size > mem->mem_size) {
    //     fprintf(stderr, "Memory write out of bounds: addr=0x%08x, size=%zu\n", addr, size);
    //     return -1;
    // }
    printf("addr: %0x \n" ,addr);
    if (addr + size > MEM_SIZE) {
        printf("ERROR: Memory write out of bounds: addr=0x%08x, size=%d\n", addr, size);
        return -1;
    }

    for (int32_t i = 0; i < size; i++) {
        mem->ram[addr + i] = (uint8_t)((data >> (i * 8)) & 0xFF);
    }
    return 0;
}

uint32_t get_inst_my_E4(Memory_my_E4 *mem, uint32_t addr) {
    int32_t data = 0;
    for (size_t i = 0; i < 4; i++) {
        data |= mem->ram[addr + i] << (i * 8);
    }
    return data;
}
