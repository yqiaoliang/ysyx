#include <stdlib.h>
#include <stdio.h>
#include <nvboard.h>
#include "Valu.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 
#include <random>
#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Valu  * alu;

void nvboard_bind_all_pins(Valu* alu);

int signed_value(unsigned int val, int bits) {
  if (val & (1 << (bits - 1))) {
    return val - (1 << bits);
  }
  return val;
}


void step_and_dump_wave(){
    alu->clk = 0;
    alu->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());

    alu->clk = 1;
    alu->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}


void sim_init(){
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    alu = new Valu;
    contextp->traceEverOn(true);
    alu->trace(tfp, 0);
    tfp->open("dump.vcd");
}

void sim_exit(){
    step_and_dump_wave();
    tfp->close();
    delete alu;
    delete contextp;
}

void printf_num_binary(char* name, int num){
    printf(name);
    for (int i = 7; i >= 0; i--){
        printf("%d", ((uint8_t(num) >> i) & 1 ));
    }
    printf("\n");
}


int main(){
    sim_init();
    nvboard_init();
    // nvboard_bind_all_pins(alu);

    alu->rst = 1;
    alu->op = 0;  alu->A = 0; alu->B = 0; step_and_dump_wave();


    alu->rst = 0;
    alu->clk = 0;
    for (int i = 0; i < 8; i++){
        alu-> op = i;
        for (int count = 0; count < 10; count++){
            alu->A = rand()%(1<<4) - 8;
            alu->B = rand()%(1<<4) - 8;
            step_and_dump_wave();

            printf("op: %d\n", alu->op);
            printf("A: %d\n", (int8_t)alu->A);
            printf("B: %d\n", (int8_t)alu->B);
            printf("data_out: %d\n", (int8_t)signed_value(alu->data_out, 4));
            // printf_num_binary("A: ", alu->A);
            // printf_num_binary("B: ", alu->B);
            // printf_num_binary("data_out: ", alu->data_out);
            printf("is_zero: %d\n", alu->is_zero);
            printf("is_overflow: %d\n", alu->is_overflow);
            printf("is_carry: %d\n", alu->is_carry);
            printf("out: %d\n", alu->out);
            printf("\n");
        }
    }

    // while (1){
    //     encode8x3->eval();
    //     nvboard_update();
    // }

    sim_exit();
    nvboard_quit();
    return 0;
}
