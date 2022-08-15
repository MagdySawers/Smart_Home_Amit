#include "ADC.h"



void ADC_Init(Enum_V v ,Enum_Prescale prescale, Enum_Channels channel)
{
	DDRA |= 1 << channel;
	//Set_Pin_Direction(PortA,channel,Input); // as an input
	//Set_Pin_Port(PortA,channel,0);     //no pull up
	
	//setting Vref
	
	ADMUX &=0x3F;
	ADMUX |=v<<6;
	
	//setting prescaler
	
	ADCSRA &=0xF8;
	ADCSRA |=prescale;
	
	//ADLAR 0
	ClearBit(ADMUX, ADLAR);
	
	//Enable
	SetBit(ADCSRA, ADEN);
	
}

u16 ADC_Read (Enum_Channels channel)
{
	u16 adc=0;
	
	ADMUX &= 0xE0;
	ADMUX |= channel;
	
	
	//start conversion
	SetBit(ADCSRA,ADSC);
	while(GetBit(ADCSRA,ADSC)==1);  // busy wait
	
	adc= ADCL | (u16)ADCH << 8 ;
	
	
	return adc;
	
}

u16 ADC_Read_NOBlock (Enum_Channels channel)
{
	u16 adc=0;
	
	ADMUX &= 0xE0;
	ADMUX |= channel;
	
	
	//start conversion
	//	Set_Bit(ADCSRA,ADSC);
	
	//while(Get_Bit(ADCSRA,ADSC)==1);  // busy wait
	
	adc= ADCL | (u16)ADCH << 8 ;
	
	
	return adc;
	
}

void ADC_Start_conv(void)
{
	
	SetBit(ADCSRA,ADSC);
	
}


void ADC_Enable_Interrupt(void)
{
	
	SetBit(ADCSRA,3);

}
