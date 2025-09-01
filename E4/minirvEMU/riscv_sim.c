#include "riscv_sim.h"

void execute_instruction_my_E4(CpuState_my_E4 *cpu, Memory_my_E4 *mem, Instruction_my_E4 *inst, Color_my_E4 *color) {
    switch (inst->opcode) {
        case 0x37 : {
            // lui
            uint32_t imm = extract_bits_unsigned_my_E4(12, 31, inst->raw) << 12;
            printf("imm: %0x \n", imm);
            if (inst->rd != 0x0) cpu->GPR[inst->rd] = imm;
            cpu->pc += 4;
            break;
        }

        case 0x67 : {
            if (inst->funct3 == 0x0) {
                // JALR
                int32_t offset = sign_extend_my_E4(extract_bits_unsigned_my_E4(20, 31, inst->raw), 12);
                int current_pc_next = cpu->pc + 4;
                cpu->pc = (cpu->GPR[inst->rs1] + offset) & ~1;
                if (inst->rd != 0x0) cpu->GPR[inst->rd] = current_pc_next;
            }
            else cpu->pc += 4;
            break;
        }

        case 0x03 : {
            // lw
            if (inst->funct3 == 0x2) {
                int32_t offset = sign_extend_my_E4(extract_bits_unsigned_my_E4(20, 31, inst->raw), 12);
                printf("rs1: %0x, offset: %0x, mem addr: %0x \n",cpu->GPR[inst->rs1], offset, cpu->GPR[inst->rs1] + offset);
                printf("read data: %0x \n", mem_read_my_E4(mem, cpu->GPR[inst->rs1] + offset, 1));
                if (inst->rd != 0x0) cpu->GPR[inst->rd] = mem_read_my_E4(mem, cpu->GPR[inst->rs1] + offset, 4);
                if (color->color_write_index < 32 * 32) {
                    if (cpu->GPR[inst->rs1] + offset >= 0x20000000 && cpu->GPR[inst->rs1] + offset < 0x20040000){
                        color->color_buf[color->color_write_index++] = cpu->GPR[inst->rd];
                    }
                }
            }

            // lbu
            else if (inst->funct3 == 0x4){
                int32_t offset = sign_extend_my_E4(extract_bits_unsigned_my_E4(20, 31, inst->raw), 12);
                printf("rs1: %0x, offset: %0x, mem addr: %0x \n",cpu->GPR[inst->rs1], offset, cpu->GPR[inst->rs1] + offset);
                printf("read data: %0x \n", mem_read_my_E4(mem, cpu->GPR[inst->rs1] + offset, 1));
                if (inst->rd != 0x0) cpu->GPR[inst->rd] = mem_read_my_E4(mem, cpu->GPR[inst->rs1] + offset, 1);
            }
            cpu->pc += 4;
            break;
        }

        case 0x23 : {
            // sb
            if (inst->funct3 == 0x0){
                uint32_t imm = (extract_bits_unsigned_my_E4(25, 31, inst->raw) << 5) | extract_bits_unsigned_my_E4(7, 11, inst->raw);
                int32_t offset = sign_extend_my_E4(imm, 12);
                printf("rs1: %0x, offset: %0x, mem addr: %0x \n",cpu->GPR[inst->rs1], offset, cpu->GPR[inst->rs1] + offset);
                int32_t data = cpu->GPR[inst->rs2];
                mem_write_my_E4(mem, cpu->GPR[inst->rs1] + offset, 1, data);
                printf("write data: %0x \n", mem_read_my_E4(mem, cpu->GPR[inst->rs1] + offset, 1));
            }
            
            // sw
            else if (inst->funct3 == 0x02){
                uint32_t imm = (extract_bits_unsigned_my_E4(25, 31, inst->raw) << 5) | extract_bits_unsigned_my_E4(7, 11, inst->raw);
                int32_t offset = sign_extend_my_E4(imm, 12);
                printf("rs1: %0x, offset: %0x, mem addr: %0x \n",cpu->GPR[inst->rs1], offset, cpu->GPR[inst->rs1] + offset);
                int32_t data = cpu->GPR[inst->rs2];
                printf("data to write: %0x \n", data);
                mem_write_my_E4(mem, cpu->GPR[inst->rs1] + offset, 4, data);
                printf("write data: %0x \n", mem_read_my_E4(mem, cpu->GPR[inst->rs1] + offset, 4));
            }
            
            cpu->pc += 4;
            break;
        }

        case 0x13 : {
            // addi
            if (inst->funct3 == 0x0){
                uint32_t imm = (extract_bits_unsigned_my_E4(20, 31, inst->raw));
                int32_t add_num = sign_extend_my_E4(imm, 12);
                if (inst->rd != 0x0) cpu->GPR[inst->rd] = cpu->GPR[inst->rs1] + add_num;
            }
            cpu->pc += 4;
            break;
        }

        case 0x33 : {
            if (inst->funct3 == 0x0 && inst->funct7 == 0x0){
                if (inst->rd != 0x0) cpu->GPR[inst->rd] = cpu->GPR[inst->rs1] + cpu->GPR[inst->rs2]; 
            }
            cpu->pc += 4;
            break;
        }
        default : {
            cpu->pc += 4;
            break;
        }
    }
}

void inst_cycle_my_E4(CpuState_my_E4 *cpu, Memory_my_E4 * mem, Instruction_my_E4 * inst, Color_my_E4 *color){
    inst->raw = get_inst_my_E4(mem, cpu->pc);
    inst->opcode = extract_bits_unsigned_my_E4(0, 6, inst->raw);
    inst->funct3 = extract_bits_unsigned_my_E4(12, 14, inst->raw);
    inst->funct7 = extract_bits_unsigned_my_E4(25, 31, inst->raw);
    inst->rd = extract_bits_unsigned_my_E4(7, 11, inst->raw);
    inst->rs1 = extract_bits_unsigned_my_E4(15, 19, inst->raw);
    inst->rs2 = extract_bits_unsigned_my_E4(20, 24, inst->raw);
    execute_instruction_my_E4(cpu, mem, inst, color);
    cpu->GPR[0] = 0;
}