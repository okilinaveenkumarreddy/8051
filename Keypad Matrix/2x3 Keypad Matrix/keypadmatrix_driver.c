/* 2x3 keypad matrix */
#include "header.h"
#include <reg51.h>

sbit R0=P2^0;
sbit R1=P2^1;
sbit C0=P2^4;
sbit C1=P2^5;
sbit C2=P2^6;
/* 2x3 keypad matrix lookup table*/
code keypad_lookuptable[2][3]={1,2,3,4,5,6};
u8 key2x3scan(){
	u8 row,col;
	R0=R1=0;
	C0=C1=C2=1;
	while((C0&C1&C2)==1);//wait until switch press
	/* Rows checking */
	R0=0;
	R1=1;
	if((C0&C1&C2)==0)
		{
			row=0;
			goto colcheck;
	  }
	R0=1;
	R1=0;
	if((C0&C1&C2)==0)
		{
			row=1;
			goto colcheck;
		}
	colcheck:
		
		if(C0==0)
			col=0;
		else if(C1==0)
			col=1;
		else
			col=2;
		while((C0&C1&C2)==0);
	return keypad_lookuptable[row][col];
}