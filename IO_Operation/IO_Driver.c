/*IO_Driver.c*/
//for IO write need(port num,pin num,value)
#include <reg51.h>
#include "header.h"
void io_bit_write(u8 port_num,u8 pin_num,u8 val){
	switch(port_num){
		#ifdef PORT0
		case 0:
			if(val==1)
				P0|=(1<<pin_num);
			else
				P0&=~(1<<pin_num);
			break;
		#endif
		#ifdef PORT1
		case 1:
			if(val==1)
				P1|=(1<<pin_num);
			else
				P1&=~(1<<pin_num);
			break;
		#endif
		#ifdef PORT2
		case 2:
			if(val==1)
				P2|=(1<<pin_num);
			else
				P2&=~(1<<pin_num);
			break;
		#endif	
		#ifdef PORT3
		case 3:
			if(val==1)
				P3|=(1<<pin_num);
			else
				P3&=~(1<<pin_num);
			break;
		#endif
	}
}
//for IO write need(port num,pin num)
bit io_bit_read(u8 port_num,u8 pin_num){
	bit stat;
	switch(port_num){
		case 0:
			stat=((P0>>pin_num))&1?1:0;
			break;
		case 1:
			stat=((P2>>pin_num)&1)?1:0;
			break;
		case 2:
			stat=((P2>>pin_num)&1)?1:0;
			break;
		case 3:
			stat=((P2>>pin_num)&1)?1:0;
			break;
	}
	return stat;
}