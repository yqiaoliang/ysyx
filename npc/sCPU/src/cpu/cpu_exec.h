
#ifndef CPU_EXEC_H
#define CPU_EXEC_H

#include "VsCPU.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 


#endif



extern VsCPU * sCPU;
extern int process_end;
extern int runtime;
void cpu_exec(int n);