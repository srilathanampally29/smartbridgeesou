#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	
	DDRD=0xFF;
	{
		PORTD=0xFF;
		{
			
			PORTD=0x01;
			_delay_ms(220);
			PORTD=0x00;
			_delay_ms(220);
			PORTD=0x02;
			_delay_ms(220);
			PORTD=0x00;
			_delay_ms(220);
			PORTD=0x04;
			_delay_ms(220);
			PORTD=0x00;
			_delay_ms(220);
			PORTD=0x08;
			_delay_ms(220);
			PORTD=0x00;
			_delay_ms(220);
			PORTD=0x10;
			_delay_ms(220);
			PORTD=0x00;
			_delay_ms(220);
			PORTD=0x20;
			_delay_ms(220);
			PORTD=0x00;
			_delay_ms(220);
			PORTD=0x40;
			_delay_ms(220);
			PORTD=0x00;
			_delay_ms(220);
			PORTD=0x80;
			_delay_ms(220);
		}
	}
}
			

