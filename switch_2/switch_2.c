#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB = 0b00000011;
int a=0;
while(1)
{
if(((PINB&0b00000100)==0x00) || ((PINB&0b00001000)==0x00)) 
{
_delay_ms(200);
a++;

if(a==20)
{
a=0;
}
}
if((a%2)==0)
PORTB=0x00;
else
PORTB=0x01;
PORTB=0x02;
}
}

