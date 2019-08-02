#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
int a=1;
void main()
{

DDRB = 0x03;
int c;
while(1)
{
led();
}
}
void led()
{

unsigned int pin;

if((PINB&0x04)==0x00)
{
_delay_ms(100);
a++;
}
if((a%2)==0)
{
pin=0x02;
}
else if((a%2)==1)
{

pin=0x01;
}


PORTB=pin;
_delay_ms(250);
PORTB=0x00;
_delay_ms(250);


}
