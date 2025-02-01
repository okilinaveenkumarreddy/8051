#include <reg51.h>
#include "header.h"
/*define control pins*/
sbit RS=P3^4;
sbit RW=P3^5;
sbit EN=P3^6;
void lcd_cmd(u8 cmd){
	P0=cmd; 
	RS=0;//cmd to lcd
	RW=0;//write operation
	EN=1;
	delay_ms(2);
	EN=0;
}
void lcd_data(u8 d){
	P0=d; 
	RS=1;//dataa to lcd
	RW=0;//write operation
	EN=1;
	delay_ms(2);
	EN=0;
}
void lcd_string(s8 *ptr){
	while(*ptr!=0){
		lcd_data(*ptr);
		ptr++;
	}
}
u8 string_len(s8 *s){
	u8 c=0;
	while(*s!='\0'){
		c=c++;
		s++;
	}
	return c;
}
void lcd_init(){
	/*Note:give 0x02 cmd in starting of lcd_init*/
	lcd_cmd(0x02);//set cursor to home position without clearing the lcd
	lcd_cmd(0x38);//8bit mode
	lcd_cmd(0x01);//clear lcd
	lcd_cmd(0x0E);//cursor on
}