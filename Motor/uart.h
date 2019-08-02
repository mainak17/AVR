/*uart.h
*******************************************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............13th Sept 2011
Author:.............Technophilia R&D team
Organization:.......Technophilia Syestems
compiler:...........WinAVR

Description:

	This header file enables uart communication feature between two devices.
	Include this header file in your C code. 
	Call the uart_init() function before calling any other functions to initialize the uart.
	
Functions:

	uart_init();	Call this function before calling any other functions to initialize 
					the uart communication.
	uart_char();  	This function will transmit a single character on the UART.
					For e.g. uart_char(0x61); will display A. 
					Again uart_char('b'); will display b.
	uart_string();	This function will display a string. 
					An e.g. of this would be like uart_string("This is AVR");
	uart_num();		This will show a 3-digit decimal value on the display
					For e.g. uart_num(35); will displkay 035
	uart_read();	This will show a 3-digit decimal value on the Display. 
					For e.g. if we give uart_read(x); then x value will be displayed.

*******************************************************************************************/

#ifndef _UART_H_
#define _UART_H_

void uart_init()             //void uart_init(uint16_t ubrr_value)
{

   //Set Baud rate

   UBRRL = 103;      //UBRRL = ubrr_value;
   UBRRH = (103>>8);

   /*Set Frame Format


   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit

   >> char size 8

   */

   UCSRC=(1<<URSEL)|(3<<UCSZ0);


   //Enable The receiver and transmitter

   UCSRB=(1<<RXEN)|(1<<TXEN);


}

void uart_char(unsigned char uchar)
{
	UDR=uchar;
	while((UCSRA&0x40)==0x00);
	uart_delay(1000);       //edited(1000 org)
}
 
void uart_string(const unsigned char *ustring)
{
	while ( *ustring )
	{
		UDR=*ustring++;
		while((UCSRA&0x40)==0x00);
		uart_delay(1000);
	}
}
 
void uart_num(uint16_t num)
{
    unsigned char TH=0,H=0,T=0,O=0;

	TH=num/1000;
	H=(num - (TH*1000))/100;
	T=(num - (TH*1000)-(H*100))/10;
	O= num - (TH*1000) - (H*100)-(T*10);
	
	
	uart_char(TH+48);
	uart_char(H+48);
	uart_char(T+48);
	uart_char(O+48);	
}
 
unsigned char uart_read()
{
	while((UCSRA&0x80)==0x00);
	return UDR;
}
 
void uart_delay(unsigned int delaytime)
{
	unsigned int dc;
	for(dc=0;dc<=delaytime;dc++)
	{
		asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		asm("nop");asm("nop");asm("nop");asm("nop");
	}
}

#endif 
