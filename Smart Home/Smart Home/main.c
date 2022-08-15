#include <avr/io.h>
#include <avr/interrupt.h>
#include "MCAL/UART/UART.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/PWM/PWM.h"
#include "HAL/Servo/Servo.h"

#define  F_CPU 16000000UL


int main(void)
{
	//start conversion
	
	LCD_Init();
	
	ADC_Init(ADC_AVcc, ADC_CK64, ADC_Channel_0);

	
	sei();        // enable global interrupts.
	
	while (1)
	{
		ADC_Start_conv();
	}
}

ISR(USART_RXC_vect)
{
	char dataIn = UDR;
	
	switch (dataIn)
	{
		case ('a'):
		//Servo_90_Degrees();             // open door
		
		break;
		
		case ('b'):
		//Servo_0_Degrees();         // close door
		
		break;
		
		case ('c'):
		DIO_TogglePin(Port_c_pin_0);      // toggle lamp 1
		
		break;
		
		case ('d'):
		DIO_TogglePin(Port_c_pin_1);      // toggle lamp 2
		
		break;
		
		case ('e'):
		DIO_TogglePin(Port_c_pin_2);      // toggle lamp 3
		
		break;
		
		case ('f'):
		DIO_TogglePin(Port_c_pin_3);      // toggle lamp 4
		
		break;
		
		case ('g'):
		//PWM_SetDutyCycle_Timer2(0);        // light off
		
		break;
		
		case ('h'):
		//PWM_SetDutyCycle_Timer2(125);        // light dimmed
		
		break;
		
		case ('i'):
		//PWM_SetDutyCycle_Timer2(255);         // light on
		
		break;
	}
}

ISR(ADC_vect)
{   
	u16 adcReading = ADC_Read_NOBlock(ADC_Channel_0); 
	LCD_SetCursorPosition(0, 0);
	LCD_WriteNumber(adcReading);
	
	int cel = Temperature_value(adcReading);
	
	if (cel > 28)
		PWM_SetDutyCycle_Timer0(255);
	else
		PWM_SetDutyCycle_Timer0(0);
	
	LCD_SetCursorPosition(1, 0);
	LCD_WriteNumber(cel);
}
