/*
 * finalpro.c
 *
 * Created: 12/5/2020 10:07:15 AM
 * Author : Mahmoud
 */ 

#ifndef UART_H_
#define UART_H_

void UART_vInit(unsigned long baud);
void UART_vtransmit(unsigned char val);
void usart_string_transmit(char *string);
unsigned char UART_Vreceive(void);
char *usart_string_receive(char *receive_string,uint8 terminating_character);

#endif /* UART_H_ */