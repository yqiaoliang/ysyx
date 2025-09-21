#include <stdlib.h>
#include <stdio.h>
#include <nvboard.h>
#include "Vshift_rand.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 
#include <random>
#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vshift_rand  * shift_rand;

void nvboard_bind_all_pins(Vshift_rand* shift_rand);

int signed_value(unsigned int val, int bits) {
  if (val & (1 << (bits - 1))) {
    return val - (1 << bits);
  }
  return val;
}


void step_and_dump_wave(){
    shift_rand->clk = 0;
    shift_rand->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());

    shift_rand->clk = 1;
    shift_rand->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}


void sim_init(){
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    shift_rand = new Vshift_rand;
    contextp->traceEverOn(true);
    shift_rand->trace(tfp, 0);
    tfp->open("dump.vcd");
}

void sim_exit(){
    step_and_dump_wave();
    tfp->close();
    delete shift_rand;
    delete contextp;
}

void printf_num_binary(char* name, int num){
    printf("%s", name);
    for (int i = 7; i >= 0; i--){
        printf("%d", ((uint8_t(num) >> i) & 1 ));
    }
    printf("\n");
}


int main(){
    sim_init();
    nvboard_init();
    nvboard_bind_all_pins(shift_rand);

    shift_rand->rst = 1;
    step_and_dump_wave();


    shift_rand->rst = 0;
    for (int i = 0; i < 500; i++){
        step_and_dump_wave();
        printf_num_binary("data_out", shift_rand->data_out);
        printf("data_out: %0x\n", (int8_t)shift_rand->data_out);
    }

    while (1){
        step_and_dump_wave();
        nvboard_update();
        usleep(1000000);
    }

    sim_exit();
    nvboard_quit();
    return 0;
}

void nvboard_bind_all_pins(Vshift_rand* shift_rand) {
    nvboard_bind_pin(&shift_rand->seg_out_0, 7, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G);
    nvboard_bind_pin(&shift_rand->seg_out_1, 7, SEG1A, SEG1B, SEG1C, SEG1D, SEG1E, SEG1F, SEG1G);
}
