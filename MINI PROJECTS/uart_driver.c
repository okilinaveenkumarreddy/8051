#include <reg51.h>
#include "header.h"
void uart_tx(u8 byte){
	SBUF=byte;
	while(TI==0);
	TI=0;
}
u8 uart_rx(void){
	while(RI==0);
	RI=0;
	return SBUF;
}
void uart_application(u8 cmd){
	switch(cmd){
		case 'A':io_bit_write(PORT2,LED1_PIN,CLEAR);break;//led1 on
		case 'B':io_bit_write(PORT2,LED1_PIN,SET);break;//led1 off
		case 'C':io_bit_write(PORT2,LED2_PIN,CLEAR);break;//led2 on
		case 'D':io_bit_write(PORT2,LED2_PIN,SET);break;//led2 off
		case 'X':io_bit_write(PORT2,LED1_PIN,CLEAR);
						 io_bit_write(PORT2,LED2_PIN,CLEAR);
						 break;//BOTH LEDS on
		case 'Y':io_bit_write(PORT2,LED1_PIN,SET);
						 io_bit_write(PORT2,LED2_PIN,SET);
						 break;//BOTH LEDS OFF	
	}
}
void uart_init(u16 baud){
	SCON|=0x50;//Selected Universal Mode and receive Enabled
	TMOD|=0x20;//Timer1 in Mode2
	switch(baud){
		case 7200:TH1=252;break;
		case 9600:TH1=253;break;
		case 14400:TH1=254;break;
		case 28800:TH1=255;break;
		case 57600:TH1=255;PCON|=(1<<7);break;//set the SMOD bit of PCON
		default:TH1=253;	
	}
	TR1=1;//start Timer
}