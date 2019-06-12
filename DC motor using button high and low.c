#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
void PWM_init()
{
	
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	DDRB|=(1<<PB3);
}
int main(void)
{
	
	unsigned char duty;
	PWM_init();
	DDRD=0xFF;
	while(1)
	{
		
		DDRC=0x00;
		DDRD &=~(1<<PD0);
		DDRA &=~(1<<PA0);
		while(1)
		{
			
			if((PIND & (1<<PD0))==0)
			{
				
				for(duty=0;duty<255;duty++)
				{
					
					OCR0=duty;
					
					PORTD=0x01;
					_delay_ms(4000);
					PORTD=0x00;
					_delay_ms(4000);
				}
			}
			if((PINA & (1<<PA0))==0)
			{
				
				for(duty=255;duty>1;duty--)
				{
					
					OCR0=duty;
					PORTD=0x02;
					_delay_ms(4000);
					PORTD=0x00;
					_delay_ms(4000);
				}
			}
		}
	}
}

