////blink the AL led at 1ms rate
//sfr P2=0xA0;
//sbit LED=P2^0;
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
//	LED=0;
//	delay(1000);//calling fn takes 2 mc and returning to fn also takes 2 mc
//	LED=1;
//	delay(1000);
//}
/*Byte wise Methods */ //simple method to control IO Pins
//since we have connected the LEDS to P2-0,1,2,3 
//then P2-4,5,6,7 pins are don't cares so we can write 0 or 1 for this bits

sfr P2=0xA0;
void delay(unsigned int ms){
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
	P2=0xF0;
	delay(200);//calling fn takes 2 mc and returning to fn also takes 2 mc
	P2=0xFF;
	delay(200);
}
