#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include"uart.h"
void main()
{
int a,b;
DDRC=0x0F;
DDRD=0xFF;
uart_init();
while(1)
{
a=uart_read();
b=a-48;
if(b==1)
{
PORTD=0xF0;
PORTC=0x00;
}
if(b==2)
{
PORTD=0x00;
PORTC=0x0F;
}

if(b==3)
{
PORTD=0x00;
PORTC=0x00;
}
}
}
