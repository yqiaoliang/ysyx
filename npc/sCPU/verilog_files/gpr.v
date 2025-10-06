module gpr(
    input clk,
    input rst,
    input [4:0] rs1,
    input [4:0] rs2,
    input [4:0] rd,
    input w_en,
    input [31:0] w_data,
    output reg [31:0] rs1_data,
    output reg [31:0] rs2_data,
    output [31:0] gpr_files[31:0]
);

// typedef struct{
//   word_t mepc;    // 存放触发异常的PC
//   word_t mstatus; // 存放处理器的状态
//   word_t mcause;  // 存放触发异常的原因
//   word_t mtvec;   // 取出异常入口地址
// }CSR_state;

// #define MEPC    0x341
// #define MSTATUS 0x300
// #define MCAUSE  0x342
// #define MTVEC   0x305


    reg[31:0] GPR[31:0];

    always @(negedge clk or posedge rst) begin
        if (rst) begin
            for (int i = 0; i < 32; i++) GPR[i] <= 0;
        end

        else if (w_en && rd != 0) GPR[rd] <= w_data;

        // end

        // else if (w_en && rd != 0) begin
        //     GPR[rd] <= w_data;
        // end

        
    end

    assign gpr_files = GPR;
    // assign rs1_data = GPR[rs1];
    // assign rs2_data = GPR[rs2];

    // always @(*) begin
    //     if (clk) begin
    //         rs1_data = GPR[rs1];
    //         rs2_data = GPR[rs2];
    //     end
    //     else begin
    //         rs1_data = rs1_data;
    //         rs2_data = rs2_data;
    //     end
    // end
    always @(posedge clk) begin
            rs1_data <= GPR[rs1];
            rs2_data <= GPR[rs2];
    end


endmodule
