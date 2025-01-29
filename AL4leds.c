//Bitwise method of Controlling the IO Pins
//Blinking 4 LEDS at a time
sfr P2=0xA0;
sbit LED1=P2^0;
sbit LED2=P2^1;
sbit LED3=P2^2;
sbit LED4=P2^3;
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
	LED1=LED2=LED3=LED4=0;
	delay(1000);//calling fn takes 2 mc and returning to fn also takes 2 mc
	LED1=LED2=LED3=LED4=1;
	delay(1000);
}