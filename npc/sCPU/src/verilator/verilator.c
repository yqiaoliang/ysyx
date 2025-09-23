#include "verilator.h"
#include "../cpu/cpu_exec.h"


VerilatedContext* contextp;
VerilatedVcdC* tfp;

void nvboard_bind_all_pins(VsCPU* sCPU);

void step_and_dump_wave(){
    sCPU->clk = 1;
    sCPU->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());

    sCPU->clk = 0;
    sCPU->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());

    // sCPU->clk = 0;
    // sCPU->eval();
    // contextp->timeInc(1);
    // tfp->dump(contextp->time());
}

void sim_init(){
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    sCPU = new VsCPU;
    contextp->traceEverOn(true);
    sCPU->trace(tfp, 0);
    tfp->open("/home/yqiaoliang/Desktop/digital/ysyx/npc/sCPU/dump.vcd");
}

void sim_exit(){
    step_and_dump_wave();
    tfp->close();
    delete sCPU;
    delete contextp;
    // delete[] RAM;
}

void printf_num_binary(int num){
    printf("data_in: ");
    for (int i = 7; i >= 0; i--){
        printf("%d", ((uint8_t(num) >> i) & 1 ));
    }
    printf("\n");
}

extern "C" void nemu_trap(int ret) {
    // printf("process finished at pc: 0x%0x", pc);
    // process_return = ret;
    process_end = 1;
}