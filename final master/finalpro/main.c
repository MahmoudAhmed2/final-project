/*
 * finalpro.c
 *
 * Created: 12/5/2020 10:07:15 AM
 * Author : Mahmoud
 */ 

#include <math.h>
#define F_CPU   16000000UL

#include <util/delay.h>
#include "DIO.h"
#include "STD.h"
#include "reg.h"
#include "UART.h"
#include "spi.h"
#include <avr/io.h>

int main(void)
{
  
  SPI_INIT_MASTER();
  UART_vInit(9600);
  
  char data=1;
  char *string1="hello :)\r";
  char *string2="choose lamp 1 , 2 , 3 or 4:";
  char *string3="lamp 1 is on \r";
  char *string4="lamp 2 is on \r";
  char *string5="lamp 3 is on \r";
  char *string6="lamp 4 is on\r";
  char *string7="lamp 1 is off\r";
  char *string8="lamp 2 is off \r";
  char *string9="lamp 3 is off \r";
  char *string10="lamp 4 is off \r";
  char *string11="last action:";
  usart_string_transmit(string1);
  usart_string_transmit(string2);
  uint8 a=0,b=0,c=0,d=0;
    while (1) 
    {
		
		data=UART_Vreceive();
		if(!data){
		UART_vtransmit(12);
		}
		switch(data)
		{
			case '1':
			UART_vtransmit(12);
			a++;
			if(a==1){
			usart_string_transmit(string11);
			usart_string_transmit(string3);
			usart_string_transmit(string2);
			}
			else{
				usart_string_transmit(string11);
				usart_string_transmit(string7);
				usart_string_transmit(string2);
				a=0;
			}
			break;
			case '2':
			UART_vtransmit(12);
			b++;
			if(b==1){
				usart_string_transmit(string11);
				usart_string_transmit(string4);
				usart_string_transmit(string2);
			}
			else{
				usart_string_transmit(string11);
				usart_string_transmit(string8);
				usart_string_transmit(string2);
				b=0;
			}
			break;
			case '3':
			UART_vtransmit(12);
			c++;
			if(c==1){
				usart_string_transmit(string11);
				usart_string_transmit(string5);
				usart_string_transmit(string2);
			}
			else{
				usart_string_transmit(string11);
				usart_string_transmit(string9);
				usart_string_transmit(string2);
				c=0;
			}
			break;
			case '4':
			UART_vtransmit(12);
			d++;
			if(d==1){
				usart_string_transmit(string11);
				usart_string_transmit(string6);
				usart_string_transmit(string2);
			}
			else{
				usart_string_transmit(string11);
				usart_string_transmit(string10);
				usart_string_transmit(string2);
				d=0;
			}
			break;
		}
		
		_delay_ms(100);
		SPI_MASTER_TRANSMIT(data);
    }
  
}

