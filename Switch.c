/*Write an Emb C code to display the Status of LED using AL LED*/
sfr P2=0xA0;
sfr P1=0x90;
sbit LED=P2^0;
sbit SW=P1^7;
void main(){
//	while(1){
//	if(SW==0){//switch pressed
//		LED=0;//led ON
//	}
//	else//switch not pressed
//		LED=1; //led off
//	}
//	/*or*/
	LED=1;
	while(SW==1);//wait until switch pressed
	LED=0;
	while(SW==0);//wait until switch released
	//Assignment
//	while(1){
//		unsigned char i=0;
//		for(;i<8;i++){
//			while(SW==1);//wait until switch not pressed 
//			P2=~(1<<i);//if SW pressed blink the leds in left shift
//			while(SW==0);//wait until Switch released
//		}
//	}
}