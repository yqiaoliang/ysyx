#include "sCPU.h"

int runtime = 0;

void printf_gpr_files(VsCPU * sCPU) {
    printf("runtime %d \n", runtime);
    printf("pc: 0x%0x\n", sCPU->pc_o);
    printf("inst: 0x%0x\n", sCPU->out_inst);
    
    printf("0 zero 0x%0x\n", sCPU->gpr_files[0]);
    printf("1 ra   0x%0x\n", sCPU->gpr_files[1]);
    printf("2 sp   0x%0x\n", sCPU->gpr_files[2]);
    printf("3 gp   0x%0x\n", sCPU->gpr_files[3]);
    printf("4 tp   0x%0x\n", sCPU->gpr_files[4]);
    printf("5 t0   0x%0x\n", sCPU->gpr_files[5]);
    printf("6 t1   0x%0x\n", sCPU->gpr_files[6]);
    printf("7 t2   0x%0x\n", sCPU->gpr_files[7]);
    printf("8 s0/fp 0x%0x\n", sCPU->gpr_files[8]);
    printf("9 s1   0x%0x\n", sCPU->gpr_files[9]);
    printf("10 a0  0x%0x\n", sCPU->gpr_files[10]);
    printf("11 a1  0x%0x\n", sCPU->gpr_files[11]);
    printf("12 a2  0x%0x\n", sCPU->gpr_files[12]);
    printf("13 a3  0x%0x\n", sCPU->gpr_files[13]);
    printf("14 a4  0x%0x\n", sCPU->gpr_files[14]);
    printf("15 a5  0x%0x\n", sCPU->gpr_files[15]);
    // printf("16 a6  0x%0x\n", sCPU->gpr_files[16]);
    // printf("17 a7  0x%0x\n", sCPU->gpr_files[17]);
    // printf("18 s2  0x%0x\n", sCPU->gpr_files[18]);
    // printf("19 s3  0x%0x\n", sCPU->gpr_files[19]);
    // printf("20 s4  0x%0x\n", sCPU->gpr_files[20]);
    // printf("21 s5  0x%0x\n", sCPU->gpr_files[21]);
    // printf("22 s6  0x%0x\n", sCPU->gpr_files[22]);
    // printf("23 s7  0x%0x\n", sCPU->gpr_files[23]);
    // printf("24 s8  0x%0x\n", sCPU->gpr_files[24]);
    // printf("25 s9  0x%0x\n", sCPU->gpr_files[25]);
    // printf("26 s10 0x%0x\n", sCPU->gpr_files[26]);
    // printf("27 s11 0x%0x\n", sCPU->gpr_files[27]);
    // printf("28 t3  0x%0x\n", sCPU->gpr_files[28]);
    // printf("29 t4  0x%0x\n", sCPU->gpr_files[29]);
    // printf("30 t5  0x%0x\n", sCPU->gpr_files[30]);
    // printf("31 t6  0x%0x\n", sCPU->gpr_files[31]);

    printf("\n");

    runtime++;
}