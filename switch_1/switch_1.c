#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRB = 0b00000001;
DDRD = 0b00000000;
//int a = (PIND & 0x01);
while(1)
{
if ((PIND & 0x01)== 0)
{

PORTB = 0x01;
//_delay_ms(10);



}
if ((PIND & 0x01) == 1)
{

PORTB = 0x00;
//_delay_ms(10);



}



}
}
