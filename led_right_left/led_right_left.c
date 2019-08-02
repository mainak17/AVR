#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB=0b00001111;

while(1)
{
left();
right();
}
}
void left()
{

for(unsigned int i=0x08;i!=0x00;i>>=1)
{
	PORTB=i;
	_delay_ms(100);
	PORTB=0x00;
	_delay_ms(100);

 }
}

void right()
{
for(unsigned int i=0x01;i!=0x10;i<<=1)
	{
	PORTB=i;
	_delay_ms(100);
	PORTB=0x00;
	_delay_ms(100);
	
	}

}

