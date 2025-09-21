module ram(
    input clk,
    input [31:0] addr,
    input w_en,
    input [2:0] rw_byte,
    input [31:0] w_data,
    output reg [31:0] r_data
);

    parameter  use_DPI = 1;

    reg [7:0] RAM [(1<< 15)-1 : 0];
    import "DPI-C" function int pmem_read(input int raddr, input byte len);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

    always @(negedge clk) begin
        if (w_en && (!use_DPI)) begin
            case(rw_byte)
                3'b001: RAM[addr] <= w_data[7:0];
                3'b010: {RAM[addr+1], RAM[addr]} <= w_data[15:0];
                3'b100: {RAM[addr+3], RAM[addr+2], RAM[addr+1], RAM[addr]} <= w_data;
                default : RAM[addr] <= RAM[addr];
            endcase
        end

        else if (w_en && use_DPI) begin
            // pmem_write(waddr, wdata, wmask);
            pmem_write(addr, w_data, {5'b0, rw_byte});
        end
    end

    always @(*) begin
        if (!use_DPI && clk)
            case(rw_byte)
                3'b001: r_data = {24'b0, RAM[addr]};
                3'b010: r_data = {16'b0, RAM[addr+1], RAM[addr]};
                3'b100: r_data = {RAM[addr+3], RAM[addr+2], RAM[addr+1], RAM[addr]};
                default: r_data = 0;
            endcase
        else if (clk) begin
            case(rw_byte)
                // 3'b001: r_data = {24'b0, pmem_read(addr)};
                // 3'b010: r_data = {16'b0, pmem_read(addr+1), pmem_read(addr)};
                // 3'b100: r_data = {pmem_read(addr+3), pmem_read(addr+2), pmem_read(addr+1), pmem_read(addr)};
                3'b001 : r_data = pmem_read(addr,  {5'b0, rw_byte});
                3'b010 : r_data = pmem_read(addr,  {5'b0, rw_byte});
                3'b100 : r_data = pmem_read(addr,  {5'b0, rw_byte});
                default: r_data = 0;
            endcase
        end
    end


endmodule
