#include "header.h"
void main(){
	u8 temp;
	lcd_init();
	lcd_cmd(0x0C);
	while(1){
		temp=key4x4scan();
		lcd_cmd(0x01);
		if(temp>9)
			lcd_data(temp+55);
		else
			lcd_data(temp+48);

	}
}