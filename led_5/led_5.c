#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
unsigned int j=0x01;
int i;
void main()
{
	DDRB=0b00001111;
    
	while(1)
	{
	for(i=5;i<=20;i=i+5)
	{
	
	 led(i);
	
	 
	}
		
	}

}


void led(int a)
{
	int i;
	for(i=0;i<a;i++)
	{
	PORTB=j;
	_delay_ms(200);
	PORTB=0x00;
	_delay_ms(200);

	}
	if(i==a)
	j<<=1;
	if(i==20)
	 j=0x01;
}

