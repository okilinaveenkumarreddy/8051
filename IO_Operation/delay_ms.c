#include "header.h"
void delay(u16 ms){
	for(;ms>0;ms--){
		unsigned char i;
		i=250;
		while(--i);
		i=247;
		while(--i);
	}
}
