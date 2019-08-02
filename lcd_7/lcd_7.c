#define F_CPU 16000000ul
#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"


void main()
{
int x=0;
int flag=0;
char i=0x01;
lcd_init();
DDRD=0x0F;
while(1)
{
  lcd_gotoxy(1,13);
  lcd_showvalue(x);
		if((PIND&0x10)==0x00)   //sw1
		{
			_delay_ms(300);
			x++;
			i<<=1;

			if(i==0x20)
			{
	 		i=0x01;
			x=0;
			}
	     flag=1;
		}


		if(flag==1)
		{
				for(int i=0;i<=200;i++)
				{
						if((PIND&0x20)==0x00)
						{
						 PORTD=(i>>1);
						 _delay_ms(5000);
						 PORTD=0x00;
		 
						 }
						 _delay_ms(25);
				}
		 x=0;
		 i=0x01;
		 flag=0;
		
		}

		

		
		

     switch(x)
	 {
      case 0:
	  lcd_gotoxy(0,0);
	  lcd_string("Press to Select");
	  lcd_gotoxy(1,0);
	  lcd_string("                 ");
	  //TimeOut();
	  break;
		
	  case 1:
	  lcd_gotoxy(1,0);
	  lcd_string("Cold Water");
	  //TimeOut();
	  break;

	  case 2:
	  lcd_gotoxy(1,0);
	  lcd_string("Milk            ");
	  //TimeOut();
	  break;
	  
	  case 3:
	  lcd_gotoxy(1,0);
	  lcd_string("Tea            ");
	  //TimeOut();
	  break;
	  case 4:
	  lcd_gotoxy(1,0);
	  lcd_string("Coffee         ");
	  //TimeOut();
	  break;
	  
	}	
}
}


void TimeOut()
{	 
	  for(int z=0;z<=500;z++)
	    {
			_delay_ms(10);
			if((PIND&0x20)==0x00)
			{
				return(1);
				break;
			}
		    if(z==500)
			{
				return(0);
				break;
			}
		}

}
