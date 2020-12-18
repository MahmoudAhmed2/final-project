/*
 * GccApplication1.c
 *
 * Created: 12/10/2020 9:44:43 AM
 * Author : Mahmoud
 */ 


#include <math.h>
#define F_CPU   16000000UL
#include <util/delay.h>
#include "DIO.h"
#include "STD.h"
#include "reg.h"
#include "spi.h"
#include "keypad.h"
#include "LCD.h"
#include "INTERRUPT.h"
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	
	char key_entered;
	SPI_INIT_SLAVE();
	KEYPAD_INTIALIZE();
	LCD_INITIALIZE();
	DEFINE_INTERRUPT0();
	
    MOVING_CURSOR(0,0);
	LCD_PRINT("SMART HOME v1");
	_delay_ms(1000);
	SEND_CMD(0x01);
	LCD_PRINT("enter password:");
	MOVING_CURSOR(1,0);
	char string2[16];

    DIO_PIN_DIR(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
    CLR_BIT(PORTD,DIO_PIN1);
    DIO_PIN_DIR(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_PIN_DIR(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_PIN_DIR(DIO_PORTD,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_PIN_DIR(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);
      char *string3="lamp 1 is on \r";
      char *string4="lamp 2 is on \r";
      char *string5="lamp 3 is on \r";
      char *string6="lamp 4 is on \r";
      char *string7="lamp 1 is off \r";
      char *string8="lamp 2 is off \r";
      char *string9="lamp 3 is off \r";
      char *string10="lamp 4 is off \r";
	  char data;
	  uint8 val;
	  uint8 x=0;
	  uint8 y=0;
	  uint8 flag=0;
    while (1) 
    {
		while(flag==0){
			key_entered=KEYPAD_READ();
			_delay_ms(100);
			if(key_entered!=0xff){
				y++;
				
				if(key_entered!='s'&&y!=5){
					SEND_DATA('*');
					string2[x++]=key_entered;
				}
				else
				{
					y=0;
					x=0;
					if(string2[0]=='1'&&string2[1]=='2'&&string2[2]=='3'&&string2[3]=='4'){
					SEND_CMD(0x01);
					MOVING_CURSOR(0,0);
					LCD_PRINT("pass correct");
					MOVING_CURSOR(1,5);
					LCD_PRINT(":)");
					_delay_ms(1000);
					SEND_CMD(0x01);
					LCD_PRINT("system is on");
					flag=1;
					}
					else{
						SEND_CMD(0x01);
						MOVING_CURSOR(0,0);
						LCD_PRINT("pass incorrect");
						MOVING_CURSOR(1,0);
						LCD_PRINT(string2);
						_delay_ms(1000);
						SEND_CMD(0x01);
						LCD_PRINT("enter password:");
						MOVING_CURSOR(1,0);
						
					}
					
					
					
				}
			}
			else{
				//no thing
			}
		}
		SIT_BIT(PORTD,DIO_PIN1);
		data=SPI_U8SlAVE_RECIEVER();
         
		switch(data){
			case '1':
			TOGGLE_BIT(PORTD,DIO_PIN4);
			SEND_CMD(0x01);
			val=READ_BIT(PORTD,DIO_PIN4);
			if(val==1){
				LCD_PRINT("last action:");
				MOVING_CURSOR(1,0);
				LCD_PRINT(string3);
			}
			else
			{
		    LCD_PRINT("last action:");
		    MOVING_CURSOR(1,0);
			LCD_PRINT(string7);	
			}
			break;
			case '2':
			TOGGLE_BIT(PORTD,DIO_PIN5);
			SEND_CMD(0x01);
			val=READ_BIT(PORTD,DIO_PIN5);
			if(val==1){
				LCD_PRINT("last action:");
				MOVING_CURSOR(1,0);
				LCD_PRINT(string4);
			}
			else
			{
				LCD_PRINT("last action:");
				MOVING_CURSOR(1,0);
				LCD_PRINT(string8);
			}
			break;
			case '3':
			TOGGLE_BIT(PORTD,DIO_PIN6);
			SEND_CMD(0x01);
			val=READ_BIT(PORTD,DIO_PIN6);
			if(val==1){
				LCD_PRINT("last action:");
				MOVING_CURSOR(1,0);
				LCD_PRINT(string5);
			}
			else
			{
				LCD_PRINT("last action:");
				MOVING_CURSOR(1,0);
				LCD_PRINT(string9);
			}
			break;
			case '4':
			TOGGLE_BIT(PORTD,DIO_PIN7);
			SEND_CMD(0x01);
			val=READ_BIT(PORTD,DIO_PIN7);
			if(val==1){
				LCD_PRINT("last action:");
				MOVING_CURSOR(1,0);
				LCD_PRINT(string6);
			}
			else
			{
				LCD_PRINT("last action:");
				MOVING_CURSOR(1,0);
				LCD_PRINT(string10);
			}
			break;
			
		}
		 
/*		if(c==1){
			LCD_PRINT("enter password:");
			c=2;
		}
		if(c==2){
			MOVING_CURSOR(1,0);
			c=3;
		}
		if (c==3)
		{
			key_entered=KEYPAD_READ();
			if(key_entered!=0xff){
				
				
				if(key_entered!='s'){
				SEND_DATA('*');
				string2[x++]=key_entered;
				}
				else
				{
					string2[x]=0;
					LCD_PRINT(string2);
					x=0;
				}
			}
			else{
				//no thing
			}
			}
			
	*/	
	        
		
		
		data=5;
    }
}
