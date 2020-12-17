/*
 * spi.c
 *
 * Created: 11/27/2020 11:00:12 AM
 *  Author: Mahmoud
 */ 

#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"
#include "reg.h"
#include "STD.h"
#include "spi.h"
#include <avr/io.h>
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7
void SPI_INIT_SLAVE(void)
{
//set as slave by set mstr to 0
//enable spi
SIT_BIT(SPCR,SPE);
//set miso as input	
DDRB|=(1<<MISO);
}
char SPI_U8SlAVE_RECIEVER(void){
	//check transmission is finished
	
	while(!(SPSR&(1<<SPIF)))
	{
		//do nothing
	}
	return SPDR;
}
