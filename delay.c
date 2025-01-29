//generating Exact 1milli second Delay using EMB C
#include <reg51.h>
void delay(void){
	unsigned char i;
	i=250;
	while(--i);
	i=247;
	while(--i);
}
void main()
{
	delay();//calling fn takes 2 mc and returning to fn also takes 2 mc
	while(1);
}