module gpr(
    input clk,
    input rst,
    input [4:0] rs1,
    input [4:0] rs2,
    input [4:0] rd,
    input w_en,
    input [31:0] w_data,
    output [31:0] rs1_data,
    output [31:0] rs2_data,
    output [31:0] gpr_files[31:0]
);

    reg[31:0] GPR[31:0];

    always @(negedge clk or posedge rst) begin
        if (rst) begin
            for (int i = 0; i < 32; i++) GPR[i] <= 0;
        end

        else if (w_en && rd != 0) begin
            GPR[rd] <= w_data;
        end

        
    end

    assign gpr_files = GPR;
    assign rs1_data = GPR[rs1];
    assign rs2_data = GPR[rs2];


endmodule
