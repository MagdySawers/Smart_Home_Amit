#include <avr/io.h>


#ifndef UART_H_
#define UART_H_


#define  F_CPU 16000000UL
#define BaudRate 9600

#ifndef DoubleSpeed
#define  MyUBRR ((F_CPU / (BaudRate * 16UL)) -1)
#else
#define  MyUBRR ((F_CPU / (BaudRate * 8UL)) -1)
#endif



void UART_Init();
void UART_TransmitByte(char data);
void UART_TransmitString(char * text);
unsigned char UART_Receive();




#endif /* UART_H_ */