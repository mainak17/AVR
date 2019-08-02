#define F_CPU16000000ul
#include<avr/io.h>
#include<util/delay.h>
#include"adc.h"
#include"lcd.h"
void main()
{
lcd_init();
adc_init();
while(1)
{
int a=getdata(0);
lcd_gotoxy(0,0);
lcd_showvalue(a);

}
}
