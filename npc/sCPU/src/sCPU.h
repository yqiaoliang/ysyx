#include <stdlib.h>
#include <stdio.h>
#include <nvboard.h>
#include "VsCPU.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 
#include <random>

// #include "cpu/cpu_exec.h"
#include "memory/mem.h"
#include "verilator/verilator.h"
#include "difftest/difftest.h"


// extern char * ref_so_file
extern VerilatedContext* contextp;
extern VerilatedVcdC* tfp;

extern uint8_t RAM[MEM_LEN];

extern VsCPU * sCPU;
extern int process_end;
extern int runtime;


extern int img_size;




extern "C" void nemu_trap(int ret);



void nvboard_bind_all_pins(VsCPU* sCPU);
void step_and_dump_wave();
void sim_init();
void sim_exit();
void printf_num_binary(int num);
extern "C" void nemu_trap(int ret);


void printf_gpr_files(VsCPU * sCPU);


void sdb_mainloop();
void run_batch_mode();
void init_map();
void init_timer();