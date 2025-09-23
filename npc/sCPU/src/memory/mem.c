

#include "mem.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h> 
#include <stdint.h>




uint8_t RAM[MEM_LEN] = {};
int img_size;


int load_bin_to_ram_ex(const char* bin_path, uint8_t* ram, size_t ram_max_len, int little_endian) {
    FILE* bin_file = fopen(bin_path, "rb");
    if (bin_file == NULL) {
        perror("Failed to open .bin file");
        return -1;
    }

    uint8_t* temp_buf = (uint8_t*)malloc(ram_max_len);
    if (temp_buf == NULL) {
        perror("Failed to allocate temp buffer");
        fclose(bin_file);
        return -1;
    }
    memset(temp_buf, 0, ram_max_len);

    size_t read_bytes = fread(temp_buf, 1, ram_max_len, bin_file);
    if (ferror(bin_file) != 0) {
        perror("Failed to read .bin file");
        free(temp_buf);
        fclose(bin_file);
        return -1;
    }
    fclose(bin_file);

    if (little_endian) {
        // 小端模式：直接复制（每个4字节组内部不翻转）
        memcpy(ram, temp_buf, read_bytes);
    } else {
        // 大端模式：按4字节组翻转
        for (size_t i = 0; i < read_bytes; i += 4) {
            size_t group_bytes = (i + 4 <= read_bytes) ? 4 : (read_bytes - i);
            for (size_t j = 0; j < group_bytes; j++) {
                ram[i + (group_bytes - 1 - j)] = temp_buf[i + j];
            }
        }
    }

    free(temp_buf);

    printf("Successfully loaded .bin file: %s\n", bin_path);
    printf("Byte order: %s\n", little_endian ? "little-endian" : "big-endian");
    printf("Loaded bytes: %zu (0x%zx) / RAM max len: %zu (0x%zx)\n",
           read_bytes, read_bytes, ram_max_len, ram_max_len);

    if (read_bytes == ram_max_len) {
        fprintf(stderr, "Warning: .bin file may be larger than RAM, data truncated!\n");
    }

    return read_bytes;
}


extern "C" int pmem_read(int raddr, uint8_t len) {
    // int read_byte = len - '0';
    raddr -= MEM_BASE;
    // printf("len %d \n", len);
    // printf("raddr %d\n", raddr);
    // printf("%d\n", (raddr + len >= MEM_LEN));

    if(((uint64_t)raddr + len >= MEM_LEN) || (raddr < 0)) {
        // printf("mem out of bound, addr: 0x%0x\n", raddr);
        return 0;
    }
    switch (len) {
        case 1 : return RAM[raddr]; break;
        case 2 : return RAM[raddr] | RAM[raddr+1] << 8; break;
        case 4 : return RAM[raddr] | RAM[raddr+1] << 8 | RAM[raddr+2] << 16 | RAM[raddr+3] << 24; break;
    }

    return 0;
}

extern "C" void pmem_write(int waddr, int wdata, uint8_t len) {
    // int write_len = len - '0';
    waddr -= MEM_BASE;
    if((waddr + len >= MEM_LEN) || (waddr < 0)) {
        return ;
    }
    switch (len) {
        case 1 : RAM[waddr] = (uint8_t)wdata; break;
        case 2 : RAM[waddr+1] = (uint8_t)(wdata >> 8); RAM[waddr] = (uint8_t)wdata; break;
        case 4 : {
            for (int i = 0; i < 4; i++) {
                RAM[waddr + i] = (uint8_t) (wdata >> i * 8);
            }
            break;
        }
    }
}

