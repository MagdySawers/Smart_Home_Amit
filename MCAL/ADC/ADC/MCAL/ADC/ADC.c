#include "ADC.h"

void ADC_Init(Enum_Volt_Reference voltRefernce, u8 prescaler, u8 adlar)
{
	SetVoltReference(voltRefernce);
	Set_ADLAR(adlar);
	EnableADC();
	StartConversion();
	SetPrescaler(prescaler);
}

u16 ADC_Read(u8 channel)
{
	ClearPreviousChannel();
	
	SetReadingChannel(channel);
	
	StartConversion();
	
	// wait until ADSC bit is high (until conversion completes)
	while (DIO_GetRegisterValue(ADCSRA_Address) & (1 << ADCSRA_ADSC)) { }

	u16 tenBits = Get10Bits();

	return tenBits;
}

static void ClearPreviousChannel()
{
	*(volatile u8*)ADMUX_Address &= 0xF0;    // clear the older channel that was read
}

static void SetReadingChannel(u8 channel)
{
	*(volatile u8*)ADMUX_Address |= channel;       // set the channel that will be read.
}

static void SetVoltReference(Enum_Volt_Reference voltRefernce)
{
	// set reference voltage
	switch (voltRefernce)
	{
		case (Volt_Off):
		*(volatile u8*)ADMUX_Address &= ~(1 << ADMUX_Ref1);
		*(volatile u8*)ADMUX_Address  &= ~(1 << ADMUX_Ref0);
		
		break;
		
		case (Volt_Vcc):
		*(volatile u8*)ADMUX_Address &= ~(1 << ADMUX_Ref1);
		*(volatile u8*)ADMUX_Address |= 1 << ADMUX_Ref0;
		
		break;
		
		case (Volt_1_1):
		*(volatile u8*)ADMUX_Address |= 1 << ADMUX_Ref1;
		*(volatile u8*)ADMUX_Address &= ~(1 << ADMUX_Ref0);
		
		break;
		
		case (Volt_2_56):
		*(volatile u8*)ADMUX_Address |= 1 << ADMUX_Ref1;
		*(volatile u8*)ADMUX_Address |= 1 << ADMUX_Ref0;
		
		break;
	}
}

static void EnableADC()
{
	DIO_SetRegisterPin(ADCSRA_Address, ADCSRA_ADEN, High);
}

static void StartConversion()
{
	DIO_SetRegisterPin(ADCSRA_Address, ADCSRA_ADSC, High);
}

static void SetPrescaler (u8 prescaler)
{
	// another form
	//*(volatile u8*)ADCSRA_Address |= ( (1 << ADCSRA_PresclerBit1) | (1 << ADCSRA_PresclerBit2) | (1 << ADCSRA_PresclerBit3) );
	
	switch (prescaler)
	{
		case (2):
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit1, Low);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit2, Low);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit3, High);
			
		break;
		
		case (4):
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit1, Low);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit2, High);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit3, Low);
		
		break;
		
		case (16):
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit1, High);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit2, Low);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit3, Low);
		
		break;
		
		case (32):
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit1, High);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit2, Low);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit3, High);
			
		break;
		
		case (64):
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit1, High);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit2, High);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit3, Low);
			
		break;
		
		case (128):
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit1, High);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit2, High);
			DIO_SetRegisterPin (ADCSRA_Address, ADCSRA_PresclerBit3, High);
			
		break;
	}
}

static void Set_ADLAR(u8 val)
{
	ADLAR_Value = val;
	
	if (val == ADLAR0)
		*(volatile u8*) ADMUX_Address &= ~(1 << ADLAR_Bit);
	else if (val == ADLAR1)
		*(volatile u8*) ADMUX_Address |= 1 << ADLAR_Bit;
}

static u16 Get10Bits()
{
	u8 low = DIO_GetRegisterValue(ADCL_Address);
	u8 high = DIO_GetRegisterValue(ADCH_Address);
	
	u16 tenBits = 0;
	
	switch (ADLAR_Value)
	{
		case (ADLAR0):
			tenBits = high << 2 | Low >> 6;
			
		break;
		
		case (ADLAR1):
			tenBits = high << 8 | Low ;
		
		break;
	}
	
	return (tenBits);
}