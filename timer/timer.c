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

int min;
int hrs=0;
int secs;
 void main()
{    
	DDRD=0xFF;
	DDRC=0xFF;
	DDRB=0x0F;
	while(1)
	{
		if((PINB&0x01)==0x00)
			{
			_delay_ms(300);
			min++;
			}
			display(min,3);	
			
	/*	if((PINB&0x02)==0x00)
		{	for(int x=0;x<5;x++)
			{
			for(int i =min-1;i>=0;i--)
				{	display(i%10,3);
					_delay_ms(100);
					display(i/10,4);
					_delay_ms(100);
					for(secs=9;secs>=0;secs--)
					{	
						
						display(secs%10,1);
						_delay_ms(100);
						display(secs/10,2);
						_delay_ms(100);

					}
				}
		
		
			//PORTB=0x04;
			}
		} */

	}//while
		
	
}//main

void display(int i,int j)
{	
	
	 if(j==1)
	 {
	 	PORTC=0x01;
	 }
	 if(j==2)
	 {
	 	PORTC=0x02;
	 }
	 if(j==3)
	 {
	 	PORTC=0x04;
	 }
	 if(j==4)
	 {
	 	PORTC=0x08;
	 }
	 if(j==5)
	 {
	 	PORTC=0x10;
	 }
	 if(j==6)
	 {
	 	PORTC=0x20;
	 }

	 
	if(i==1)     
	PORTD=~(0x06);				
	if(i==2)
	PORTD=~(0x5b);
	if(i==3)
	PORTD=~(0x4f);
	if(i==4)
	PORTD=~(0x66);
	if(i==5)
	PORTD=~(0x6d);
	if(i==6)
	PORTD=~(0x7d);
	if(i==7)
	PORTD=~(0x07);
	if(i==8)
	PORTD=~(0x7f);
	if(i==9)
	PORTD=~(0x6f);
	if(i==0)
	PORTD=~(0x3f); 

}






