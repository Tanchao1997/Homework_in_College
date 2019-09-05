`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/05/14 22:45:12
// Design Name: 
// Module Name: lightcontrol
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module lightcontrol(
    input clk,
    input reset,
    input run,
    output [7:0]led
    );
    wire clk_out;
    wire state;
	
    clk_divider divder(
    .clk(clk),
    .reset(reset),
    .clk_out(clk_out)
    );
    
    controller cler(
        .run(run),
        .reset(reset),
        .clk(clk),
        .state(state)
    );
    
    shower my_shower(
        .clk(clk_out),
        .reset(reset),
		.run(run),
        .led(led)
    );

endmodule

module clk_divider(
    input clk,
    input reset,
    output reg clk_out
);

parameter count_limit = 499999;
reg [31:0] count;

always @(posedge clk or posedge reset)
begin
    if(reset)begin
        count <= 0;
        clk_out <= 0;
    end
    else
        if(count == count_limit)begin
            count <= 0;
            clk_out <= !clk_out;
        end
        else begin
            count <= count + 1;
        end
end
endmodule

module controller(
    input run,
    input reset,
    input clk,
    output reg state
);

parameter Running = 1'b1;
parameter STOP = 1'b0;

reg state,nextstate;

always @(posedge clk or posedge reset)
begin
    if(reset)
        state <= STOP;
    else
        state <= nextstate;
end

always @(*)
begin
    if(state == STOP)begin
        if(reset)begin
            nextstate = STOP;
            state = STOP;
        end
        else begin
        if(run)begin
            nextstate = Running;
            state = Running;
            end
          end
       end
    else begin
        if(run)begin
            nextstate = Running;
            state = Running;
        end
        else begin
        if(reset)begin
            nextstate = STOP;
            state = STOP;
            end
        end
    end
end
endmodule


module shower(
    input clk,
    input reset,
    input run,
    output reg [7:0]led
);
reg flag=1;
reg [3:0]count;
parameter[3:0] delay=4'd0100;

always@(posedge clk or posedge reset)
	begin
		if(reset)  
			count<=0;//assign
		else if(count==delay)
			count<=0;//assign
		else
			count<=count+1;
	end
always@(posedge clk or posedge reset)
	begin
		if(reset) begin
			led<=8'b1111_1111;//from the first one
			end
		else if(run) begin
			led<=8'b0000_0001;
			end
		else 
			begin
				if(flag==1) begin
					if(led==8'b0111_0000) begin
						flag<=0;
					end
					else if(count==delay) begin
						led<={led[6:0],led[7]}; end
					else begin
						led<=led; end			
				end
				else
				begin
					if(led==8'b0000_1110) begin
						flag<=1;
					end
					else if(count==delay) begin
						led<={led[0],led[7:1]}; end
					else begin
						led<=led; end			
				end
			end
	end

endmodule
