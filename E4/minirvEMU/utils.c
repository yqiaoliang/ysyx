#include "riscv_sim.h"
#include <string.h>

void cpu_init_my_E4(CpuState_my_E4 * cpu) {
    cpu->pc = 0;
    memset(cpu->GPR, 0, sizeof(cpu->GPR));
}

void color_init_my_E4(Color_my_E4 *color){
    memset(color->color_buf, 0, sizeof(color->color_buf));
    color->color_write_index = 0;
}

int sign_extend_my_E4(int32_t value, int bits) {
    // int32_t mask = 1 << (bits - 1);
    // return (value ^ mask) - mask;
    if (value & (1 << (bits -1))){
        int32_t mask = ~((1 << bits) - 1);
        return value | mask;
    }
    return value;
}

uint32_t extract_bits_unsigned_my_E4(int left, int right, uint32_t value) {
    uint32_t width = right - left + 1;
    return (value >> left) & ((1 << width) - 1);
}

void decode_instruction_my_E4(Instruction_my_E4 *inst, uint32_t raw) {
    inst->raw = raw;
    inst->opcode = extract_bits_unsigned_my_E4(0, 6, raw);
    inst->funct3 = extract_bits_unsigned_my_E4(12, 14, raw);
    inst->funct7 = extract_bits_unsigned_my_E4(25, 31, raw);
    inst->rd = extract_bits_unsigned_my_E4(7, 11, raw);
    inst->rs1 = extract_bits_unsigned_my_E4(15, 19, raw);
    inst->rs2 = extract_bits_unsigned_my_E4(20, 24, raw);
}

