#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include<util\delay.h>
int main(void)
{
	int i;
	DDRD =0x00;
	DDRC=0xFF;
	{
		
		while(1)
		if((PIND & (1<<PD1))==0)
		{
			
			for(i=0;i<=7;)
			{
				
				PORTC|=(7<<i);
				_delay_ms(220);
				PORTC &=~(1<<i);
				_delay_ms(220);
				i++;
			}
		}
		if((PIND & (1<<PD2))==0)
		{
			
			for(i=7;i>=0;)
			{
				PORTC|=(1<<i);
				_delay_ms(220);
				PORTC &=~(1<<i);
				_delay_ms(220);
				i--;
			}
		}
	}
}

