#include <stdio.h>
#include <stdint.h> 
#include <stdlib.h>
#include <string.h>

uint8_t PC = 0;
uint8_t R[4];
uint8_t M[16] = {0x90, 0xa1, 0xb1, 0x16, 0x2b, 0xca, 0x40};

char * chars_slice(int left, int right, char * str){
    char * slice = malloc(right - left + 2);
    strncpy(slice, str + left, right - left + 1);
    slice[right - left + 1] = '\0';
    return slice;
}

void inst_cycle(){
    int inst = M[PC];
    char inst_binary[9];
    for (int i = 0; i < 8; i++) {
        inst_binary[7-i] = inst & (1 << i) ? '1' : '0';
    }
    inst_binary[8] = '\0';
    printf("inst: %s\n", inst_binary);
    char *endptr;

    

    uint8_t operator = strtol(chars_slice(0, 1, inst_binary), &endptr ,2);
    uint8_t rd = strtol(chars_slice(2, 3, inst_binary), &endptr ,2);
    uint8_t rs1 = strtol(chars_slice(4, 5, inst_binary), &endptr ,2);
    uint8_t rs2 = strtol(chars_slice(6, 7, inst_binary), &endptr ,2);
    uint8_t imm = strtol(chars_slice(4, 7, inst_binary), &endptr ,2);
    uint8_t addr = strtol(chars_slice(2, 5, inst_binary), &endptr ,2);

    printf("operator %d \n", operator);
    // printf("rd %d \n", rd);
    // printf("rs1 %d \n", rs1);
    // printf("rs2 %d \n", rs2);
    // printf("imm %d \n", imm);
    // printf("addr %d \n", addr);

    switch(operator){
        case 0: {
            uint8_t result = R[rs1] + R[rs2];
            R[rd] = result;
            PC++;
            break;
        }
        case 2: {
            R[rd] = imm;
            PC++;
            break;
        }
        case 3: {
            if (R[0] != R[rs2])PC = addr;
            else PC++;
            break;
        }
        default: {
                printf("R[0]: %d\n", R[0]);
                printf("R[1]: %d\n", R[1]);
                printf("R[2]: %d\n", R[2]);
                printf("R[3]: %d\n", R[3]);
                PC = 15;
            break;
        }
    }
}

int main(uint8_t argc, char *argv[]){
    uint8_t num = (uint8_t)atoi(argv[1]);
    printf("num: %d \n", num);
    R[0] = num;
    for (int i = 0 ; i < 100; i++){
        printf("PC: %d\n", PC);
        inst_cycle();
        printf("\n");

        printf("R[0]: %d\n", R[0]);
        printf("R[1]: %d\n", R[1]);
        printf("R[2]: %d\n", R[2]);
        printf("R[3]: %d\n", R[3]);

        if (PC == 15) break;
    }

    return 0;
}