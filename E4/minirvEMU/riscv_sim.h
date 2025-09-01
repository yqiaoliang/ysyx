#include <stdint.h>
#include <stdio.h>

#define MEM_SIZE (1 << 22)  

typedef struct{
    int32_t pc;
    int32_t GPR[32];
}CpuState;

typedef struct{
    uint8_t ram[MEM_SIZE];
    uint8_t rom[MEM_SIZE];
}Memory;

typedef struct{
    uint32_t raw;
    uint8_t opcode;
    uint8_t funct3;
    uint8_t funct7;
    uint8_t rd;
    uint8_t rs1;
    uint8_t rs2;
}Instruction;

void cpu_init(CpuState * cpu);
void mem_init(Memory * mem);
uint32_t get_inst(Memory *mem, uint32_t addr);
int load_bin_to_mem(Memory *mem, const char *bin_path);
int32_t mem_read(Memory *mem, uint32_t addr, int32_t size);
int32_t mem_write(Memory *mem, uint32_t addr, int32_t size, int32_t data);
int sign_extend(int32_t value, int bits);
uint32_t extract_bits_unsigned(int left, int right, uint32_t value);
void decode_instruction(Instruction *inst, uint32_t raw);
void execute_instruction(CpuState *cpu, Memory *mem, Instruction *inst);
void inst_cycle(CpuState *cpu, Memory *mem, Instruction *inst);