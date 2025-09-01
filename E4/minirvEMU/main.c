#include "riscv_sim.h"
#include <stdlib.h>


int main (int argc, char * argv[]){
    Memory *mem = malloc(sizeof(Memory));
    CpuState *cpu = malloc(sizeof(CpuState)); 
    Instruction *inst = malloc(sizeof(Instruction));

    cpu_init(cpu);
    mem_init(mem);

    char *bin_path = argv[1];
    char command[512];
    sprintf(command, 
            "tail -n +2 %s | sed -e 's/.*: //' | tr -d '\\n' | sed -e 's/\\(..\\)/\\1 /g' | xxd -r -p > temp.bin", 
            bin_path);
    system(command);    

    int loaded = load_bin_to_mem(mem , "temp.bin");
    if (loaded < 0) return EXIT_FAILURE;
    printf("load success %d bytes to rom\n", loaded);

    for (int i = 0; i < 6000; i++){
        printf("pc: %0x \n", cpu->pc);
        inst_cycle(cpu, mem, inst);
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


    free(mem);
    free(cpu);
    free(inst);
    return 0;
}