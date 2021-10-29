module add2b (
    input [1:0] x,y,
    input ci,
    output [1:0] z,
    output co

);

    wire ci;
    FAC i0(.x(x[0]), .y(y[0]), .ci(ci), .z(z[0]), .co(ci));
    FAC i1(.x(x[1]), .y(y[1]), .ci(ci), .z(z[1]), .co(co));

endmodule

module add2b_tb;

    reg [1:0] x, y;
    reg ci;
    reg [1:0] z;
    reg co;

    add2b cut(.x(x), .y(y), .ci(ci), .z(z), .co(co));

    integer k;
    initial begin
      $display("Time\tx\ty\tci\tco\tz");
      $monitor("%3t\t%1d\t%1d\t%b\t%b\t%1d", $time, x, y, ci, co, z);
      for(k = 0; k < 32; k = k + 1) begin
        {x, y, ci} = k;
        #10 ;
      end
    
    end
endmodule


