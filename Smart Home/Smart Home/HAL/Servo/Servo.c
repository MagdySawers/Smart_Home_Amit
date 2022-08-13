#include "Servo.h"

void Servo_Init()
{
	DDRD |= (1 << PD5);	// Make OC1A pin as output
	
	TCNT1 = 0;		// Set timer1 count zero
	ICR1 = 4999;		// Set TOP count for timer1 in ICR1 register

	// Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64
	TCCR1A = (1 << WGM11) | (1 << COM1A1);
	TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS10) | (1 << CS11);
}

void Servo_0_Degrees()
{
	OCR1A = 130;
}

void Servo_90_Degrees()
{
	OCR1A = 350;
}

void Servo_180_Degrees()
{
	OCR1A = 600;
}