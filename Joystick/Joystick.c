#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include"adc.h"
#include"lcd.h"
void main()
{
int Rx,Ry,sw=0;
unsigned int i;
i=0x01;
//DDRC=0x0F;
DDRB=0x0F;
DDRD=0XFF;
PORTD=0x10;

lcd_init();
adc_init();

while(1)
{
	Rx=getdata(0);
	_delay_ms(200);
	lcd_gotoxy(0,0);
	lcd_showvalue(Rx);
	lcd_gotoxy(1,0);
	lcd_string("Rx");


	Ry=getdata(1);
	_delay_ms(200);
	lcd_gotoxy(0,5);
	lcd_showvalue(Ry);
	lcd_gotoxy(1,5);
	lcd_string("Ry");



	if(Rx<120)
	{
			PORTD=0x11;
	}
	if(Rx>130)
	{		
			PORTD=0x12;
	}
	
	if(Ry<120)
	{		
			PORTD=0x14;
	}
	if(Ry>130)
	{		
			PORTD=0x18;
	}
	
	if((PIND&0x10)==0x00)
	{	
			PORTD=0x1F;	
	}
	if(((PIND&0x10)==0x10) && (Rx>120) && (Rx<130) && (Ry>120) && (Ry<130))
	{
	PORTD=0x10;	
	}
	
	
}
}

