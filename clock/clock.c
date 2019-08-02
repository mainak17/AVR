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


void main()
{   
int i=1,c=0;
int min=0;
int sec=0;
int k=0;

	DDRD=0xFF;
	DDRC=0xFF;
	DDRB=0x0F;
	while(1)
	{	
		if((PINB&0x20)==0x00)
			{
			c=1;	
			}
		if(c==1)
		{
		            display(k,5);
					_delay_ms(1);
					display(0,6);
					_delay_ms(1);

			if((PINB&0x20)==0x00)
			{
			_delay_ms(300);
			 k++;	
			}
          
		}

		if((PINB&0x10)==0x00)
			{
			_delay_ms(300);	 
			i++;
			c=0;
			}			

if(i%2==0)
	{	for(min=0;min<=10;min++)
			{
				
			for(sec=0;sec<=9;sec++)
	 			{
			
			for(int y=0;y<250;y++)
				 {
					display(min%10,3);
					_delay_ms(1);
					display(min/10,4);
					_delay_ms(1);
					
					display(sec,1);
					_delay_ms(1);
					display(0,2);
					_delay_ms(1);

					if((min==k)&&(sec==0))
					{
					PORTB=0x02;
					}//if check 1
				if((min>k)&&(sec==0))
					{
					PORTB=0x00;
					}//if check 2
				 }//for y
				}//for sec

			
		}//for min
 } //if i check


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





