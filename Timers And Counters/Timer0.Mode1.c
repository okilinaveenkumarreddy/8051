/*Timer 0 Mode1*/
/*Generate Exact 1ms delay*/
#include "intrins.h"
#include <reg51.h>
void delay(){
	TMOD=0x01;//2mc
	TH0=0xFC;//2mc
	TL0=0x27;////2mc
	TR0=1;//1mc
	while(TF0==0);//monitor timer0 overflow :takes 2mc and takes//2mc extra to come out of that loop
	TR0=0;//1mc
	TF0=0;//1mc
	_nop_();
}
void main(){
	delay(); 
	while(1);
}