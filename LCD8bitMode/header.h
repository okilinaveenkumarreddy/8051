/*Declare all the fns prototypes*/
/*io_bit_write(2,0,1); I can understand this 2,0,1
       since i wrote the program
       but another guy can't understand
      so define macros for port_num,pin_num,value    */
/*ports*/
//#define PORT0 0
//#define PORT1 1
#define PORT2 2
//#define PORT3 3
/*Pin_num*/
#define SW_PIN 0
//#define SW2_PIN 7
/*values*/
//#define SET 1
//#define CLEAR 0
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long int u32;
typedef signed long int s32;
extern void io_bit_write(u8 port_num,u8 pin_num,u8 val);
extern bit io_bit_read(u8 port_num,u8 pin_num);
extern void io_byte_write(u8 port_num,u8 byte);
extern void delay_ms(u16 ms);
extern void lcd_cmd(u8 cmd);
extern void lcd_data(u8 d);
extern void lcd_string(s8 *ptr);
extern u8 string_len(s8 *s);
extern void lcd_init();
