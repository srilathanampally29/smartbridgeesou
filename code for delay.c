/*
 * code for delay.c
 *
 * Created: 10-06-2019 12:13:15
 * Author : DELL
 */ 

#include <avr/io.h>
#define LED PB0
int main()
{
	
	uint8_t timeroverflowcount=0;
	DDRB=0xFF;
	TCNT0=0x00;
	TCCR0=(1<<CS00)|(1<<CS02);
    while (1) 
    {
		while((TIFR&0x01)==0);
		TCNT0=0x00;
		TIFR=0x01;
		timeroverflowcount++;
		if(timeroverflowcount>=5)
		{
			PORTB^=(0x01<<LED);
			timeroverflowcount=0;
		}
	}
    }

