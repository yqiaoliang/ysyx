#include "cpu_exec.h"

#define MAX_RUNTIME 10000

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
    printf("pc: 0x%08x\n", sCPU->pc_o);
    step_and_dump_wave();
    runtime++;
}