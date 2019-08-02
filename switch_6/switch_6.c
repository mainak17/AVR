#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB=0b00001111;
int c=1,d=1;
while(1)
{
	led(c);
if((PINB&0b00010000)==0x00)
{
	_delay_ms(200);
	
	
	c=c*2;
	if(c==16)
	{
	c=1;
	}
	led(c);
}
if(((PINB&0b00100000)==0x00))
{
	blink(c);
}
}
}
void blink(int pin)
{
for(int i=0;i<10;i++)
{
_delay_ms(250);
PORTB=pin;
_delay_ms(250);
PORTB=0x00;
}
}

void led(int a)
{
PORTB=a;
}
