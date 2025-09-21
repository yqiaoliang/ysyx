module alu(
    input [31:0] alu_input_A,
    input [31:0] alu_input_B,
    input [2:0] alu_op,
    output reg [31:0] alu_data,
    output reg is_zero,
    output reg is_overflow
);

    // 监控语句应该放在always块外部
    // initial begin
    //     // 将所有需要监控的信号放在同一个$monitor中
    //     $monitor("Time: %t, input_A: %h, input_B: %h, alu_data: %h", 
    //             $time, alu_input_A, alu_input_B, alu_data);
    // end
    always @(*) begin
        case(alu_op)
            0 : begin
                alu_data = alu_input_A + alu_input_B;
                is_overflow = (alu_input_A[31] == alu_input_B[31]) && (alu_data[31] != alu_input_A[31]);
            end

            default : begin
                alu_data = alu_input_A + alu_input_B;
                is_overflow = (alu_input_A[31] == alu_input_B[31]) && (alu_data[31] != alu_input_A[31]);
            end 

        endcase

        is_zero = (alu_data == 0) ? 1 : 0;
    end

endmodule

