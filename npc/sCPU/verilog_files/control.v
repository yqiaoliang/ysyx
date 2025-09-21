    // wire [31:0] pc, next_pc;
    // wire [31:0] alu_data;
    // wire is_jar,     // ?
    // wire [31:0] inst_sCPU;
    
    // wire [6:0] opocde;
    // wire [4:0] rs1;
    // wire [4:0] rs2;
    // wire [5:0] rd;
    // wire [2:0] funct3;
    // wire [6:0] funct7;

    // wire gpr_w_en;          // ?
    // wire [31:0] gpr_w_data;  // ?
    // wire [31:0] rs1_data;
    // wire [31:0] rs2_data;

    // wire [31:0] ram_addr;   // ?
    // wire ram_w_en;          // ?
    // wire [2:0] ram_rw_byte; // ?
    // wire [31:0] ram_w_data; // ?
    // wire [31:0] ram_r_data;

    // wire alu_is_zero;
    // wire alu_is_overflow;
    // wire [31:0] alu_input_A;    // ?
    // wire [31:0] alu_input_B;    // ?
    // wire [2:0] alu_op;


module control (
    input rst,
    input [6:0] opcode,
    input [2:0] funct3,
    input [6:0] funct7,
    input [31:0] alu_data,
    input [31:0] imm,
    input [31:0] pc,
    input [31:0] rs1_data,
    input [31:0] rs2_data,
    input [31:0] ram_r_data,
    /* verilator lint_off UNUSEDSIGNAL */
    input [31:0] GPR_10,
    /* verilator lint_on UNUSEDSIGNAL */
    output reg is_jar,
    output reg [2:0] inst_type,
    output reg gpr_w_en,
    output reg [31:0] gpr_w_data,
    output reg ram_w_en,
    output reg [31:0] ram_addr,
    output reg [2:0] ram_rw_byte,
    output reg [31:0] ram_w_data,
    output reg [31:0] alu_input_A,
    output reg [31:0] alu_input_B,
    output reg [2:0] alu_op
);



    /* verilator lint_off UNUSEDSIGNAL */
    parameter R_type = 0, I_type = 1, S_type = 2;
    parameter U_type = 4;
    /* verilator lint_on UNUSEDSIGNAL */
    

    task set_default;
    begin
        is_jar = 1'b0;
        inst_type = R_type;
        gpr_w_en = 1'b0;
        gpr_w_data = 32'h0;
        ram_w_en = 1'b0;
        ram_addr = 32'h0;
        ram_rw_byte = 3'b000;
        ram_w_data = 32'h0;
        alu_input_A = 32'h0;
        alu_input_B = 32'h0;
        alu_op = 3'b000;
    end
    endtask


    always @(*) begin
        if (rst) begin
            set_default;
        end

        else begin
            case(opcode)
                7'h37 : begin // lui
                    is_jar = 0;
                    inst_type = U_type;
                    gpr_w_en = 1;
                    gpr_w_data = imm; 
                    ram_w_en = 0;
                    ram_addr = 0;
                    ram_rw_byte = 0; 
                    ram_w_data = 0;
                    alu_input_A = 0;
                    alu_input_B = 0;
                    alu_op = 0;
                end

                7'h67 : begin // jalr
                    if (funct3 == 3'b0) begin
                        is_jar = 1;
                        inst_type = I_type;
                        gpr_w_en = 1;
                        gpr_w_data = pc + 4;
                        ram_w_en = 0;
                        ram_addr = 0;
                        ram_rw_byte = 0; 
                        ram_w_data = 0;
                        alu_op = 0;
                        alu_input_A = imm;
                        alu_input_B = rs1_data;
                    end
                    else set_default;
                end

                7'h03 : begin
                    //lw
                    if (funct3 == 3'b010) begin
                        is_jar = 0;
                        inst_type = I_type;
                        gpr_w_en = 1;
                        gpr_w_data = ram_r_data;
                        ram_w_en = 0;
                        ram_rw_byte = 4;
                        ram_addr = alu_data;
                        ram_w_data = 0;
                        alu_op = 0;
                        alu_input_A = imm;
                        alu_input_B = rs1_data;
                    end
                    // lbu
                    else if (funct3 == 3'b100) begin
                        is_jar = 0;
                        inst_type = I_type;
                        gpr_w_en = 1;
                        gpr_w_data = ram_r_data;
                        ram_w_en = 0;
                        ram_rw_byte = 1;
                        ram_addr = alu_data;
                        ram_w_data = 0;
                        alu_op = 0;
                        alu_input_A = imm;
                        alu_input_B = rs1_data;
                    end
                    else set_default;
                end

                7'h23 : begin
                    // sb
                    if (funct3 == 3'b000) begin
                        is_jar = 0;
                        inst_type = S_type;
                        gpr_w_en = 0;
                        gpr_w_data = 0;
                        ram_w_en = 1;
                        ram_rw_byte = 1;
                        ram_addr = alu_data;
                        ram_w_data = rs2_data;
                        alu_op = 0;
                        alu_input_A = imm;
                        alu_input_B = rs1_data;
                    end

                    //sw
                    else if (funct3 == 3'b010) begin
                        is_jar = 0;
                        inst_type = S_type;
                        gpr_w_en = 0;
                        gpr_w_data = 0;
                        ram_w_en = 1;
                        ram_rw_byte = 4;
                        ram_addr = alu_data;
                        ram_w_data = rs2_data;
                        alu_op = 0;
                        alu_input_A = imm;
                        alu_input_B = rs1_data;
                    end

                    else set_default;
                end

                7'h13 : begin
                    // addi
                    if (funct3 == 3'b000) begin
                        is_jar = 0;
                        inst_type = I_type;
                        gpr_w_en = 1;
                        gpr_w_data = alu_data;
                        ram_w_en = 0;
                        ram_rw_byte = 0;
                        ram_addr = 0;
                        ram_w_data = 0;
                        alu_op = 0;
                        alu_input_A = imm;
                        alu_input_B = rs1_data;
                    end
                    else set_default;
                end

                7'h33 : begin
                    if ((funct3 == 3'b000) && (funct7 == 7'b0)) begin
                        is_jar = 0;
                        inst_type = R_type;
                        gpr_w_en = 1;
                        gpr_w_data = alu_data;
                        ram_w_en = 0;
                        ram_rw_byte = 0;
                        ram_addr = 0;
                        ram_w_data = 0;
                        alu_op = 0;
                        alu_input_A = rs2_data;
                        alu_input_B = rs1_data;
                    end
                    else set_default;
                end

                7'h73 : begin
                    // nemu_trap();
                    set_default;
                end

                default: begin
                   set_default;
                end
            endcase
        end
    end

endmodule
