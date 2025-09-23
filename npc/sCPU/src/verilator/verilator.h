#ifndef VERILATOR_H
#define VERILATOR_H

#include "VsCPU.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 

#endif

extern VsCPU * sCPU;
extern VerilatedContext* contextp;
extern VerilatedVcdC* tfp;

void nvboard_bind_all_pins(VsCPU* sCPU);
void step_and_dump_wave();
void sim_init();
void sim_exit();
void printf_num_binary(int num);
extern "C" void nemu_trap(int ret);