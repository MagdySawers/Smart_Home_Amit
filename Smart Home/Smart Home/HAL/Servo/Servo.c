#include "Servo.h"

void Servo_Init()
{
	// Configure timer 1
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11); // non inverted PWM
	TCCR1B |= (1 << WGM13) | (1 << WGM12) | (0 << CS11) | (1 << CS10); // pre-scaler = 1 (fast pwm)

	ICR1 = 19999;            //fPWM=50Hz (Period = 20ms Standard).

	DDRD |= (1 << PD4) | (1 << PD5); //PWM Pins as Out
}

void Servo_0_Degrees()
{
	OCR1A = 0;
}

void Servo_90_Degrees()
{
	OCR1A = 950;
}

void Servo_180_Degrees()
{
	OCR1A = 1900;
}
