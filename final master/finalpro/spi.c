/*
 * spi.c
 *
 * Created: 11/27/2020 10:10:55 AM
 *  Author: Mahmoud
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
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7
void SPI_INIT_MASTER(void){
	//configure master or slave(master)
	SIT_BIT(SPCR,MSTR);
	//configure clock speed
	SIT_BIT(SPCR,SPR1);
	SIT_BIT(SPCR,SPR0);
	//configure mosi,ss,sck as output
	DDRB|=(1<<MOSI);
	DDRB|=(1<<SCK);
	DDRB|=(1<<SS);
	//put ss as high
	PORTB|=(1<<SS);
	//enable spi perpheral 
	SIT_BIT(SPCR,SPE);
}
void SPI_MASTER_TRANSMIT(char data){
	//enable ss (set to 0)
	PORTB&=~(1<<SS);
	//put data to spdr
	SPDR=data;
	//check transmission is done
	while((SPSR&(1<<SPIF))==0)
	{
		//do nothing
	}
	//close ss (Set ss back to 1 )
	PORTB|=(1<<SS);
}