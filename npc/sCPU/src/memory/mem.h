#ifndef MEM_H
#define MEM_H


#include <stdint.h> 
#include <stddef.h>
#include <cstdio>



#define MEM_LEN ((1 << 25) -1)
#define MEM_BASE 0x80000000
#define paddr_t uint32_t
#define word_t uint32_t

extern uint8_t RAM[MEM_LEN];
extern int img_size;


int load_bin_to_ram_ex(const char* bin_path, uint8_t* ram, size_t ram_max_len, int little_endian);
extern "C" int pmem_read(int raddr, uint8_t len);
extern "C" void pmem_write(int waddr, int wdata, uint8_t len);

uint32_t mmio_read(paddr_t addr, int len);
void mmio_write(paddr_t addr, int len, word_t data);


static inline int host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
  }
  return 1;
}

static inline void host_write(void *addr, int len, int data) {

    //     waddr -= MEM_BASE;
    // if((waddr + len >= MEM_LEN) || (waddr < 0)) {
    //     return ;
    // }
    // switch (len) {
    //     case 1 : RAM[waddr] = (uint8_t)wdata; break;
    //     case 2 : RAM[waddr+1] = (uint8_t)(wdata >> 8); RAM[waddr] = (uint8_t)wdata; break;
    //     case 4 : {
    //         for (int i = 0; i < 4; i++) {
    //             RAM[waddr + i] = (uint8_t) (wdata >> i * 8);
    //         }
    //         break;
    //     }
    // }
  switch (len) {
    case 1: *(uint8_t *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
  }
    // switch(len){
    //     case 1: *(uint8_t *)addr = data; return;
    //     case 2: *(uint8_t *)addr = data; *(uint8_t *)(addr+1) = (data > 8); return;
    //     case 4: for (int i = 0; i < 4; i++){
    //         *(uint8_t *) (addr+i) = (uint8_t) (data >> i * 8);
    //         return;
    //     }
    // }
}

#endif