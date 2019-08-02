#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
void main()
{
int c=0;
lcd_init();
while(1)
{
if((PIND&0x01)==0x00)
{
_delay_ms(300);
c++;
}
lcd_gotoxy(0,5);
//lcd_string("Hello AVR");
lcd_showvalue(c);
}
}
