#include <stdlib.h>
#include <stdio.h>
#include <nvboard.h>
#include "VsCPU.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 
#include <random>

#include "cpu/cpu_exec.h"
#include "memory/mem.h"



extern VerilatedContext* contextp;
extern VerilatedVcdC* tfp;

extern uint8_t RAM[MEM_LEN];

extern VsCPU * sCPU;
extern int process_end;
extern int runtime;


// typedef void (*difftest_memcpy_t)(paddr_t, void*, size_t, bool);
// typedef void (*difftest_regcpy_t)(void*, bool);
// typedef void (*difftest_exec_t)(uint64_t);


extern "C" void nemu_trap(int ret);



void nvboard_bind_all_pins(VsCPU* sCPU);
void step_and_dump_wave();
void sim_init();
void sim_exit();
void printf_num_binary(int num);
extern "C" void nemu_trap(int ret);


void printf_gpr_files(VsCPU * sCPU);


void sdb_mainloop();