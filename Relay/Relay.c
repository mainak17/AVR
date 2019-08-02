#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include"uart.h"
void main()
{
int a,b;
DDRC=0x0F;
DDRD=0x0F;
uart_init();
while(1)
{
a=uart_read();
b=a-48;
if(b==1)
{
PORTC=0x01;
}
if(b==2)
{
PORTC=0x00;
}
}
}
