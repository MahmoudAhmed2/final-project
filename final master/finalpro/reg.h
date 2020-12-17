/*
 * reg.h
 *
 * Created: 11/10/2020 8:36:35 PM
 *  Author: Mahmoud
 */ 


#ifndef REG_H_
#define REG_H_
#define DDRA *(volatile uint8*)(0x3A)
#define PINA *(volatile uint8*)(0x39)
#define PORTA *(volatile uint8*)(0x3B)


#define DDRB *(volatile uint8*)(0x37)
#define PINB *(volatile uint8*)(0x36)
#define PORTB *(volatile uint8*)(0x38)


#define DDRC *(volatile uint8*)(0x34)
#define PINC *(volatile uint8*)(0x33)
#define PORTC *(volatile uint8*)(0x35)


#define DDRD *(volatile uint8*)(0x31)
#define PIND *(volatile uint8*)(0x30)
 
 




#endif /* REG_H_ */