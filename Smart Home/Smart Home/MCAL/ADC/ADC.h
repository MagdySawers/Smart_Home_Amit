#include "type_def.h"
#include "bit_operations.h"
#include <avr/io.h>

#ifndef ADC_H_
#define ADC_H_

typedef enum
{
  ADC_AVref=0,
  ADC_AVcc=1,
  ADC_V256=3
	
}Enum_V;

typedef enum
{
  ADC_CK2=1,
  ADC_CK4,
  ADC_CK8,
  ADC_CK16,
  ADC_CK32,
  ADC_CK64,
  ADC_CK128
	
}Enum_Prescale;

typedef enum
{
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
	
}Enum_Channels;


#define ADMUX *((volatile u8*)0x27)
#define REFS1 7
#define REFS0 6 
#define ADLAR 5
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0

#define ADCSRA *((volatile u8*)0x26)
#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

#define ADCH *((volatile u8*)0x25)
#define ADCL *((volatile u8*)0x24)


void ADC_Init(Enum_V v ,Enum_Prescale prescale, Enum_Channels channel);

u16 ADC_Read (Enum_Channels channel);
u16 ADC_Read_NOBlock (Enum_Channels channel);
void ADC_Start_conv(void);
void ADC_Enable_Interrupt(void);

#endif
