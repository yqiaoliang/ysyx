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
    input alu_is_carry_out,
    input [1:0] alu_cmp,
    /* verilator lint_on UNUSEDSIGNAL */
    output reg unknow_inst,
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
    output reg [3:0] alu_op
);



    /* verilator lint_off UNUSEDSIGNAL */
    parameter R_type = 0, I_type = 1, S_type = 2;
    parameter B_type = 3, U_type = 4, J_type = 5;

    parameter ADD = 0, SUB = 1, MUL = 2, DIV = 3, AND = 4, OR = 5, XOR = 6, SLL = 7, SRL = 8, SRA = 9, CMP = 10;
    parameter EQU = 0, SMALLER = 1, BIGGER = 2;
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
        alu_op = 4'b0000;
        unknow_inst = 1;
    end
    endtask


    always @(*) begin
        if (rst) begin
            set_default;
            unknow_inst = 0;
        end

        else begin
            case(opcode)
                7'h37 : begin
                    // lui
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
                    unknow_inst = 0;
                end

                7'h67 : begin 
                    // jalr
                    if (funct3 == 3'b0) begin
                        is_jar = 1;
                        inst_type = I_type;
                        gpr_w_en = 1;
                        gpr_w_data = pc + 4;
                        ram_w_en = 0;
                        ram_addr = 0;
                        ram_rw_byte = 0; 
                        ram_w_data = 0;
                        alu_op = ADD;
                        alu_input_A = rs1_data;
                        alu_input_B = imm;
                        unknow_inst = 0;
                    end
                    else set_default;
                end

                7'h6f : begin
                    // jal
                    is_jar = 1;
                    inst_type = J_type;
                    gpr_w_en = 1;
                    gpr_w_data = pc + 4;
                    ram_w_en = 0;
                    ram_addr = 0;
                    ram_rw_byte = 0; 
                    ram_w_data = 0;
                    alu_op = ADD;
                    alu_input_A = pc;
                    alu_input_B = imm;
                    unknow_inst = 0;
                end

                7'h03 : begin
                    is_jar = 0;
                    inst_type = I_type;
                    gpr_w_en = 1;
                    gpr_w_data = ram_r_data;
                    ram_w_en = 0;
                    ram_addr = alu_data;
                    ram_w_data = 0;
                    alu_op = ADD;
                    alu_input_A = rs1_data;
                    alu_input_B = imm;


                    // lb
                    if (funct3 == 3'b000) begin
                        ram_rw_byte = 1;
                        gpr_w_data = {{24{ram_r_data[7]}}, ram_r_data[7:0]};
                        unknow_inst = 0;
                    end

                    // lh
                    else if (funct3 == 3'b001) begin
                        ram_rw_byte = 2;
                        gpr_w_data = {{16{ram_r_data[15]}}, ram_r_data[15:0]};
                        unknow_inst = 0;
                    end

                    // lw
                    else if (funct3 == 3'b010) begin
                        ram_rw_byte = 4;
                        unknow_inst = 0;
                    end

                    // lbu
                    else if (funct3 == 3'b100) begin
                        ram_rw_byte = 1;
                        unknow_inst = 0;
                    end

                    // lhu
                    else if (funct3 == 3'b101) begin
                        ram_rw_byte = 2;
                        unknow_inst = 0;
                    end

                    else set_default;
                end

                7'h23 : begin
                    is_jar = 0;
                    inst_type = S_type;
                    gpr_w_en = 0;
                    gpr_w_data = 0;
                    ram_w_en = 1;
                    ram_addr = alu_data;
                    ram_w_data = rs2_data;
                    alu_op = ADD;
                    alu_input_A = rs1_data;
                    alu_input_B = imm;

                    // sb
                    if (funct3 == 3'b000) begin
                        ram_rw_byte = 1;
                        unknow_inst = 0;
                    end

                    // sh
                    else if (funct3 == 3'b001) begin
                        ram_rw_byte = 2;
                        unknow_inst = 0;
                    end

                    //sw
                    else if (funct3 == 3'b010) begin
                        ram_rw_byte = 4;
                        unknow_inst = 0;
                    end
                    

                    else set_default;
                end

                7'h13 : begin
                        is_jar = 0;
                        inst_type = I_type;
                        gpr_w_en = 1;
                        gpr_w_data = alu_data;
                        ram_w_en = 0;
                        ram_rw_byte = 0;
                        ram_addr = 0;
                        ram_w_data = 0;
                        alu_input_A = rs1_data;
                        alu_input_B = imm;

                    // addi
                    if (funct3 == 3'b000) begin
                        alu_op = ADD;
                        unknow_inst = 0;
                    end

                    // andi
                    else if (funct3 == 3'b111) begin
                        alu_op = AND;
                        unknow_inst = 0;
                    end

                    // ori
                    else if (funct3 == 3'b110) begin
                        alu_op = OR;
                        unknow_inst = 0;
                    end

                    // xori
                    else if (funct3 == 3'b100) begin
                        alu_op = XOR;
                        unknow_inst = 0;
                    end

                    // slti
                    else if (funct3 == 3'b010) begin
                        alu_op = SUB;
                        gpr_w_data = (alu_data > imm) ? 0 : 1;
                        unknow_inst = 0;
                    end

                    // sltiu
                    else if (funct3 == 3'b011) begin
                        alu_op = SUB;
                        gpr_w_data = {31'b0 ,alu_is_carry_out};
                        unknow_inst = 0;
                    end

                    // slli
                    else if ((funct3 == 3'b001) && (funct7 == 7'b0000000)) begin
                        alu_op = SLL;
                        unknow_inst = 0;
                    end

                    // srli
                    else if ((funct3 == 3'b101) && (funct7 == 7'b0000000)) begin
                        alu_op = SRL;
                        unknow_inst = 0;
                    end

                    // srai
                    else if ((funct3 == 3'b101) && (funct7 == 7'b0100000)) begin
                        alu_op = SRA;
                        unknow_inst = 0;
                    end



                    else set_default;
                end

                7'h33 : begin
                    is_jar = 0;
                    inst_type = R_type;
                    gpr_w_en = 1;
                    gpr_w_data = alu_data;
                    ram_w_en = 0;
                    ram_rw_byte = 0;
                    ram_addr = 0;
                    ram_w_data = 0;
                    alu_input_A = rs1_data;
                    alu_input_B = rs2_data;
                    
                    // add
                    if ((funct3 == 3'b000) && (funct7 == 7'b000000)) begin
                        alu_op = ADD;
                        unknow_inst = 0;
                    end

                    // sub
                    else if ((funct3 == 3'b000) && (funct7 == 7'b0100000)) begin
                        alu_op = SUB;
                        unknow_inst = 0;
                    end

                    // sll
                    else if ((funct3 == 3'b001) && (funct7 == 7'b0000000)) begin
                        alu_op = SLL; 
                        unknow_inst = 0;
                    end

                    // slt
                    else if ((funct3 == 3'b010) && (funct7 == 7'b0000000)) begin
                        alu_op = CMP;
                        gpr_w_data = (alu_cmp == SMALLER) ? 1 : 0; 
                        unknow_inst = 0;
                    end

                    // sltu
                    else if ((funct3 == 3'b011) && (funct7 == 7'b0000000)) begin
                        alu_op = SUB;
                        gpr_w_data = {31'b0, alu_is_carry_out};
                        unknow_inst = 0;
                    end 

                    // xor
                    else if ((funct3 == 3'b100) && (funct7 == 7'b0000000)) begin
                        alu_op = XOR;
                        unknow_inst = 0;
                    end


                    // srl
                    else if ((funct3 == 3'b101) && (funct7 == 7'b0000000)) begin
                        alu_op = SRL;
                        unknow_inst = 0;
                    end

                    // sra
                    else if ((funct3 == 3'b101) && (funct7 == 7'b0100000)) begin
                        alu_op = SRA;
                        unknow_inst = 0;
                    end

                    // or
                    else if ((funct3 == 3'b110) && (funct7 == 7'b0000000)) begin
                        alu_op = OR;
                        unknow_inst = 0;
                    end

                    // and
                    else if ((funct3 == 3'b111) && (funct7 == 7'b0000000)) begin
                        alu_op = AND;
                        unknow_inst = 0;
                    end

                    else set_default;
                end

                7'h73 : begin
                    // nemu_trap();
                    set_default;
                    unknow_inst = 0;
                end

                7'h17 : begin
                    // auipc
                    is_jar = 0;
                    inst_type = U_type;
                    gpr_w_en = 1;
                    gpr_w_data = alu_data; 
                    ram_w_en = 0;
                    ram_addr = 0;
                    ram_rw_byte = 0; 
                    ram_w_data = 0;
                    alu_op = ADD;
                    alu_input_A = pc;
                    alu_input_B = imm;
                    unknow_inst = 0;
                end

                7'h1b : begin
                    // addiw
                    if (funct3 == 3'b000) begin
                        is_jar = 0;
                        inst_type = I_type;
                        gpr_w_en = 1;
                        gpr_w_data = alu_data; 
                        ram_w_en = 0;
                        ram_addr = 0;
                        ram_rw_byte = 0; 
                        ram_w_data = 0;
                        alu_op = ADD;
                        alu_input_A = rs1_data;
                        alu_input_B = imm;
                        unknow_inst = 0;
                    end

                    else set_default;
                end

                7'h3b : begin
                    is_jar = 0;
                    inst_type = I_type;
                    gpr_w_en = 1;
                    gpr_w_data = alu_data; 
                    ram_w_en = 0;
                    ram_addr = 0;
                    ram_rw_byte = 0; 
                    ram_w_data = 0;
                    alu_input_A = rs1_data;
                    alu_input_B = rs2_data;

                    // addw
                    if ((funct3 == 3'b000) && (funct7 == 7'b0000000)) begin
                        alu_op = ADD;
                        unknow_inst = 0;
                    end

                    // subw
                    else if ((funct3 == 3'b000) && (funct7 == 7'b0100000)) begin
                        alu_op = SUB;
                        unknow_inst = 0;
                    end

                    

                    // TODO: sllw

                    // TODO: srlw

                    // TODO: sraw

                    else set_default;
                end

                7'h63 : begin
                    inst_type = B_type;
                    gpr_w_en = 0;
                    gpr_w_data = 0; 
                    ram_w_en = 0;
                    ram_addr = 0;
                    ram_rw_byte = 0; 
                    ram_w_data = 0;
                    alu_op = 0;
                    alu_input_A = pc;
                    alu_input_B = imm;

                    //beq
                    if (funct3 == 3'b000) begin
                        is_jar = (rs1_data == rs2_data) ? 1 : 0;
                        unknow_inst = 0;
                    end

                    //beg
                    else if (funct3 == 3'b001) begin
                        is_jar = (rs1_data != rs2_data) ? 1 : 0;
                        unknow_inst = 0;
                    end

                    // blt
                    else if (funct3 == 3'b100) begin
                        is_jar = ($signed(rs1_data) < $signed(rs2_data)) ? 1 : 0;
                        unknow_inst = 0;
                    end

                    // bge
                    else if (funct3 == 3'b101) begin
                        is_jar = ($signed(rs1_data) >= $signed(rs2_data)) ? 1 : 0; 
                        unknow_inst = 0;
                    end

                    // bltu
                    else if (funct3 == 3'b110) begin
                        is_jar = (rs1_data < rs2_data) ? 1 : 0;
                        unknow_inst = 0;
                    end

                    // bgeu
                    else if (funct3 == 3'b111) begin
                        is_jar = (rs1_data >= rs2_data) ? 1 : 0;
                        unknow_inst = 0;
                    end

                    else set_default;
                end

            

                default: begin
                   set_default;
                end
            endcase
        end
    end

endmodule
