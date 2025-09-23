#include "cpu_exec.h"
#include "../verilator/verilator.h"
#include "../difftest/difftest.h"

#define MAX_RUNTIME 1000000

VsCPU * sCPU;
int process_end;
int runtime = 0;

void exec_once();

void cpu_exec(int n) {
    if (n < 0) {
        while (!process_end) exec_once();
    }

    else {
        for (int i = 0; i < n; i++){
            if (!process_end) exec_once();
        }
    }
}

void exec_once() {
    if (runtime > MAX_RUNTIME) {
        process_end = 1;
        return;
    }
    
    // printf("start\n");
    step_and_dump_wave();
    difftest_step();
    // printf("finish\n");
    if (sCPU->unknow_inst) {
        printf("unknow_inst at pc, inst: %0x: 0x%0x \n", sCPU->pc_o, sCPU->out_inst);
        process_end = 1;
    }
    runtime++;
}