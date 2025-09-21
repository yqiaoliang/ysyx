// `include "segment_7.v"

module encode8x3 (
    input [7:0] data_in,
    input en,
    output is_zero,
    output reg [6:0] seg,
    output reg [2:0] data_out
);
    assign is_zero = (data_in == 8'b00000000);
    segment_7 seg_7({1'b0, data_out}, seg);

    
    always @(*) begin
        if (!en) begin
            data_out = 3'b000;
        end else begin
            casez (data_in)
                8'b1??????? : data_out = 3'b111;
                8'b01?????? : data_out = 3'b110;
                8'b001????? : data_out = 3'b101;
                8'b0001???? : data_out = 3'b100;
                8'b00001??? : data_out = 3'b011;
                8'b000001?? : data_out = 3'b010;
                8'b0000001? : data_out = 3'b001;
                8'b00000001 : data_out = 3'b000;
                default : data_out = 3'b000;
            endcase
        end
    end

endmodule
