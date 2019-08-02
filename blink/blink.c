#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>

int main(void)
{
unsigned char i;
DDRB=0b00001111;
while(1)
{

	for(i= 0x01;i!=0x10;i++)
	{
		PORTB=i;
		_delay_ms(500);
	}
}
}
