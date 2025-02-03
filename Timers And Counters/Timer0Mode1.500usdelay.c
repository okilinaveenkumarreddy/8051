/*Timer 0 Mode1*/
/*Generate Exact 500us delay*/
#include "intrins.h"
#include <reg51.h>
sbit SQRW=P1^0;
void delay(){
	TMOD=0x01;//2mc
	TH0=0xFE;//2mc
	TL0=0x1B;////2mc
	TR0=1;//1mc
	while(TF0==0);//monitor timer0 overflow :takes 2mc and takes//2mc extra to come out of that loop
	TR0=0;//1mc
	TF0=0;//1mc
	_nop_();
}
void main(){
	while(1){
		SQRW=0;
		delay();
		SQRW=1;
		delay();
	
		
}