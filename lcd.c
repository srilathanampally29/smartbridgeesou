 

#include <avr/io.h>
#define F_CPU 16000000UL
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
	send_command(0x01);
    send_command(0x38);
	send_command(0x0E);
	send_character(0x53);
	send_character(0x6F);
	send_character(0x68);
	send_character(0x69);
	send_character(0x6C);
}
void send_character(unsigned char character)
{
	PORTC=character;
	PORTD|=(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD &=~(1<<E);
	PORTC=0;
}
void send_command(unsigned char command)
{
	PORTC=command;
	PORTD &=~(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD &=~(1<<E);
	PORTC=0;
}
