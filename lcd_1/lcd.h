/***************************************************************************************************************************************************
HEADER:LCD118010.h 
****************************************************************************************************************************************************

*COPYRIGHT(c): Technophilia embedded systems.
*AUTHOR: Technophilia
*Target system: AVR devlopment board s/n-118010
*Manufacturer: Technophilia 
*Microcontroller: ATmega-8
*Clock: 12MHz
*COMPILER: WinAVR
*last modified 09/09/2011
	

DESCRIPTION: 
	This header files have implementation of some common finctions of the LCD.
	Include this header file in your C code. Call the lcd_init() function before
	calling any other functions to initialize the lcd.


	lcd_init() ----- Call the lcd_init() function before calling any other functions
			  to initialize the lcd.
	lcd_cmd() ------ This function is used to give any command instructions to the
			  LCD. For e.g lcd_cmd(0x01) will give the clear command.
	lcd_char() ----- This function will display a single character on the LCD display.
			  For example lcd_char(0x61) will display A. Again lcd_char('b')
			  will display b.
	lcd_string()---- This function will display a string. An example of this would be
			  like lcd_string("This is AVR")
	lcd_showvalue()- This will show a 3-digit decimal value on the LCD. For example if
			  we give lcd_showvalue(0xFF) then 255 will be displayed.
	lcd_gotoxy()--- Will set the cursor at a particular position on of the LCD.
			  So lcd_gotoxy(1,4) will set the cursor at the 2d row 3rd column
			  row and column address are starts from(0,0)
	lcd_clear()---To clear the LCD
	
LCD connection Details

Daata mode--------4bit

RS----------------PORTB 4
RW----------------Ground
E-----------------PORTB 5
D0----------------open
D1----------------open
D2----------------open
D3----------------open
D4----------------PORTB 0
D5----------------PORTB 1
D6----------------PORTB 2
D7----------------PORTB 3	
	
*/

#ifndef _LCD_H_
#define _LCD_H_


unsigned char k=0,j=0;
unsigned char save=0;

void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void latch(void);
void delay_ns_lcd(unsigned char tim);
void lcd_char(unsigned char single);
void lcd_string(unsigned char str[32]);
void lcd_showvalue(unsigned char num);
void lcd_gotoxy(unsigned char row,unsigned char column);
void delay_ms_lcd(unsigned int ms);
void lcd_clear();

void lcd_init(void)	//init the lcd
{	
  
	DDRB=0x3F;
	delay_ms_lcd(20);

	
	PORTB=0x03;		
	latch();
	delay_ms_lcd(5);
	PORTB=0x03;
	latch();
	delay_ms_lcd(1);
	PORTB=0x03;
	latch();
	delay_ms_lcd(1);
	PORTB=0x02;			//Enable 4 bit mode
	latch();
	delay_ms_lcd(5);		
	
  	   
	lcd_cmd(0x28);		//Set interface 4 bit 2 line
	delay_ms_lcd(1);
	
	lcd_cmd(0x08);		//Enable display/cursor
	delay_ms_lcd(1);
	
	lcd_cmd(0x01);		//clear the display
	delay_ms_lcd(1);
	
	lcd_cmd(0x06);		//Set cursor move, Move cursor right
	delay_ms_lcd(1);
	   
		
	lcd_cmd(0X0C);		//Turn on display
	delay_ms_lcd(2);

}

void latch(void)
{
PORTB&=~0x20;
delay_ns_lcd(200);  
PORTB|=0x20;
delay_ns_lcd(200);  
PORTB&=~0x20;
}

void delay_ns_lcd(unsigned char tim)
{
	for(j=0;j<tim;j++)
	{
		for(k=0;k<11;k++)
		{};
	}
}

void lcd_cmd(unsigned char cmd)
{   unsigned char cmd_temp=cmd;
	PORTB&=~0x30;
	cmd_temp>>=4;
	PORTB=((cmd_temp & 0x0F));			
	latch();
	PORTB=(cmd & 0x0F);	
	latch();
}


void lcd_char(unsigned char single)
{
    unsigned char temp_single=single;
	temp_single>>=4;
	PORTB=0x10;
	PORTB=0x00;
	PORTB=(temp_single & 0x0F)|0x10;						
	latch();
	PORTB=(single & 0x0F)|0x10;
	latch();
}

void lcd_string(unsigned char *str)
{
	unsigned char k=0;

		while(*str!='\0')	//Till null character is encountered
		{
			lcd_char(*str);
			str++;
		}
}



void lcd_showvalue(unsigned char num)	//prints the decimal 3digit value of num
{
	unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));
	
	lcd_char(H+48);
	lcd_char(T+48);
	lcd_char(O+48);
}

void lcd_gotoxy(unsigned char row,unsigned char column)			//move cursor to the specified position
{
   if(row==0)
    {
	 lcd_cmd(0x80+column);
	}
   else if(row==1)
	{
	 lcd_cmd(0xC0+column);	
	}	
}


void delay_ms_lcd(unsigned int ms)
{
	int i;

	while (ms-- > 0)
	{
		
		for (i = 0; i < 3276; ++i)
			asm("nop");
	}
}

void lcd_clear()
{
 lcd_cmd(0x01);
}
#endif 
