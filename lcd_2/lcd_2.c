#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
void main()
{
DDRD=0b00001111;
int c=1,d=1;
lcd_init();
while(1)
{
    lcd_gotoxy(0,0);
	lcd_showvalue(d);

if((PIND&0b00010000)==0x00)
{
	_delay_ms(200);
	c=c*2;
	d=d+1;
	if(c==16)
	{
		c=1;
		d=1;
	}
	lcd_gotoxy(0,0);
	lcd_showvalue(d);
	
}
if((PIND&0b00100000)==0x00)
{
 lcd_gotoxy(1,0);
 lcd_string("Blink Led :");
 lcd_showvalue(d);
 led(c);
}
}
}

void led(char a)
{
 for(int i=1;i<=10;i++)
 {
   PORTD=a;
   _delay_ms(500);
   PORTD=0;
   _delay_ms(500);

 }

}

//void led(int a)
//{
//lcd_showvalue(a);
//}
