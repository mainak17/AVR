#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
void main()
{
	DDRB=0b00001111;
	while(1)
	{
		led1(1,500);
		led2(2,500);
		led3(3,500);
		led4(4,500);
	}


}
void led1(int c,int t)
{ int i=0;
		while(i!=c)
		{
			PORTB=0b00000001;
			_delay_ms(t);
			PORTB=0x00;
			_delay_ms(t);
			i++;
		}
	
}


void led2(int c,int t)
{ int i=0;

		while(i!=c)
		{
			PORTB=0b00000010;
			_delay_ms(t);
			PORTB=0x00;
			_delay_ms(t);
			i++;
		}
	
}

void led3(int c,int t)
{ int i=0;

		while(i!=c)
		{
			PORTB=0b00000100;
			_delay_ms(t);
			PORTB=0x00;
			_delay_ms(t);
			i++;
		}
	
}

void led4(int c,int t)
{ int i=0;

		while(i!=c)
		{
			PORTB=0b00001000;
			_delay_ms(t);
			PORTB=0x00;
			_delay_ms(t);
			i++;
		}
	
}
