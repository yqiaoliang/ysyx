module rom(
    input [7:0] addr,
    output reg [7:0] read_data
);

    reg ROM[7:0][7:0];

    always @(*) begin
        read_data <= ROM[addr];
    end

endmodule