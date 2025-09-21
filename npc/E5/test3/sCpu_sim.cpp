#include <stdlib.h>
#include <stdio.h>
#include <nvboard.h>
#include "VsCpu.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 
#include <random>
// #include <nvboard.h>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VsCpu * sCpu;


void nvboard_bind_all_pins(VsCpu* sCpu);

void step_and_dump_wave(){
    sCpu->clk = 0;
    sCpu->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());

    sCpu->clk = 1;
    sCpu->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void sim_init(){
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    sCpu = new VsCpu;
    contextp->traceEverOn(true);
    sCpu->trace(tfp, 0);
    tfp->open("dump.vcd");
}

void sim_exit(){
    step_and_dump_wave();
    tfp->close();
    delete sCpu;
    delete contextp;
}

void printf_num_binary(int num){
    printf("data_in: ");
    for (int i = 7; i >= 0; i--){
        printf("%d", ((uint8_t(num) >> i) & 1 ));
    }
    printf("\n");
}

int main(){
    sim_init();
    nvboard_init();
    nvboard_bind_all_pins(sCpu);

    sCpu->rst = 1;
    step_and_dump_wave();


    sCpu->rst = 0; 
    for (int i = 0; i < 60; i++){
        step_and_dump_wave();

        printf("data_out: %d", sCpu->data_out);
        printf("\n");
    }


    sCpu->rst = 1;
    step_and_dump_wave();
    sCpu->rst = 0; 
    printf("data_out: %d", sCpu->data_out);
    printf("\n");
    while (1){
        sCpu->eval();
        // step_and_dump_wave();
        nvboard_update();
        // usleep(10000);
    }

    sim_exit();
    nvboard_quit();
    return 0;
}


void nvboard_bind_all_pins(VsCpu* sCpu) {
    nvboard_bind_pin(&sCpu->clk, 1, SW0);
    nvboard_bind_pin(&sCpu->seg_out_0, 7, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G);
    nvboard_bind_pin(&sCpu->seg_out_1, 7, SEG1A, SEG1B, SEG1C, SEG1D, SEG1E, SEG1F, SEG1G);
}