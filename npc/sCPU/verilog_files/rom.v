module rom(
    input [31:0] addr, // pc
    output reg [31:0] inst
);

    import "DPI-C" function int pmem_read(input int raddr, input byte len);
    import "DPI-C" function void nemu_trap();
    // reg [7:0] ROM[(1 << 15) - 1 : 0];

    // initial begin
    //     for (int i = 0; i < (1 << 15) -1; i++) ROM[i] = 0;
    // end

    always @(*) begin
        // inst[7:0] = ROM[addr];
        // inst[15:8] = ROM[addr+1];
        // inst[23:16] = ROM[addr+2];
        // inst[31:24] = ROM[addr+3];
        inst = pmem_read(addr, 4);
        if (inst == 32'h00100073) nemu_trap();
    end

endmodule
