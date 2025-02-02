#include "header.h"
void main(){
	u8 temp;
	lcd_init();
	lcd_cmd(0x0C);
	while(1){
		temp=key2x3scan();
		lcd_data(temp+48);
	}
}