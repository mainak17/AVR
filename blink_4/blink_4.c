#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
void main()
{	int pin;
	DDRB=0b00001111;
	while(1)
	{	//for(pin=1;pin<5;pin++)
		led(1,5,500);
		PORTB=0x08;
		_delay_ms(1000);
		PORTB=0x00;
		
	}


}
void led(int pin,int c,int t)
{ 
	int i=0;
	while(i!=c)
	{
			PORTB=pin;
			_delay_ms(t);
			PORTB=0x00;
			_delay_ms(t);
			i++;
	}
	
}

/*int PIN(int pin)
{
	for (unsigned int j=0x01;j!=0x10;j<<=1)
	//PORTB=j;
	return j;

}*/
