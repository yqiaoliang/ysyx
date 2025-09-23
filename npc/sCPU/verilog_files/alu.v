module alu(
    input clk,
    input [31:0] alu_input_A,
    input [31:0] alu_input_B,
    input [3:0] alu_op,
    output reg [31:0] alu_data,
    output reg is_zero,
    output reg is_carry_out,
    output reg [1:0] cmp,
    output reg is_overflow
);

    // 监控语句应该放在always块外部
    // initial begin
    //     // 将所有需要监控的信号放在同一个$monitor中
    //     $monitor("Time: %t, alu_op: %h, input_A: %h, input_B: %h, alu_data: %h", 
    //             $time, alu_op, alu_input_A, alu_input_B, alu_data);
    // end

    parameter ADD = 0, SUB = 1, MUL = 2, DIV = 3, AND = 4, OR = 5, XOR = 6, SLL = 7, SRL = 8, SRA = 9, CMP = 10;
    parameter EQU = 0, SMALLER = 1, BIGGER = 2;

    always @(*) begin
        if (clk) begin
            case(alu_op)
            ADD : begin
                {is_carry_out, alu_data} = {1'b0, alu_input_A} + {1'b0, alu_input_B};
                is_overflow = (alu_input_A[31] == alu_input_B[31]) && (alu_data[31] != alu_input_A[31]);
            end

            SUB : begin
                {is_carry_out, alu_data} = {1'b0, alu_input_A} - {1'b0, alu_input_B};
                is_overflow = (alu_input_A[31] != alu_input_B[31]) && (alu_data[31] != alu_input_A[31]);
            end

            MUL : begin
                alu_data = alu_input_A * alu_input_B;
                is_carry_out = 0; // Carry out not meaningful for MUL
                is_overflow = |(alu_input_A[31] ^ alu_input_B[31] ^ alu_data[31]);
            end

            DIV : begin
                if (alu_input_B == 0) begin
                    alu_data = 32'hFFFFFFFF;
                    is_carry_out = 0;
                    is_overflow = 1;
                end 
                else begin
                    alu_data = alu_input_A / alu_input_B;
                    is_carry_out = 0;
                    is_overflow = 0;
                end
            end

            AND : begin
                alu_data = alu_input_A & alu_input_B;
                is_carry_out = 0;
                is_overflow = 0;
            end

            OR : begin
                alu_data = alu_input_A | alu_input_B;
                is_carry_out = 0;
                is_overflow = 0;
            end

            XOR : begin
                alu_data = alu_input_A ^ alu_input_B;
                is_carry_out = 0;
                is_overflow = 0;
            end
            
            SLL : begin
                alu_data = alu_input_A << alu_input_B[4:0];
                is_carry_out = 0;
                is_overflow = 0;
            end

            SRL : begin
                alu_data = alu_input_A >> alu_input_B[4:0];
                is_carry_out = 0;
                is_overflow = 0;
            end

            SRA : begin
                alu_data = ($signed(alu_input_A)) >>> alu_input_B[4:0];
                is_carry_out = 0;
                is_overflow = 0;
            end

            CMP : begin
                if (($signed(alu_input_A)) == ($signed(alu_input_B))) begin
                    cmp = EQU;
                end 
                else if (($signed(alu_input_A)) < ($signed(alu_input_B))) begin
                    cmp = SMALLER;
                end 
                else begin
                    cmp = BIGGER;
                end
                alu_data = 32'b0;
                is_carry_out = 0;
                is_overflow = 0;
            end

            default : begin
                {is_carry_out, alu_data} = {1'b0, alu_input_A} + {1'b0, alu_input_B};
                is_overflow = (alu_input_A[31] == alu_input_B[31]) && (alu_data[31] != alu_input_A[31]);
            end
            endcase

            is_zero = (alu_data == 0) ? 1 : 0;
        end
    end

endmodule

