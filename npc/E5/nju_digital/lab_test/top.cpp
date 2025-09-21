#include <nvboard.h>
#include "Vpriority_encoder_83.h"  // Verilator 生成的模块头文件

static Vpriority_encoder_83 top;  // 实例化 Verilog 模块

void nvboard_bind_all_pins() {
    // 绑定拨码开关 SW[8:0]
    nvboard_bind_pin(top.SW, 9, SW8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
    // 绑定 LED[4:0]
    nvboard_bind_pin(top.LED, 5, LD4, LD3, LD2, LD1, LD0);
    // 绑定七段数码管 HEX0[6:0]
    nvboard_bind_pin(top.HEX0, 7, HEX0, HEX0, HEX0, HEX0, HEX0, HEX0, HEX0);
}

int main() {
    nvboard_bind_all_pins();  // 绑定硬件引脚
    nvboard_init();           // 初始化 nvboard 图形界面

    while (1) {
        top.eval();     // 评估 Verilog 模块逻辑
        nvboard_update(); // 更新 nvboard 图形界面显示
    }

    nvboard_quit();  // 退出 nvboard（实际因 while(1) 一般不会执行到）
    return 0;
}