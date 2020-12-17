/*
 * DIO.c
 *
 * Created: 11/10/2020 8:53:31 PM
 *  Author: Mahmoud
 */ 

#include "DIO.h"
#include "STD.h"
#include "reg.h"
#include <avr/io.h>
////////////////////////////////initialize port (output/input)//////////////////////////////////////////////////////

void DIO_SET_PORT_DIR(uint8 port,uint8 dir){
	switch(port){
		case DIO_PORTA:
		if(dir==DIO_PORT_OUTPUT){
			DDRA=dir;
		}
		else{
		DDRA=DIO_PORT_INPUT;	
		}
		break;
		case DIO_PORTB:
		if(dir==DIO_PORT_OUTPUT){
			DDRB=dir;
		}
		else{
			DDRB=DIO_PORT_INPUT;
		}
		break;
		case DIO_PORTC:
		if(dir==DIO_PORT_OUTPUT){
			DDRC=dir;
		}
		else{
			DDRC=DIO_PORT_INPUT;
		}
		break;
		case DIO_PORTD:
		if(dir==DIO_PORT_OUTPUT){
			DDRD=dir;
		}
		else{
			DDRD=DIO_PORT_INPUT;
		}
		break;
	}
}
//////////////////////////////////set port output value//////////////////////////////////////////////////////////////////

void DIO_SET_PORT_VAL(uint8 port,uint8 dir){
	switch(port){
		case DIO_PORTA:
		if(dir==DIO_PORT_HIGH){
			PORTA=dir;
		}
		else{
			PORTA=DIO_PORT_LOW;
		}
		break;
		case DIO_PORTB:
		if(dir==DIO_PORT_HIGH){
			PORTB=dir;
		}
		else{
			PORTB=DIO_PORT_LOW;
		}
		break;
		case DIO_PORTC:
		if(dir==DIO_PORT_HIGH){
			PORTC=dir;
		}
		else{
			PORTC=DIO_PORT_LOW;
		}
		break;
		case DIO_PORTD:
		if(dir==DIO_PORT_HIGH){
			PORTD=dir;
		}
		else{
			PORTD=DIO_PORT_LOW;
		}
		break;
		
	}
}
//////////////////////////read port value///////////////////////////////////////////////////////////
uint8 READ_PORT_VALUE(uint8 port){
	static uint8 val;
	switch(port){
		case DIO_PORTA:
		val=PINA;
		break;
		case DIO_PORTB:
		val=PINB;
		break;
		case DIO_PORTC:
		val=PINC;
		break;
		case DIO_PORTD:
		val=PIND;
		break;
	
	}
	return val;
}
//////////////////////////////////set pin dir(output/input)//////////////////////////////
void DIO_PIN_DIR(uint8 port, uint8 pin ,uint8 dir){
	switch(port){
		case DIO_PORTA:
		if(dir==DIO_PIN_OUTPUT){
			SIT_BIT(DDRA,pin);
		}
		else{
			CLR_BIT(DDRA,pin);
		}
		break;
		case DIO_PORTB:
		if(dir==DIO_PIN_OUTPUT){
			SIT_BIT(DDRB,pin);
		}
		else{
			CLR_BIT(DDRB,pin);
		}
		break;
		case DIO_PORTC:
		if(dir==DIO_PIN_OUTPUT){
			SIT_BIT(DDRC,pin);
		}
		else{
			CLR_BIT(DDRC,pin);
		}
		break;
		case DIO_PORTD:
		if(dir==DIO_PIN_OUTPUT){
			SIT_BIT(DDRD,pin);
		}
		else{
			CLR_BIT(DDRD,pin);
		}
		break;
	}
}
/////////////////////////////////set pen value////////////////////////////
void  SET_PIN_VALUE(uint8 port,uint8 pin,uint8 val){
	switch (port){
		case DIO_PORTA:
		if(val==PIN_HIGH){
			SIT_BIT(PORTA,pin);
		}
		else {
			CLR_BIT(PORTA,pin);
		}
		break;
		case DIO_PORTB:
		if(val==PIN_HIGH){
			SIT_BIT(PORTB,pin);
		}
		else {
			CLR_BIT(PORTB,pin);
		}
		break;
		case DIO_PORTC:
		if(val==PIN_HIGH){
			SIT_BIT(PORTC,pin);
		}
		else {
			CLR_BIT(PORTC,pin);
		}
		break;
		case DIO_PORTD:
		if(val==PIN_HIGH){
			SIT_BIT(PORTD,pin);
		}
		else {
			CLR_BIT(PORTD,pin);
		}
		break;
	}
}
////////////////////////////read pin value/////////////////////////////////////
uint8 READ_PIN_VALUE(uint8 port,uint8 pin){
	static uint8 val=0;
	switch(port){
	case DIO_PORTA:
	val=READ_PIN_VALUE(PORTA,pin);
	break;
	case DIO_PORTB:
	val=READ_PIN_VALUE(PORTB,pin);
	break;
	case DIO_PORTC:
	val=READ_PIN_VALUE(PORTC,pin);
	break;
	case DIO_PORTD:
	val=READ_PIN_VALUE(PORTD,pin);
	break;
	}
	return val;		
}
///////////////////////////////toggle value of pin /////////////////////////////
void DIO_TOGGLE_BIN(uint8 port,uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA:
		TOGGLE_BIT(PORTA,pin);
		break;
		
		case DIO_PORTB:
		TOGGLE_BIT(PORTB,pin);
		break;
		
		case DIO_PORTC:
		TOGGLE_BIT(PORTC,pin);
		break;
		
		case DIO_PORTD:
		TOGGLE_BIT(PORTD,pin);
		break;
		
		default:
		break;
	}
}
