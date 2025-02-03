/*Counter0 Mode1*/
#include "header.h"
#include <reg51.h>
void main(){
	u16 count;
	TMOD=0x05;
	TH0=0;
	TL0=0;
	TR0=1;
	while(TF0==0){
		count=TH0*256+TL0;
	}
	TR0=0;
	TF0=0;
	while(1);
}