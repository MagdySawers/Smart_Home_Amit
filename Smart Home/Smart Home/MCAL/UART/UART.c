#include "UART.h"

void UART_Init()
{
	UCSRB =  (1 << RXCIE) | (1 << RXEN) |( 1 << TXEN);    // enable transmit and receive (interrupt mode)
	//UCSRB |= (1 << RXEN) | (1 << TXEN);      // enable transmit and receive (data mode)
	
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	
	UBRRL = MyUBRR;              // set baud rate
	UBRRH = MyUBRR >> 8;         // set baud rate
}

void UART_TransmitByte(char byte)
{
	while(!(UCSRA & (1 << UDRE)));   // flag is reised when sending, you can use GetBit(). this is another way to use GetBit()
	UDR = byte;         // UDR is the register that holds transmitted and received data.
}

void UART_TransmitString(char* text)
{
	char i = 0;
	while (text[i] != '\0')
	{
		UART_TransmitByte(text[i]);
		i++;
	}
}

unsigned char UART_Receive()
{
	while(!(UCSRA & (1 << RXC)));   //flag is reised when receiving, you can use GetBit(). this is another way to use GetBit()
	return (UDR);
}

char * UART_ReceiveString()
{
	while(!(UCSRA & (1 << RXC)));   //flag is reised when receiving, you can use GetBit(). this is another way to use GetBit()
	
	char * str;
	
	while (UDR != '\0')
	{
		str += UDR;
	}
	
	return (str);
}