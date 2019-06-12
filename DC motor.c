#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRD=0xFF;
	{
		while(1)
		{
			PORTD=0x01;
			_delay_ms(4000);
			
			PORTD=0x00;
			_delay_ms(4000);
			
			PORTD=0x02;
			_delay_ms(4000);
			
			PORTD=0x00;
		_delay_ms(4000);
		}
	}
}

