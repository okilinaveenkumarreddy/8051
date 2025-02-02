/*Declare all the fns prototypes*/
/*io_bit_write(2,0,1); I can understand this 2,0,1
       since i wrote the program
       but another guy can't understand
      so define macros for port_num,pin_num,value    */
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
extern void lcd_integer(s32 num);
extern void lcd_float(float f);
extern void lcd_init();
extern u8 key2x3scan(void);
