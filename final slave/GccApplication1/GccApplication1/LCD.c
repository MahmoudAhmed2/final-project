/*
 * LCD.c
 *
 * Created: 11/12/2020 8:40:43 PM
 *  Author: Mahmoud
 */ 
#include <math.h>
#define F_CPU   16000000UL
#include <util/delay.h>
#include "DIO.h"
#include "STD.h"
#include "reg.h"
#include "spi.h"
//#include "keypad.h"
#include "LCD.h"
#include "INTERRUPT.h"
#include <avr/io.h>
#include <avr/interrupt.h>



#define RS 1
#define RW 2
#define EN 3

void SEND_FALLING_EDGE(void){
	SIT_BIT(PORTB,EN);
	_delay_ms(5);
	CLR_BIT(PORTB,EN);
	_delay_ms(5);
}
void SEND_CMD(uint8 cmd){
	PORTA&=0x0f;
	PORTA|=(cmd&0xf0);//send last 4 digits 
	CLR_BIT(PORTB,RS);
	SEND_FALLING_EDGE();
	PORTA&=0x0f;
	PORTA|=(cmd<<4);//send first 4 digits
	CLR_BIT(PORTB,RS);
	SEND_FALLING_EDGE();	
}
void SEND_DATA(uint8 cmd){
	PORTA&=0x0f;
	PORTA|=(cmd&0xf0);//send last 4 digits
	SIT_BIT(PORTB,RS);
	SEND_FALLING_EDGE();
	PORTA&=0x0f;
	PORTA|=(cmd<<4);//send first 4 digits
	SIT_BIT(PORTB,RS);
	SEND_FALLING_EDGE();
}
void LCD_INITIALIZE(void){
DDRB|=0x0E;
DDRA|=0xf0;
CLR_BIT(PORTB,RW);
SEND_CMD(0x33);
SEND_CMD(0x32);
SEND_CMD(0x28);
SEND_CMD(0x01);
SEND_CMD(0x0f);
_delay_ms(20);	
}
void MOVING_CURSOR(uint8 row ,uint8 col){
	uint8 temp;
	if(row==0){
		temp=0x80+col;
	}
	else{
		temp=0xc0+col;
	}
	SEND_CMD(temp);
}
void LCD_PRINT(char *cmd){
	for(int i=0;i<16;i++)
	{
		if(cmd[i]=='\0'){
			break;
		}
		SEND_DATA(cmd[i]);	
	}
}
