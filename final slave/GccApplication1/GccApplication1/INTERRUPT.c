/*
 * INTERRUPT.c
 *
 * Created: 11/12/2020 11:29:27 AM
 *  Author: Mahmoud
 */ 


#include "DIO.h"
#include "reg.h"
#include "STD.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "INTERRUPT.h"
#include <avr/io.h>
void DEFINE_INTERRUPT0(void){
	sei();
	DIO_PIN_DIR(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	SET_PIN_VALUE(DIO_PORTD,DIO_PIN2,PIN_HIGH);
	GICR|=(1<<INT0);
}
void DEFINE_INTERRUPT1(void){
	sei();
	DIO_PIN_DIR(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	SET_PIN_VALUE(DIO_PORTD,DIO_PIN2,PIN_HIGH);
	GICR|=(1<<INT1);
}

