#include "type_def.h"
#include "bit_operations.h"
#include "DIO/DIO.h"

#ifndef ADC_H_
#define ADC_H_

// Set Ref0 and Ref1 as follows
// Ref1-Ref0
// 00 to turn off ADMUX
// 01 to set reference voltage to Vcc
// 10 to set reference voltage to 1.1v
// 11 to set reference voltage to 2.56v

#define ADMUX_Address 0x27      // ADC multiplexer selection register
#define ADMUX_Ref0 6
#define ADMUX_Ref1 7

#define ADCSRA_Address 0x26         // ADC control and status register
#define ADCSRA_ADEN 7      // set it to 0 or 1 to turn off or on ADC
#define ADCSRA_ADSC 6     // set it to 1 to start conversion from analog to digital
#define ADCSRA_PresclerBit1 2
#define ADCSRA_PresclerBit2 1
#define ADCSRA_PresclerBit3 0

#define ADCH_Address 0x25
#define ADCL_Address 0x24 
#define ADLAR_Bit 5
#define ADLAR0 0
#define ADLAR1 1

u8 ADLAR_Value;

typedef enum 
{
	Volt_Off, Volt_Vcc, Volt_1_1, Volt_2_56
}Enum_Volt_Reference;

void ADC_Init(Enum_Volt_Reference voltRefernce, u8 prescaler, u8 adlar);
u16 ADC_Read(u8 channel);

static void SetVoltReference(Enum_Volt_Reference voltRefernce);
static void EnableADC();
static void StartConversion();
static void ClearPreviousChannel();
static void SetReadingChannel(u8 channel);
static void SetPrescaler (u8 prescaler);
static void Set_ADLAR(u8 val);
static u16 Get10Bits();


#endif /* ADC_H_ */