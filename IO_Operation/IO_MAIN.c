/*IO_MAIN.c*/
#include "header.h" //including prototypes defined header file
void main(){
	while(1){
		//for IO write need(port num,pin num,value)
		io_bit_write(PORT2,LED_PIN,SET);
		while(io_bit_read(PORT2,SW_PIN)==1);
		io_bit_write(PORT2,LED_PIN,CLEAR);
		while(io_bit_read(PORT2,SW_PIN)==0);
	}
}