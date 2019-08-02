#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
#include <string.h>

char a[10]={'h','e','l','l','o'};

void main()
{

lcd_init();
while(1)
{

for(int i=0;i<5;i++){
lcd_gotoxy(0,0);
lcd_char(a[i]);
_delay_ms(1000);
}
}
}
