#include "header.h"
#define width 16

unsigned char str[]="22180 CSMT P1";
void main(){
	u8 count,remaining_chars,i;
	lcd_init();
	lcd_cmd(0x0C);//disable cursor
	count=string_len(str);
	while(1){
		lcd_cmd(0x80+i);
		lcd_string(str);
		/*display remaining left over string from starting*/
		if(i+count>=width){
			remaining_chars=width-i;
			lcd_cmd(0x80);
			lcd_string(str+(remaining_chars));
		}
		delay_ms(400);
		lcd_cmd(0x01);
		i++;
		if(i==16){
			i=0;
		}
	}
}