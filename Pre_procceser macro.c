#include F_CPU
#define F-CPU 16000000UL
#endif
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED PORTB
char buffer[10];

void USARTInit(uint16_t ubrr_value)
{
	
	UBRRL = ubrr_value;
	UBRRH = (ubrr_value>>0);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UCSR(1<<RXEN)|(1<<TXEN);
}
char USARTReadChar()
{
	
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
	USARTInt(77);
	DDRB=0XFF;
	char data;
	LED=0;
	while(1)
	{
		
		data=USARTReadChar();
		if(data=='1')
		
	}



