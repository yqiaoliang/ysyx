

#include "mem.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h> 
#include <stdint.h>
#include <sys/time.h>




uint8_t RAM[MEM_LEN] = {};
int img_size;

static int boot_time = 0;
uint8_t* guest_to_host(uint32_t paddr) {return RAM + paddr - MEM_BASE;}


static uint64_t get_time_internal() {
  struct timeval now;
  gettimeofday(&now, NULL);
  uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
  return us;
}

uint64_t get_time() {
  if (boot_time == 0) boot_time = get_time_internal();
  uint64_t now = get_time_internal();
  return now - boot_time;
}



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
    // raddr -= MEM_BASE;
    // printf("len %d \n", len);
    // printf("raddr %0x\n", raddr);
    // printf("%d\n", (raddr + len >= MEM_LEN));
    if(((uint32_t)raddr - MEM_BASE + len >= MEM_LEN) || ((uint32_t)raddr < 0)) { 
        if (raddr == 0xa00003f8) return get_time();

        return 0;
        // return mmio_read(raddr,len);
        // else return 0;
    }


    return  host_read(guest_to_host(raddr), len);

}

extern "C" void pmem_write(int waddr, int wdata, uint8_t len) {
    // int write_len = len - '0';
    // waddr -= MEM_BASE;
    if(((uint32_t)waddr - MEM_BASE + len >= MEM_LEN) || ((uint32_t)waddr < 0)) {
        // mmio_write(waddr, len, wdata);
        if (wdata < MEM_LEN && (waddr >= 0)) {
            switch (len) {
                case 1 : putchar((uint8_t) wdata);
                case 2 : putchar((uint16_t) wdata);
                case 4 : putchar((uint32_t) wdata);
            }
        }
        
        return;
    }
    waddr -= MEM_BASE;
    // host_write(guest_to_host(waddr), wdata, len);
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

