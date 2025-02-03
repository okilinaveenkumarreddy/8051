/*Remotely controlling devices from Serial Terminal...
   Decives are connected to 8051 Target Board.c*/
	 /*I have connected the target board to PC and
	 I will be giving the commands from serial terminal to control the devices which are connected to Target Board
	 we can use any commands but those commands should be unique
	 here i used A,B,C,D,X,Y*/
#include "header.h"
void main(){
	u8 temp;
	uart_init(9600);
	while(1){
		temp=uart_rx();
		uart_application(temp);
	}
}