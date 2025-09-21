module GPR(
    input clk,
    input rst,
    input [1:0]rs1,
    input [1:0]rs2,
    input [1:0]rd,
    input write,
    input [7:0] write_data,
    output reg [7:0] rs1_data,
    output reg [7:0] rs2_data
);

    reg [1:0]GPR[7:0];

    

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            for(int i = 0; i < 3; i++) GPR[i] <= 8'b0;
            rs1_data <= 8'b0;
            rs2_data <= 8'b;
        end

        else begin
            if (write) begin
                GPR[rd] <= write_data;
            end

            else begin
                rs1_data <= GPR[rs1];
                rs2_data <= GPR[rs1];
            end
        end
    end

endmodule