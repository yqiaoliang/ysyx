module pc_m(
    input clk,
    input rst,
    input [31:0] alu_data,
    input is_jar, // 1 : pc+4, 0:alu_data
    output reg [31:0] current_pc,
    output reg [31:0] next_pc
);

    always @(negedge clk or posedge rst) begin
        if (rst) begin
            next_pc <= 32'h7ffffffc;
            // next_pc <= 32'hfffffffc;
        end

        else begin
            if (!is_jar) next_pc <= current_pc + 4;
            else next_pc <= alu_data;
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            current_pc <= 32'h7ffffffc;
            // current_pc <= 32'hfffffffc;
        end
        else begin
            current_pc <= next_pc;
        end
    end

endmodule
