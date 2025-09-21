module segment_7(
    input [3:0] bin,      // 4位二进制输入
    output reg [6:0] seg  // 七段输出，seg[0]对应a段，seg[1]对应b段...seg[6]对应g段
);

// 七段数码管各段定义:
//    a
//   ---
//  f| |b
//   -g-
//  e| |c
//   ---
//    d

always @(*) begin
    case(bin)
        4'd0: seg = 7'b0000001;  // 0: a,b,c,d,e,f亮，g灭
        4'd1: seg = 7'b1001111;  // 1: b,c亮
        4'd2: seg = 7'b0010010;  // 2: a,b,g,e,d亮
        4'd3: seg = 7'b0000110;  // 3: a,b,g,c,d亮
        4'd4: seg = 7'b1001100;  // 4: f,g,b,c亮
        4'd5: seg = 7'b0100100;  // 5: a,f,g,c,d亮
        4'd6: seg = 7'b0100000;  // 6: a,f,g,c,d,e亮
        4'd7: seg = 7'b0001111;  // 7: a,b,c亮
        4'd8: seg = 7'b0000000;  // 8: 全亮
        4'd9: seg = 7'b0000100;  // 9: a,b,c,d,f,g亮
        4'd10: seg = 7'b0001000; // A: a,b,c,e,f,g亮
        4'd11: seg = 7'b1100000; // b: c,d,e,f,g亮
        4'd12: seg = 7'b0110001; // C: a,d,e,f亮
        4'd13: seg = 7'b1000010; // d: b,c,d,e,g亮
        4'd14: seg = 7'b0110000; // E: a,d,e,f,g亮
        4'd15: seg = 7'b0111000; // F: a,e,f,g亮
        default: seg = 7'b1111111; // 默认全灭
    endcase
end

endmodule