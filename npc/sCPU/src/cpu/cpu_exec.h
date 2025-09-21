
#include "VsCPU.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 


extern VsCPU * sCPU;
extern int process_end;
extern int runtime;
void cpu_exec(int n)