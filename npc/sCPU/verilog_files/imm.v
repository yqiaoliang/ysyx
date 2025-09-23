module imm(
    input [2:0] inst_type,
    /* verilator lint_off UNUSEDSIGNAL */
    input [31:0] inst,
    /* verilator lint_on UNUSEDSIGNAL */
    output reg [31:0] imm
);

    parameter R_type = 0, I_type = 1, S_type = 2;
    parameter B_type = 3, U_type = 4, J_type = 5;

    always @(*) begin
        case(inst_type)
            R_type : imm = 0;
            I_type : imm = {{20{inst[31]}}, inst[31:20]};
            S_type : imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
            B_type : imm = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
            U_type : imm = {inst[31:12], 12'b0};
            J_type : imm = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};
        endcase
    end

endmodule
