////Bitwise method of Controlling the IO Pins
////Blinking 4 LEDS at a time
//sfr P2=0xA0;
//sbit LED1=P2^0;
//sbit LED2=P2^1;
//sbit LED3=P2^2;
//sbit LED4=P2^3;
//void delay(unsigned int ms){
//	for(;ms>0;ms--){
//		unsigned char i;
//		i=250;
//		while(--i);
//		i=247;
//		while(--i);
//	}
//}
//void main()
//{ //pass the delay needed in ms
//	LED1=LED2=LED3=LED4=0;
//	delay(1000);//calling fn takes 2 mc and returning to fn also takes 2 mc
//	LED1=LED2=LED3=LED4=1;
//	delay(1000);
//}
/*Byte wise Methods */ //simple method to control IO Pins
//since we have connected the LEDS to P2-0,1,2,3 
//then P2-4,5,6,7 pins are don't cares so we can write 0 or 1 for this bits

sfr P2=0xA0;
void delay(unsigned char ms){
	for(;ms>0;ms--){
		unsigned char i;
		i=250;
		while(--i);
		i=247;
		while(--i);
	}
}
void main()
{ //pass the delay needed in ms
//	P2=0xF0;
//	delay(200);//calling fn takes 2 mc and returning to fn also takes 2 mc
//	P2=0xFF;
//	delay(200);
	P2^=0x0F; //toggle method
	delay(200);
}
