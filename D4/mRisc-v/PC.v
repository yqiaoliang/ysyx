module PC(
    input clk,
    input rst,
    input PCSrc,    // 1: branch, 0: pc+4
    input [31:0] alu_out,
    input pc_delay, // 1: pc hold, 0: pc update
    input [31:0] pre_pc,
    output reg [31:0] cur_pc
);

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            cur_pc <= 32'b0;
        end

        else if (pc_delay) begin
            cur_pc <= pre_pc;
        end

        else if (PCSrc) begin
            cur_pc <= alu_out;
        end

        else begin
            cur_pc <= pre_pc;
        end
    end

endmodule