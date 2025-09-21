#include <stdlib.h>
#include <stdio.h>
#include <nvboard.h>
#include "Vencode8x3.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 
#include <random>
// #include <nvboard.h>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vencode8x3 * encode8x3;


void nvboard_bind_all_pins(Vencode8x3* encode8x3);

void step_and_dump_wave(){
  encode8x3->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}

void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  encode8x3 = new Vencode8x3;
  contextp->traceEverOn(true);
  encode8x3->trace(tfp, 0);
  tfp->open("dump.vcd");
}

void sim_exit(){
    step_and_dump_wave();
    tfp->close();
    delete encode8x3;
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
    nvboard_bind_all_pins(encode8x3);

    encode8x3->en = 0;
    encode8x3->data_in = 0; step_and_dump_wave();


    encode8x3->en = 1; 
    for (int i = 0; i < (1 << 8) - 1; i++){
        encode8x3->data_in = i;
        step_and_dump_wave();

        printf_num_binary(i);
        printf("is_zero: %d\n", encode8x3->is_zero);
        printf("data_out: %d\n", encode8x3->data_out);
        printf("\n");
    }

    while (1){
        encode8x3->eval();
        nvboard_update();
    }

    sim_exit();
    nvboard_quit();
    return 0;
}

void nvboard_bind_all_pins(Vencode8x3* encode8x3) {
    nvboard_bind_pin(&encode8x3->data_in, 8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
    nvboard_bind_pin(&encode8x3->en, 1, SW9);
    nvboard_bind_pin(&encode8x3->is_zero, 1, LD0);
    nvboard_bind_pin(&encode8x3->data_out, 3, LD3, LD2, LD1);
    nvboard_bind_pin(&encode8x3->seg, 7, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G);
}
