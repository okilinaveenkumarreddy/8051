/* 4x4 keypad matrix */
#include "header.h"
#include <reg51.h>

sbit R0=P2^0;
sbit R1=P2^1;
sbit R2=P2^2;
sbit R3=P2^3;

sbit C0=P2^4;
sbit C1=P2^5;
sbit C2=P2^6;
sbit C3=P2^7;
/* 2x3 keypad matrix lookup table*/
code keypad_lookuptable[4][4]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
u8 key4x4scan(){
	u8 row,col;
	R0=R1=R2=R3=0;
	C0=C1=C2=C3=1;
	while((C0&C1&C2&C3)==1);//wait until switch press
	/* Checking Rows Individually*/
	//ROW 0
	R0=0;
	R1=1;
	R2=1;
	R3=1;
	if((C0&C1&C2&C3)==0)
		{
			row=0;
			goto colcheck;
	  }
	//ROW 1
	R0=1;
	R1=0;	
	R2=1;
	R3=1;
	if((C0&C1&C2&C3)==0)
		{
			row=1;
			goto colcheck;
		}
	//ROW 2
	R0=1;
	R1=1;	
	R2=0;
	R3=1;
	if((C0&C1&C2&C3)==0)
		{
			row=2;
			goto colcheck;
		}
	//ROW 3
	R0=1;
	R1=1;	
	R2=1;
	R3=0;
	if((C0&C1&C2&C3)==0)
		{
			row=3;
			goto colcheck;
		}	
	colcheck:
		if(C0==0)
			col=0;
		else if(C1==0)
			col=1;
		else if(C2==0)
			col=2;
		else
			col=3;
		while((C0&C1&C2)==0);
	return keypad_lookuptable[row][col];
}