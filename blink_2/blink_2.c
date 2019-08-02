#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
void main()
{
	DDRB=0b00001111;
	//unsigned int i;
	int c=1;
	while(1)
	{
		blink();
	}


}
void blink()
{
	int c;
	int y=2; 
	unsigned int i;

		for(i=0x01;i!=0x10;i<<=1)
		{
			for(c=1;c<y;c++)
			{
			PORTB=i;
			_delay_ms(500);
			PORTB=0x00;
			_delay_ms(500);
			}
			y++;
		}
}

