#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB=0b00001111;
int c=0;
while(1)
{
if((PINB&0b00010000)==0x00)
{
	_delay_ms(200);
	c++;
	if(c>4)
	{
	c=0;
	}
	
}
if(((PINB&0b00100000)==0x00))
{
if(c==1)
{
for(int i=0;i<10;i++)
{
_delay_ms(250);
PORTB=0x01;
_delay_ms(250);
PORTB=0x00;
}
}

if(c==2)
{
for(int i=0;i<10;i++)
{
_delay_ms(250);
PORTB=0x02;
_delay_ms(250);
PORTB=0x00;
}
}

if(c==3)
{
for(int i=0;i<10;i++)
{
_delay_ms(250);
PORTB=0x04;
_delay_ms(250);
PORTB=0x00;
}
}
if(c==4)
{
for(int i=0;i<10;i++)
{
_delay_ms(250);
PORTB=0x08;
_delay_ms(250);
PORTB=0x00;
}
}
}
}
}

