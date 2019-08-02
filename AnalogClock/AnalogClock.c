// 		 PD7  PD6  PD5 PD4  PD3 PD2  PD1  PD0
//  	  h    g	f   e    d   c   b     a
// 1->    0	   0    0	0	 0   1   1     0   0x06   	 	
// 2->	  0    1	0   1    1   0   1     1   0x5b  
// 3->	  0    1    0   0    1   1   1     1   0x4f
// 4->	  0	   1	1	0	 0	 1	 1	   0   0x66 
// 5->	  0    1	1	0	 1	 1   0	   1   0x6d    
// 6->	  0	   1	1	1	 1	 1	 0	   1   0x7d
// 7->	  0	   0    0   0    0   1   1     1   0x07
// 8->	  0    1    1   1    1   1   1     1   0x7f
// 9->	  0    1	1	0	 1	 1	 1     1   0x6f
// 0->	  0	   0    1   1    1   1   1     1   0x3f




#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include"adc.h"
#include"lcd.h"

void main()
{   
int i,s;
int clock;
int min;
int sec;
int x;
DDRB=0xFF;
//DDRC=0x0F;
DDRD=0x0F;
adc_init();
lcd_init();

while(1)
{


	
	for(min=0;min<=5;min++)
	{
		
		for(sec=0;sec<10;sec++)
		{
			for(int time=0;time<=100;time++)
			{
			//
			i=getdata(5);
lcd_gotoxy(0,0);
//_delay_ms(50);
lcd_showvalue(i);
lcd_gotoxy(1,0);
x=(0.04*i);
lcd_showvalue(x);
lcd_gotoxy(0,4);
lcd_string("ALARM");

lcd_gotoxy(0,11);
lcd_showvalue(x);

lcd_gotoxy(0,15);
lcd_string("M");

s=getdata(4);	
if(s<30)
{
clock=0;
_delay_ms(300);
clock++;
}
			//
			lcd_gotoxy(1,5);
			lcd_showvalue(min);
			_delay_ms(5);

			lcd_gotoxy(1,8);
			lcd_char(':');
			
			lcd_gotoxy(1,10);
			lcd_showvalue(sec);
			_delay_ms(5);

			if((min==x))
			{
				PORTD=0x01;
			}
			if((min>x))
			{
				PORTD=0x00;
			}

			}

		}//sec for
	}//min for
	clock=0;	

	

}//while
		
	
}//main


