module alu(
    input rst,
    input clk,
    input [2:0] op,
    input [3:0] A,
    input [3:0] B,
    output reg out,
    output reg is_zero,
    output reg is_overflow,
    output reg is_carry,
    output reg [3:0] data_out
);

    reg [4:0] alu_temp;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            is_zero <= 0;
            is_overflow <= 0;
            is_carry <= 0;
            out <= 0;
            data_out <= 0;
        end

        else begin
            case (op)
                3'd0 : begin
                    alu_temp <= {1'b0, A} + {1'b0, B}; 
                    data_out <= A + B;
                    is_zero <= (data_out == 4'b0) ? 1 : 0;
                    is_overflow = ((~(A[3] ^ B[3])) ^ data_out[3])  ? 1 : 0;
                    is_carry = alu_temp[4] ? 1 : 0;
                    out <= 0;
                end

                3'd1 : begin
                    alu_temp <= {1'b0, A} - {1'b0, B}; 
                    data_out <= A - B;
                    is_zero <= (data_out == 4'b0) ? 1 : 0;
                    is_overflow = ((A[3] ^ B[3]) ^ (data_out[3] ^ A[3]))  ? 1 : 0;
                    is_carry = alu_temp[4] ? 1 : 0;
                    out <= 0;
                end

                3'd2 : begin
                    data_out <= ~ A;
                    is_zero = 0;
                    is_overflow <= 0;
                    is_carry <= 0;
                    out <= 0;
                end

                3'd3 : begin
                    data_out <= A & B;
                    is_zero = 0;
                    is_overflow <= 0;
                    is_carry <= 0;
                    out <= 0;
                end

                3'd4 : begin
                    data_out <= A | B;
                    is_zero = 0;
                    is_overflow <= 0;
                    is_carry <= 0;
                    out <= 0;
                end

                3'd5 : begin
                    data_out <= A ^ B;
                    is_zero = 0;
                    is_overflow <= 0;
                    is_carry <= 0;
                    out <= 0;
                end

                3'd6 : begin
                    alu_temp <= {1'b0, A} - {1'b0, B}; 
                    data_out <= alu_temp[3:0];
                    is_zero <= (data_out == 4'b0) ? 1 : 0;
                    is_overflow = ((A[3] ^ B[3]) ^ (data_out[3] ^ A[3]))  ? 1 : 0;
                    is_carry = alu_temp[4] ? 1 : 0;
                    out <= A[3] ^ is_overflow;
                end

                3'd7 : begin
                    alu_temp <= {1'b0, A} - {1'b0, B}; 
                    data_out <= alu_temp[3:0];
                    is_zero <= (data_out == 4'b0) ? 1 : 0;
                    is_overflow = ((A[3] ^ B[3]) ^ (data_out[3] ^ A[3]))  ? 1 : 0;
                    is_carry = alu_temp[4] ? 1 : 0;
                    out <= is_zero;
                end
            endcase
        end
    end

endmodule
