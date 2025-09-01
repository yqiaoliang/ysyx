#include <stdint.h>
#include <stdio.h>

#define MEM_SIZE (1 << 30)  

typedef struct{
    int32_t pc;
    int32_t GPR[32];
}CpuState_my_E4;

typedef struct{
    uint8_t ram[MEM_SIZE];
    uint8_t rom[MEM_SIZE];
}Memory_my_E4;

typedef struct{
    uint32_t color_buf[32 * 32];
    int32_t color_write_index;
}Color_my_E4;

typedef struct{
    uint32_t raw;
    uint8_t opcode;
    uint8_t funct3;
    uint8_t funct7;
    uint8_t rd;
    uint8_t rs1;
    uint8_t rs2;
}Instruction_my_E4;

void draw(Color_my_E4 *color);
void cpu_init_my_E4(CpuState_my_E4 * cpu);
void mem_init_my_E4(Memory_my_E4 * mem);
void color_init_my_E4(Color_my_E4 *color);
uint32_t get_inst_my_E4(Memory_my_E4 *mem, uint32_t addr);
int load_bin_to_mem_my_E4(Memory_my_E4 *mem, const char *bin_path);
int32_t mem_read_my_E4(Memory_my_E4 *mem, uint32_t addr, int32_t size);
int32_t mem_write_my_E4(Memory_my_E4 *mem, uint32_t addr, int32_t size, int32_t data);
int sign_extend_my_E4(int32_t value, int bits);
uint32_t extract_bits_unsigned_my_E4(int left, int right, uint32_t value);
void decode_instruction_my_E4(Instruction_my_E4 *inst, uint32_t raw);
void execute_instruction_my_E4(CpuState_my_E4 *cpu, Memory_my_E4 *mem, Instruction_my_E4 *inst, Color_my_E4 *color);
void inst_cycle_my_E4(CpuState_my_E4 *cpu, Memory_my_E4 *mem, Instruction_my_E4 *inst, Color_my_E4 *color);
