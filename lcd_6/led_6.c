#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
void main()
{
unsigned char str[32];
int x=0;
char i=0x01;
lcd_init();
DDRD=0x0F;
while(1)
{
		if((PIND&0x10)==0x00)   //sw1
		{
		_delay_ms(300);
		x++;
		i<<=1;
		}
		if(i==0x20)
		{
		i=0x01;
		//x=0;

		}

		if((PIND&0x20)==0x00)   //sw2
		{
		_delay_ms(300);
		PORTD=(i>>1);
		_delay_ms(5000);
		PORTD=0x00;
		
		}

     switch(x)
	 {
      case 0:
	  lcd_gotoxy(0,0);
	  lcd_string("Press to Select");
	  lcd_gotoxy(1,0);
	  lcd_string("                 ");
	  break;
		
	  case 1:
	  lcd_gotoxy(1,0);
	  lcd_string("Cold Water");
	  break;

	  case 2:
	  lcd_gotoxy(1,0);
	  lcd_string("Milk            ");
	  break;
	  case 3:
	  lcd_gotoxy(1,0);
	  lcd_string("Tea            ");
	  break;
	  case 4:
	  lcd_gotoxy(1,0);
	  lcd_string("Coffee         ");
	  break;
	  
	}	
}
}


void TimeOut()
{
	  lcd_gotoxy(0,0);
	  lcd_string("      TIMEOUT        ");
	  lcd_gotoxy(1,0);
	  lcd_string("                     ");
	  _delay_ms(5000);

}
