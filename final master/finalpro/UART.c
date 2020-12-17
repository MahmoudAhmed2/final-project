/*
 * finalpro.c
 *
 * Created: 12/5/2020 10:07:15 AM
 * Author : Mahmoud
 */ 
#include <avr/io.h>
#include "reg.h"
#include "STD.h"
#include "DIO.h"
#include "UART.h"

#define CPU_FREQ 16000000UL

void UART_vInit(unsigned long baud)
{
	unsigned short ubrr;
		
	/*1 - Choose baud rate that will be used by sender and receiver by writing to UBRRL/UBRRH*/
	ubrr =  ( (CPU_FREQ/ (16*baud)) - 1);
		
	UBRRL = (char) ubrr;
	UBRRH = (char) (ubrr >> 8);
	
	/*3 - Choose number of data bits to be sent from UCSRC We will work with 8 bits.*/
	UCSRC = (1<<URSEL)|(1<<UCSZ0) | (1<<UCSZ1);

	UCSRB = (1<<RXCIE);
	
	/*2 - Enable UART Sender & Receiver*/
	UCSRB |= (1<<TXEN) | (1<<RXEN);
}

void UART_vtransmit(unsigned char val)
{
	/*Wait for Transmit buffer to be empty*/
	while( (UCSRA & (1<<UDRE)) == 0 )
	{
		
	}
	
	/*Put data to transmit buffer*/
	UDR = val;
}
unsigned char UART_Vreceive(void)
{
	while(!((UCSRA) & (1<<RXC)));                  // wait while data is being received
	return UDR;                                   // return 8-bit data
}
/*The function is declared to transmit string.*/
void usart_string_transmit(char *string)
{
	while(*string)
	UART_vtransmit(*string++);
}
/*The function is declared to receive string.*/
char *usart_string_receive(char *receive_string,uint8 terminating_character)
{
	int i,temp=0;
	for(i=0;;i++)
	{
		*(receive_string+i)=UART_Vreceive();
		if(*(receive_string+i)==terminating_character)
		break;
		else
		temp++;
	}
	*(receive_string+temp)='\0';
	return receive_string;
}


