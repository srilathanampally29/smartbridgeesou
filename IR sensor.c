#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>

#define LED_OUTPUT PORTB
#define PIR_INPUT PINC
int main(void)
{
	
	DDRC=0x00;
	DDRD=0xFF;
	while(1)
	{
		
		LED_OUTPUT=PIR_INPUT;
	}
}


