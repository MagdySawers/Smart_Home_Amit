#include "bit_operations.h"

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

/*DIO*/
#define PIND		*((volatile u8*)0x30)
#define DDRD		*((volatile u8*)0x31)
#define PORTD		*((volatile u8*)0x32)

#define PINC		*((volatile u8*)0x33)
#define DDRC		*((volatile u8*)0x34)
#define PORTC		*((volatile u8*)0x35)

#define PINB		*((volatile u8*)0x36)
#define DDRB		*((volatile u8*)0x37)
#define PORTB		*((volatile u8*)0x38)

#define PINA		*((volatile u8*)0x39)
#define DDRA		*((volatile u8*)0x3A)
#define PORTA		*((volatile u8*)0x3B)

/*ADC*/
#define ADMUX		*((volatile u8*)0x27) //ADC multiplexer selection register
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

#define ADCSRA		*((volatile u8*)0x26) //ADC status register
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

#define ADCH		*((volatile u8*)0x25) //ADC data register high
#define ADCL		*((volatile u8*)0x24) //ADC data register low

/*EXTI*/
#define MCUCR		*((volatile u8*)0x55)
#define ISC00	0
#define ISC01	1
#define MCUCSR		*((volatile u8*)0x54)
#define GIFR		*((volatile u8*)0x5A)
#define GICR		*((volatile u8*)0x5B)

 /*TIMER0*/
#define TCCR0       *((volatile u8*)0x53)
#define TCNT0       *((volatile u8*)0x52)
#define OCR0        *((volatile u8*)0x5C)
#define TIMSK       *((volatile u8*)0x59)
#define TIFR        *((volatile u8*)0x58)


/************************Global interrupt********************/

#define SREG		*((volatile u8*)0x5F)

#define sei()	__asm__ __volatile__ ("sei"::) //enable the global interrupt
#define cli()	__asm__ __volatile__ ("cli"::) //disable the glb interrupt


#define ISR(vector)		void vector(void) __attribute__ ((signal));\
						void vector(void)
						
/*****************************vectors**************************/

#define ADC_vect			__vector_16

#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3

#define TIMER0_OVF_vect		__vector_11

#endif /* MEMORY_MAP_H_ */