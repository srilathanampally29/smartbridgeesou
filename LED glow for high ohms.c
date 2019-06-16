#include<avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>
#include<stdio.h>
#define enable 5
#define registerselection 7
void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_character);
int main(void)
{
	
	DDRC=0xFF;
	DDRA=0x00;
	DDRD=0xFF;
	_delay_ms(50);
	ADMUX|=(1<<REFS0)|(1<<REFS1);
	ADCSRA|=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	int16_t COUNTA=0;
	char SHOWA[3];
	send_a_command(0x01);
	_delay_ms(50);
	send_a_command(0x38);
	_delay_ms(50);
	send_a_command(0b00001111);
	_delay_ms(50);
	ADCSRA|=(1<<ADSC);
	while(1)
	{
		
		COUNTA=ADC/4;
		send_a_string("Smartbridge");
		send_a_command(0x80+0x40+0);
		send_a_string("EMF(V)=");
		send_a_command(0x80+0x40+8);
		itoa(COUNTA,SHOWA,10);
		send_a_string(SHOWA);
		send_a_string(" ");
		send_a_command(0x80+0);
	}
}
void send_a_command(unsigned char command)
{
	PORTC=command;
	PORTD&=~(1<<registerselection);
	PORTD|=(1<<enable);
	_delay_ms(50);
	PORTD&=~(1<<enable);
	PORTC=0;
}
void send_a_character(unsigned char character)
{
	
	PORTC=character;
	PORTD|=(1<<registerselection);
	PORTD|=(1<<enable);
	_delay_ms(50);
	PORTD&=~(1<<enable);
	PORTC=0;
}
void send_a_string(char *string_of_characters)
{
	while(*string_of_characters>0)
	{
		send_a_character(*string_of_characters++);
	}
}


