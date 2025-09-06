#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <am.h>
#include <klib-macros.h>
uint32_t PC = 0;
uint32_t R[16];
#define MEM_SIZE 1024*1024*1024
#define EBREAK 0xe6000001
#define HALT_POS 0xdb8
uint8_t * colorpix=NULL;
uint8_t M[MEM_SIZE]={
0x01,0x40,0x05,0x13, 
0x01,0x00,0x00,0xe7,
0x00,0xc0,0x00,0xe7,
0x00,0xc0,0x00,0x67,
0x00,0xa5,0x05,0x13,
0x00,0x00,0x80,0x67
};
int cnt=0;
void draw() {
  int width = 256, height = 256;
 static uint32_t buf[256]; // 一行的像素缓存
  for (int y = 0; y < height; y++) {
  for (int i = 0; i < width; i++) buf[i] = *(uint32_t*)(colorpix+y*width*4+i*4);
    io_write(AM_GPU_FBDRAW, 0, y, buf, width, 1, false);
  }
  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true); // 刷新
}


uint32_t inst(){
    uint32_t _inst = M[PC] | (M[PC+1]<<8) | (M[PC+2]<<16) | (M[PC+3]<<24); // 小端
    printf("inst: %x\n", _inst);
    PC+=4;
    return _inst;
}

void decode(uint32_t inst){
    if(inst== EBREAK){
        while(1){
            draw();
        }
    }
    cnt++;
    printf("PC:%x\n", PC);
    printf("inst: %x\n", inst);
    uint32_t opcode = inst &0x7f;
    uint32_t rd=(inst>>7)& 0x1f;
    uint32_t imm4_0=rd;
    uint32_t funct3=(inst>>12) & 0x7;
    uint32_t rs1=(inst>>15)& 0x1f;
    uint32_t rs2=(inst>>20)& 0x1f;
    uint32_t imm11_0=(inst>>20)& 0xfff;
    uint32_t simm11_0 = ((int32_t)(imm11_0 << 20)) >> 20; // Sign-extend to 32-bit
    uint32_t imm11_5=(inst>>25 )& 0x7f;
    uint32_t imm31_12=(inst >>12)& 0xfffff;

    switch(opcode){
        
        case 0b0010011:
            if(funct3==0b000){//ADDI
            if(rd) R[rd]=R[rs1]+simm11_0;
                printf("ADDI: R[%x] = R[%x] + %x\n", rd, rs1, simm11_0);
            }
            break;
        case 0b1100111:
            if(funct3==0b000){//JALR
                uint32_t pc=PC;
                PC=(R[rs1]+simm11_0)&(~1);
                printf("PC: %x\n", PC);
                if(rd) R[rd]=pc; 
                printf("JALR: R[%x] = %x\n", rd, PC);
                
            }
            break;
        case 0b0000011:
            if(funct3==0b010){//LW
            if(rd) {
                uint32_t addr = R[rs1] + simm11_0;
                if (addr + 3 >= MEM_SIZE) {
                    fprintf(stderr, "Memory access out of bounds: 0x%x\n", addr);
                    exit(1);
                }
                printf("LW: target--R[%x] = %x\n", rd, R[rd]);
                R[rd]=M[addr]; //最低字节
                printf("LW: M[R[%x]+%x] = %x\n",rs1,simm11_0,M[addr]);
                R[rd]|=M[addr+1]<<8;
                printf("LW: M[R[%x]+%x+1] = %x\n",rs1,simm11_0,M[addr+1]);
                R[rd]|=M[addr+2]<<16;
                printf("LW: M[R[%x]+%x+2] = %x\n",rs1,simm11_0,M[addr+2]);
                R[rd]|=M[addr+3]<<24;
                printf("LW: M[R[%x]+%x+3] = %x\n",rs1,simm11_0,M[addr+3]);

            }
            }
            else if(funct3==0b100){//LBU
                uint32_t addr = R[rs1] + simm11_0;
                if (addr  >= MEM_SIZE) {
                    fprintf(stderr, "Memory access out of bounds: 0x%x\n", addr);
                    exit(1);
                }

                if(rd) R[rd]=(uint32_t)M[addr];
                printf("LBU: R[%x] = %x\n", rd, R[rd]);
            }
            break;
        case 0b0110111: //LUI
            if(rd)  R[rd]=imm31_12<<12;
            printf("LUI: R[%x] = %x\n", rd, R[rd]);
            break;
        case 0b0100011:
            if(funct3==0b010){//SW
                uint32_t imm=(imm11_5<<5)|imm4_0;
                int32_t simm=((int32_t)(imm<<20))>>20;
                uint32_t addr = R[rs1] + simm;
                if (addr+3  >= MEM_SIZE) {
                    fprintf(stderr, "Memory access out of bounds: 0x%x\n", addr);
                    exit(1);
                }
                if(addr>=0x20000000 && addr+3<0x20000000+0x40000){
                    *(uint8_t*)(colorpix+addr-0x20000000)=(R[rs2])&0xff;
                    *(uint8_t*)(colorpix+addr-0x20000000+1)=(R[rs2]>>8)&0xff;
                    *(uint8_t*)(colorpix+addr-0x20000000+2)=(R[rs2]>>16)&0xff;
                    *(uint8_t*)(colorpix+addr-0x20000000+3)=(R[rs2]>>24)&0xff;
                    break;
                }
                printf("SW: target--M[%x] = %x\n", R[rs1]+simm, R[rs2]);
                M[addr]=(R[rs2])&0xff;
                printf("SW: M[%x] = %x\n", addr, M[addr]);
                M[addr+1]=(R[rs2]>>8)&0xff;
                printf("SW: M[%x] = %x\n", addr+1, M[addr+1]);
                M[addr+2]=(R[rs2]>>16)&0xff;
                printf("SW: M[%x] = %x\n", addr+2, M[addr+2]);
                M[addr+3]=(R[rs2]>>24)&0xff;
                printf("SW: M[%x] = %x\n", addr+3, M[addr+3]);

            }
            else if(funct3==0b000){//SB
                uint32_t imm=(imm11_5<<5)|imm4_0;
                int32_t simm=((int32_t)(imm<<20))>>20;
                uint32_t addr = R[rs1] + simm;
                if (addr  >= MEM_SIZE) {
                    fprintf(stderr, "Memory access out of bounds: 0x%x\n", addr);
                    exit(1);
                }
                M[addr]=(R[rs2])&0xff;
                printf("SB: M[%x] = %x\n", addr, M[addr]);
            }
            break;
        case 0b0110011:
            if(funct3==0b000  && imm11_5==0b0000000){//ADD
                if(rd) R[rd]=R[rs1]+R[rs2];
                printf("ADD: R[%x] = R[%x] + R[%x]\n", rd, rs1, rs2);
            }
            break;
        default:
            printf("Unknown opcode: %x\n", opcode);
            break;
    }
}
int main(int argc, char *argv[]){
   ioe_init();

    // 打开文件
    FILE *fp = fopen("vga.bin", "rb");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }
   
    // 读取文件内容到 M 数组
    fread(M, 1, MEM_SIZE, fp);
    fclose(fp);
    M[HALT_POS+ 0] = EBREAK&0xff;
    M[HALT_POS+ 1] = (EBREAK>>8)&0xff;
    M[HALT_POS+ 2] = (EBREAK>>16)&0xff;
    M[HALT_POS+ 3] = (EBREAK>>24)&0xff;

    colorpix = (uint8_t *)malloc(0x40000);

    while(1){
        decode(inst());
        R[0]=0;
    }

}