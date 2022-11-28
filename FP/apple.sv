module apple (

		input         Reset, frame_clk,
		input  [31:0] a_loc, 
		input  [9:0]  BallX, BallY,
		output        cut,
		output [9:0]  AppleX, AppleY
);

parameter A_X_Min = 80;
parameter A_X_Max = 560;
parameter A_Y_Min = 120;
parameter A_Y_Max = 320;

always_ff @ (posedge frame_clk) begin



end

assign appleX = a_loc[25:16];
assign appleY = a_loc[9:0];

endmodule 