#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED PORTB
char buffer[10];

void USARTInit(uint16_t ubrr_value)
{
	//set  Baudrate
	UBRRL = ubrr_value;
	UBRRH = (ubrr_value>>0);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	//Enable the receiver and transmitter
	UCSRB=(1<<RXEN)|(1<<TXEN);
}
char USARTReadChar()
{
	//Wait until a data is available
	while(!(UCSRA & (1<<RXC)))
	{
		
	}
	return UDR;
}
void USARTwriteChar(char data)
{
	
	while(!(UCSRA & (1<<UDRE)))
	{
	}
	UDR=data;
}
int main()
{
	USARTInit(77);
	DDRB=0xFF;
	char data;
	LED=0;
	while(1)
	{
		
		data=USARTReadChar();
		if(data=='1')
{
	LED |=0xFF;
}
else if(data=='2')
{
	LED=0x00;
	}
	}
	return 0;
}






