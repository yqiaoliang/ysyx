module sCPU(
    input clk,
    input rst,
    /* verilator lint_off UNUSEDSIGNAL */
    input [31:0] inst_CXX,
    /* verilator lint_on UNUSEDSIGNAL */
    output reg unknow_inst,
    output [31:0] pc_o,
    output [31:0] next_pc_o,
    output [31:0] out_inst,
    output reg [31:0] gpr_files[31:0]
);

    wire [31:0] pc;
    /* verilator lint_off UNUSEDSIGNAL */
    wire [31:0] next_pc;
    /* verilator lint_on UNUSEDSIGNAL */
    wire [31:0] alu_data;
    wire is_jar;     
    /* verilator lint_off UNUSEDSIGNAL */
    wire [31:0] inst_sCPU;
    /* verilator lint_on UNUSEDSIGNAL */
    
    wire [6:0] opcode;
    wire [4:0] rs1;
    wire [4:0] rs2;
    wire [4:0] rd;
    wire [2:0] funct3;
    wire [6:0] funct7;

    wire [2:0] inst_type;
    wire [31:0] imm_sCPU;

    wire gpr_w_en;         
    wire [31:0] gpr_w_data;  
    wire [31:0] rs1_data;
    wire [31:0] rs2_data;

    wire [31:0] ram_addr;   
    wire ram_w_en;          
    wire [2:0] ram_rw_byte; 
    wire [31:0] ram_w_data; 
    wire [31:0] ram_r_data;

    /* verilator lint_off UNUSEDSIGNAL */
    wire alu_is_zero;
    wire [1:0] alu_cmp;
    wire alu_is_carry_out;
    wire alu_is_overflow;
    /* verilator lint_on UNUSEDSIGNAL */
    wire [31:0] alu_input_A;    
    wire [31:0] alu_input_B; 
    wire [3:0] alu_op;

    assign pc_o = pc;
    assign next_pc_o = next_pc;
    assign out_inst = inst_sCPU;
    

    pc_m PC_CPU(
        .clk(clk),
        .rst(rst),
        .alu_data(alu_data),
        .is_jar(is_jar),
        .current_pc(pc),
        .next_pc(next_pc)
    );

    
    rom ROM_CPU(
        .addr(pc),
        .inst(inst_sCPU)
    );

    inst INST_CPU(
        .inst(inst_sCPU),
        .opcode(opcode),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .funct3(funct3),
        .funct7(funct7)
    );

    imm IMM_CPU(
        .inst_type(inst_type),
        .inst(inst_sCPU),
        .imm(imm_sCPU)
    );


    gpr GPR_CPU(
        .clk(clk),
        .rst(rst),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .w_en(gpr_w_en),
        .w_data(gpr_w_data),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .gpr_files(gpr_files)
    );


    ram RAM_CPU(
        .clk(clk),
        .addr(ram_addr),
        .w_en(ram_w_en),
        .rw_byte(ram_rw_byte),
        .w_data(ram_w_data),
        .r_data(ram_r_data)
    );

    alu ALU_CPU(
        .clk(clk),
        .alu_input_A(alu_input_A),
        .alu_input_B(alu_input_B),
        .alu_op (alu_op),
        .alu_data(alu_data),
        .is_zero(alu_is_zero),
        .cmp(alu_cmp),
        .is_carry_out(alu_is_carry_out),
        .is_overflow(alu_is_overflow)
    );

    control CONTROL_CPU(
        .rst(rst),
        .opcode(opcode),
        .funct3(funct3),
        .funct7(funct7),
        .alu_data(alu_data),
        .imm(imm_sCPU),
        .pc(pc),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .ram_r_data(ram_r_data),
        .GPR_10(gpr_files[10]),
        .alu_is_carry_out(alu_is_carry_out),
        .alu_cmp(alu_cmp),
        .unknow_inst(unknow_inst),
        .is_jar(is_jar),
        .inst_type(inst_type),
        .gpr_w_en(gpr_w_en),
        .gpr_w_data(gpr_w_data),
        .ram_w_en(ram_w_en),
        .ram_addr(ram_addr),
        .ram_rw_byte(ram_rw_byte),
        .ram_w_data(ram_w_data),
        .alu_input_A(alu_input_A),
        .alu_input_B(alu_input_B),
        .alu_op(alu_op)
    );
    

endmodule
