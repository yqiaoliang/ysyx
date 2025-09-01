#include "riscv_sim.h"
#include <stdlib.h>
// #include "gui.h"
// #include <am.h>
// #include <klib-macros.h>

int main (int argc, char * argv[]){
    // ioe_init();
    printf("test0 \n");
    printf("argc %d\n", argc);
    Memory_my_E4 *mem = malloc(sizeof(Memory_my_E4));
    CpuState_my_E4 *cpu = malloc(sizeof(CpuState_my_E4));
    Instruction_my_E4 *inst = malloc(sizeof(Instruction_my_E4));
    Color_my_E4 *color = malloc(sizeof(Color_my_E4));

    printf("argc %d\n", argc);

    printf("test1 \n");

    cpu_init_my_E4(cpu);
    mem_init_my_E4(mem);
    printf("test2 \n");
    color_init_my_E4(color);
    printf("test3 \n");

    char *bin_path = argv[1];
    printf("test4\n");
    char command[512];
    sprintf(command, 
            "tail -n +2 %s | sed -e 's/.*: //' | tr -d '\\n' | sed -e 's/\\(..\\)/\\1 /g' | xxd -r -p > temp.bin", 
            bin_path);
    printf("test5\n");
    system(command);    

    printf("test4\n");

    int loaded = load_bin_to_mem_my_E4(mem , "temp.bin");
    if (loaded < 0) return EXIT_FAILURE;
    printf("load success %d bytes to rom\n", loaded);

    for (int i = 0; i < 6000; i++){
        printf("pc: %0x \n", cpu->pc);
        inst_cycle_my_E4(cpu, mem, inst, color);
        printf("inst: %0x \n", inst->raw);
        printf("opcode: %0x \n", inst->opcode);
        printf("rd: %0d \n", inst->rd);
        // printf("\n");
    

        printf("0 zero: %0x \n", cpu->GPR[0]);
        printf("1 ra: %0x \n", cpu->GPR[1]);
        printf("2 sp: %0x \n", cpu->GPR[2]);
        printf("3 gp: %0x \n", cpu->GPR[3]);
        printf("4 tp: %0x \n", cpu->GPR[4]);
        printf("5 t0: %0x \n", cpu->GPR[5]);
        printf("6 t1: %0x \n", cpu->GPR[6]);
        printf("7 t2: %0x \n", cpu->GPR[7]);
        printf("8 s0/fp: %0x \n", cpu->GPR[8]);
        printf("9 s1: %0x \n", cpu->GPR[9]);
        printf("10 a0: %0x \n", cpu->GPR[10]);
        printf("11 a1: %0x \n", cpu->GPR[11]);
        printf("12 a2: %0x \n", cpu->GPR[12]);
        printf("13 a3: %0x \n", cpu->GPR[13]);
        printf("14 s4: %0x \n", cpu->GPR[14]);
        printf("15 a5: %0x \n", cpu->GPR[15]);
        printf("\n");
    }

    while (1) {
        draw(color);
    }

    free(mem);
    free(cpu);
    free(inst);
    free(color);
    return 0;
}