// module gpr(
//     input clk,
//     input rst,
//     input [4:0] crs_rs1,
//     input [4:0] crs_rd,
//     input w_en,
//     input [31:0] w_data,
//     output reg [31:0] crs_rs1_data,
// );


// // #define MEPC    0x341
// // #define MSTATUS 0x300
// // #define MCAUSE  0x342
// // #define MTVEC   0x305

//     parameter MEPC = 12'h341, MSTATUS = 12'h300, MCAUSE = 12'h342, MTVEC = 12'h305;


//     reg[31:0] crs[4:0];

//     always @(negedge clk or posedge rst) begin
//         if (rst) begin
//             for (int i = 0; i < 4; i++) crs[i] <= 0;
//         end

//         else if (w_en) begin
//             switch(crs_rd) begin
//                 MEPC    : crs[0] <= w_data;
//                 MSTATUS : crs[1] <= w_data;
//                 MCAUSE  : crs[2] <= w_data;
//                 MTVEC   : crs[3] <= w_data;
//                 default : crs[4] <= w_data;
//             end
//         end

//     end

    
    
//     always @(posedge clk) begin
//         crs_rs1_data <= 
//     end

// endmodule
