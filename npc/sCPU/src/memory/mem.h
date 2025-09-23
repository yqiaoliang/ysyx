#ifndef MEM_H
#define MEM_H


#include <stdint.h> 
#include <stddef.h> 

#endif

#define MEM_LEN ((1 << 25) -1)
#define MEM_BASE 0x80000000

extern uint8_t RAM[MEM_LEN];
extern int img_size;


int load_bin_to_ram_ex(const char* bin_path, uint8_t* ram, size_t ram_max_len, int little_endian);
extern "C" int pmem_read(int raddr, uint8_t len);
extern "C" void pmem_write(int waddr, int wdata, uint8_t len);
