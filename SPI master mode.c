/*
 * SPI Master mode.c
 *
 * Created: 14-06-2019 12:32:21
 * Author : SRILATHA
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
void SPI_Init()
{
	
	DDRB|=(1<<MOSI)|(1<<SCK)|(1<<CSS);
	DDRB &=~(1<<MISO);
	PORTB|=(1<<SS);
	SPCR=(1<<SPE);
	SPSR &=~(1<<SPI2X);
}
void SPI_write(char data)
{
	char flush_buffer;
	SPDR=data;
	while(!(SPSR &(1<<SPIF)));
	flush_buffer=SPDR;
}
char SPI_Read()
{
	
	SPDR=0xFF;
	while(!(SPSR &(1<<SPIFF)));
	return(SPDR);
}

