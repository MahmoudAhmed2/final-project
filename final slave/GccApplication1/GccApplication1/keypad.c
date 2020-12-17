/*
 * keypad.c
 *
 * Created: 11/13/2020 8:39:46 AM
 *  Author: Mahmoud
 */ 

#include "DIO.h"
#include "reg.h"
#include "STD.h"
#include "LCD.h"
//#include "keypad.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
uint8 arr[4][4]={{'1','2','3','/'},
                 {'4','5','6','*'},
                 {'7','8','9','-'},
                 {'s','0','=','+'}};
void KEYPAD_INTIALIZE(void){
DDRC=0x0f;
PORTC |=0xff;// there is a pin called (pull up direction -sfidr	
}

uint8 KEYPAD_READ(void){
	 
						 
					 
	
	for(uint8 i=0;i<4;i++){
	PORTC=0xff;
	CLR_BIT(PORTC,i);
	for(uint8 j=0;j<4;j++){
    uint8 temp=READ_BIT(PINC,(j+4));
	if(temp==0)
	{
		return  arr[i][j];
	}
	}

	
	}
	return 0xff;//define the magic number to default
	
}
