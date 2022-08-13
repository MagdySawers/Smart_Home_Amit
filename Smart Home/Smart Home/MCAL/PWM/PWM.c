#include "PWM.h"
#include <avr/io.h>

void PWM_Init(void)
{
	// initialize TCCR0 as per requirement, say as follows
	TCCR0 |= (1 << WGM00) | (1 << WGM01) | (1 << COM01)  | (1 << CS00);
	
	// make sure to make OC0 pin (pin PB3 for atmega32) as output pin.
	DDRB |= (1 << PB3);
	// make sure to make OC2 pin (pin PD7 for atmega32) as output pin.
	DDRD |= (1 << PB7);
}

void PWM_SetDutyCycle_Timer0(unsigned short val)
{
	OCR0 = val;
}

void PWM_SetDutyCycle_Timer2(unsigned short val)
{
	OCR2 = val;
}