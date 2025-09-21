#include <nvboard.h>
#include "Vlight.h"

static Vlight *light = new Vlight;

void nvboard_bind_all_pins(Vlight* light) {
    nvboard_bind_pin(&light->clk, 1, PS2_CLK);
    // nvboard_bind_pin(&light->rst, 1, RST);
    nvboard_bind_pin(&light->led, 16,  LD15, LD14, LD13, LD12, LD11, LD10, LD9, LD8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
}

void single_cycle() {
  light->clk = 0; light->eval();
  light->clk = 1; light->eval();
}


void reset(int n) {
  light->rst = 1;
  while (n -- > 0) single_cycle();
  light->rst = 0;
}

int main(){
    nvboard_bind_all_pins(light);
    nvboard_init();

    reset(10);

    while(1) {
        single_cycle();
        nvboard_update();
        // usleep(10000); 
    }
}


