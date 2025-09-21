#include <stdlib.h>
#include <stdio.h>
#include <nvboard.h>
#include "Vtop.h"
#include "verilated.h"
#include <random>

void nvboard_bind_all_pins(Vtop* top);

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  // 初始化Verilator环境

    nvboard_init();

    Vtop* top = new Vtop;  // 实例化设计模块
    nvboard_bind_all_pins(top);


    while (1){
        nvboard_update();

        top->a = rand() % 2;
        top->b = rand() % 2;

        top->eval();

        printf("a: %d, b: %d, f: %d\n", top->a, top->b, top->f);

        // nvboard_led_set(0, top->f);
        nvboard_update();

        usleep(100000);  // 延时100ms
    }

    
    top->final();  // 清理资源
    nvboard_quit();
    delete top;
    
    return 0;
}

void nvboard_bind_all_pins(Vtop* top) {
    nvboard_bind_pin(&top->a, 1, SW0);
    nvboard_bind_pin(&top->b, 1, SW1);
    nvboard_bind_pin(&top->f, 1, LD0);
}