#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB=0b00001111;

while(1)
{   
               
		increment();
		//led(5,100);


		
}

}


void led(int a,int b)
{
for(int i=1;i<=a;i++)
{
PORTB=0x01;
_delay_ms(b);
PORTB=0x00;
_delay_ms(b);
}
}



void increment()
{
for(int i=1;i<=10;i++)
{
  PORTB=0x08;
  _delay_ms(100);
  PORTB=0x00;

 if(i==5)
 {
  led(5,250);
 }
 _delay_ms(2000);
}
}


