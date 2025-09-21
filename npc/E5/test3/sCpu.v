module sCpu(
    input clk,
    input rst,
    output reg [7:0] data_out,
    output reg [6:0] seg_out_0,
    output reg [6:0] seg_out_1
);

    reg [7:0] registers [3:0];
    reg [7:0] pc;
    reg [7:0] instruction_mem [0:255];

    segment_7 seg7_0(data_out[3:0], seg_out_0);
    segment_7 seg7_1(data_out[7:4], seg_out_1);


    
    wire [7:0] current_instruction = instruction_mem[pc];
    
    wire [1:0] opcode = current_instruction[7:6];
    wire [1:0] rd = current_instruction[5:4];
    wire [1:0] rs1 = current_instruction[3:2];
    wire [1:0] rs2 = current_instruction[1:0];
    wire [3:0] imm = current_instruction[3:0];
    wire [3:0] addr = current_instruction[5:2];
    
    initial begin
        instruction_mem[0] = 8'h40;
        instruction_mem[1] = 8'h8b;
        instruction_mem[2] = 8'h90;
        instruction_mem[3] = 8'ha1;
        instruction_mem[4] = 8'hb1;
        instruction_mem[5] = 8'h16;
        instruction_mem[6] = 8'h2b;
        instruction_mem[7] = 8'hd2;
        instruction_mem[8] = 8'hdd;
    end
    
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 8'b0;
            data_out <= 8'b0;
            for (integer i = 0; i < 4; i = i + 1)
                registers[i] <= 8'b0;
        end else begin
            case (opcode)
                2'b00: begin
                    registers[rd] <= registers[rs1] + registers[rs2];
                    pc <= pc + 1;
                end
                2'b10: begin
                    registers[rd] <= {4'b0, imm};
                    pc <= pc + 1;
                end
                2'b11: begin
                    if (registers[0] != registers[rs2])
                        pc <= {4'b0, addr};
                    else
                        pc <= pc + 1;
                end
                default: pc <= pc + 1;
            endcase

            data_out <= registers[1];
        end
    end
    

    // always @(*) begin
    //     registers[0] = 8'b0;
    // end

endmodule