#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include<avr/io.h>
#include<util/delay.h>
#define RS 7
#define E 5
void send_command(unsigned char command);
void send_character(unsigned char character);
int main(void)
{
	DDRC=0xFF;
	DDRD=0xFF;
	_delay_ms(50);
	//PORTc|=(1<<PCO);
	send_command(0x01);
	send_command(0x38);
	send_command(0x0E);
	DDRA|=(1<<PA0);
	DDRB=~(1<<PB0);
	while(1)
	{
		if((PINB &(1<<PB0))==0)
		{
			
			PORTA|=(1<<PA0);
			send_character(0x4F);
			send_character(0x4E);
			_delay_ms(3000);
			send_command(0x01);
			PORTA&=~(1<<PA0);
			send_character(0x4F);
			send_character(0x46);
	        _delay_ms(300);
	        send_command(0x01);
		}
}
}
void send_command(unsigned char command)
{
	
	PORTC=command;
	PORTD&=~(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD&=~(1<<E);
	PORTC=0;
}
void send_character(unsigned char character)
{
	PORTC=character;
	PORTD|=(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD&=~(1<<E);
	PORTC=0;
}
