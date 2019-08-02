#define F_CPU 16000000ul
#include <avr/io.h>
#include<util/delay.h>
#include "lcd.h"
#include "adc.h"


int main(void)
{

lcd_init();
adc_init();

while(1)
{
lcd_gotoxy(0,3);

/*lcd_cmd(0x1D);  //0x1D: right shift; 0x18:left shift
lcd_string("Shiladitya");*/

int adc= getdata(0);
lcd_showvalue(adc);

_delay_ms(250);

}






}
