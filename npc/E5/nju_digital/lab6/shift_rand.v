module shift_rand(
    input rst,
    input clk,
    output reg [7:0] data_out,
    output reg [6:0] seg_out_0,
    output reg [6:0] seg_out_1
);

    segment_7 seg7_0(data_out[3:0], seg_out_0);
    segment_7 seg7_1(data_out[7:4], seg_out_1);

    always @(posedge clk or posedge rst) begin
        if (rst) data_out <= 8'b0;
        else begin
            data_out[6:0] <= data_out[7:1];
            data_out[7] <= data_out[4] ~^ data_out[3] ~^ data_out[2] ~^ data_out[0]; 
        end
    end

endmodule