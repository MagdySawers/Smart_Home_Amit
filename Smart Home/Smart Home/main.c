#include <avr/io.h>
#include <avr/interrupt.h>
#include "MCAL/UART/UART.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/PWM/PWM.h"

int main(void)
{
	UART_Init();
	LCD_Init();
	PWM_Init();
	sei();
	
	DIO_SetPinDirection(Port_d_pin_3, Output);
	
	while (1)
	{	
		for (unsigned short i = 0; i < 255; i++)
		{
			PWM_SetDutyCycle(i);
			
			// delay so as to make the user "see" the change
			_delay_ms(5);
		}
		
		_delay_ms(250);
		
		for (unsigned short i = 255; i > 0 ; i--)
		{
			PWM_SetDutyCycle(i);
			
			// delay so as to make the user "see" the change
			_delay_ms(5);
		}
		
		_delay_ms(250);
	}
}

ISR(USART_RXC_vect)
{
	char dataIn = UDR;
	LCD_SetCursorPosition(0, 0);
	LCD_WriteChar('a');
	
	switch (dataIn)
	{
		case ('a'):
		
		// open door
		
		break;
		
		case ('b'):
		
		// close door
		
		break;
		
		case ('c'):
		
		// toggle lamp 1
		DIO_TogglePin(Port_d_pin_3);      // toggle lamp 1
		
		break;
		
		case ('d'):
		
		// toggle lamp 2
		DIO_TogglePin(Port_d_pin_3);      // toggle lamp 2
		
		break;
		
		case ('e'):
		
		// toggle lamp 3
		DIO_TogglePin(Port_d_pin_3);      // toggle lamp 3
		
		break;
		
		case ('f'):
		
		// toggle lamp 4
		DIO_TogglePin(Port_d_pin_3);      // toggle lamp 4
		
		break;
		
		case ('g'):
		break;
		
		case ('h'):
		break;
		
		case ('i'):
		break;
		
		case ('j'):
		break;
		
		case ('k'):
		break;
		
		case ('l'):
		break;
	}
}