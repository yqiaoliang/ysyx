#include <stdlib.h>
#include <iostream>
#include "MyDesign.h"
#include "verilated.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  // 初始化Verilator环境
    
    MyDesign* top = new MyDesign;  // 实例化设计模块
    
    // 测试所有输入组合
    for (int i = 0; i < 4; i++) {
        top->a = i & 1;     // a = LSB
        top->b = (i >> 1);  // b = MSB
        
        top->eval();  // 仿真计算
        
        // 打印结果 
        std::cout << "a = " << (int)top->a
                  << ", b = " << (int)top->b
                  << ", f = " << (int)top->f
                  << std::endl;
    }
    
    top->final();  // 清理资源
    delete top;
    
    return 0;
}