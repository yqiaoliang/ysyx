module priority_encoder_83 (
    input  wire [8:0] SW,       // SW[8]: 使能端 en；SW[7:0]: 输入 in[7:0]
    output  reg [4:0] LED,      // LED[4]: 指示位 valid；LED[2:0]: 编码 code
    output  reg [6:0] HEX0      // 七段数码管，显示十进制编码结果
);

    wire [7:0] in = SW[7:0];    // 8 位输入
    wire       en = SW[8];      // 使能端

    reg [2:0] code;             // 3 位编码结果
    reg       valid;            // 指示位（输入是否全 0）

    // 七段数码管译码表（共阴极，低电平点亮）
    // 索引 0~7 对应显示数字 0~7
    reg [6:0] seg_table [0:7];
    initial begin
        seg_table[0] = 7'b0111111; // 0
        seg_table[1] = 7'b0000110; // 1
        seg_table[2] = 7'b1011011; // 2
        seg_table[3] = 7'b1001111; // 3
        seg_table[4] = 7'b1100110; // 4
        seg_table[5] = 7'b1101101; // 5
        seg_table[6] = 7'b1111101; // 6
        seg_table[7] = 7'b0000111; // 7
    end

    // 8-3 优先编码器逻辑（高位优先）
    always @(*) begin
        if (!en) begin // 使能无效时，输出全 0
            code  = 3'b000;
            valid = 1'b0;
        end else begin
            valid = 1'b0;
            code  = 3'b000;
            // 从最高位（bit7）到最低位（bit0）遍历，找到第一个为 1 的位
            casez (in)
                8'b1???????: begin code = 3'b111; valid = 1'b1; end
                8'b01??????: begin code = 3'b110; valid = 1'b1; end
                8'b001?????: begin code = 3'b101; valid = 1'b1; end
                8'b0001????: begin code = 3'b100; valid = 1'b1; end
                8'b00001???: begin code = 3'b011; valid = 1'b1; end
                8'b000001??: begin code = 3'b010; valid = 1'b1; end
                8'b0000001?: begin code = 3'b001; valid = 1'b1; end
                8'b00000001: begin code = 3'b000; valid = 1'b1; end
                default:     begin code = 3'b000; valid = 1'b0; end
            endcase
        end
        LED[2:0] = code;
        LED[4]   = valid;
        LED[3:1] = 3'b000;
        HEX0 = seg_table[code];
    end

    // 七段数码管输出（根据编码结果 code 查表）
    // assign

    // // LED 输出赋值
    // assign 
    // assign 
    // assign  // 未使用的 LED 置 0

endmodule
