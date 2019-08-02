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

int min=0;
int hrs=0;
int sec=0;
int x=0;
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
			x=x+10;				//increment for min
			}

		for(int c=0;c<300;c++)	//for showing  value of min at 0 position
			{
			display(x/10,1);
			display(0,2);
			//_delay_ms(200);
			break;
			}		

		for(sec=x;sec>0;sec--)
	 {
			min=sec%10;
		 	hrs=min%10;
			 
			 for(int y=0;y<166;y++)
			 {
			    
				display(sec%10,1);
				_delay_ms(1);
				display(sec/10,2);
				_delay_ms(1);

				display(min%10,3);
				_delay_ms(1);
				display(min/10,4);
				_delay_ms(1);

				display(hrs%10,5);
				_delay_ms(1);
				display(hrs/10,6);
				_delay_ms(1);
			}//for

 
	


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





