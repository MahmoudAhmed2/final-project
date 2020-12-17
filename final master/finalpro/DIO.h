/*
 * DIO.h
 *
 * Created: 11/10/2020 8:53:56 PM
 *  Author: Mahmoud
 */ 



#ifndef DIO_H_
#define DIO_H_
#include "STD.h"

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0
#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT 0x00
#define PIN_HIGH 1
#define PIN_LOW 0
#define DIO_PORT_HIGH 0xff
#define DIO_PORT_LOW 0x00

void DIO_SET_PORT_DIR(uint8 port,  uint8 dir);
void DIO_SET_PORT_VAL(uint8 port,uint8 dir);
uint8 READ_PORT_VALUE(uint8 port);
void DIO_PIN_DIR(uint8 port, uint8 pin ,uint8 dir);
void  SET_PIN_VALUE(uint8 port,uint8 pin,uint8 val);
uint8 READ_PIN_VALUE(uint8 port,uint8 pin);
void DIO_TOGGLE_BIN(uint8 port,uint8 pin);




#endif /* DIO_H_ */