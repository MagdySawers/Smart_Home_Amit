#include "DIO.h"

void DIO_SetPortDirection (Enum_Ports port, Enum_Data_Direction direction)
{
	u8 address = GetDDRAddress(port);
	
	switch (direction)
	{
		case (Input):
		*(volatile u8*)address = 0x00;
		
		break;
		
		case (Output):
		*(volatile u8*)address = 0xFF;
		
		break;
	}
}

void DIO_SetPortValue(Enum_Ports port, u8 val)
{
	u8 address = GetPortAddress(port);
	*(volatile u8*)address = val;
}

void DIO_SetRegisterValue(u8 address, u8 val)
{
	*(volatile u8*)address = val;
}

void DIO_SetRegisterPin(u8 address, u8 pin_number, Enum_Volt_Value val)
{
	switch (val)
	{
		case (High):
		*(volatile u8*)address |= 1 << pin_number;
		
		break;
		
		case (Low):
		*(volatile u8*)address &= ~(1 << pin_number);
		
		break;
	}
}

void DIO_SetPinDirection(Enum_Pins pin, Enum_Data_Direction direction)
{
	u8 address = GetDDRAddress(GetPinPort(pin));
	u8 pin_number = GetPinNumber(pin);
	
	switch (direction)
	{
		case (Input):
		*(volatile u8*)address &= ~(1 << pin_number);
		
		break;
		
		case (Output):
		*(volatile u8*)address |= 1 << pin_number;
		
		break;
	}
}

void DIO_SetPinValue(Enum_Pins pin, Enum_Volt_Value val)
{
	u8 address = GetPortAddress(GetPinPort(pin));
	u8 pin_number = GetPinNumber(pin);
	
	switch (val)
	{
		case (High):
		*(volatile u8*)address |= 1 << pin_number;
		
		break;
		
		case (Low):
		*(volatile u8*)address &= ~(1 << pin_number);
		
		break;
	}
}

void DIO_TogglePin(Enum_Pins pin)
{
	u8 address = GetPortAddress(GetPinPort(pin));
	u8 pin_number = GetPinNumber(pin);
	
	*(volatile u8*)address ^= 1 << pin_number;
}

u8 DIO_GetPortValue(Enum_Ports port)
{
	u8 address = GetPortAddress(port);
	
	return (*(volatile u8*)address);
}

u8 DIO_GetRegisterValue(u8 address)
{
	return (*(volatile u8*)address);
}

u8 DIO_GetPinValue(Enum_Pins pin)
{
	u8 address = GetPinAddress(GetPinPort(pin));
	u8 pin_number = GetPinNumber(pin);
	
	return (*(volatile u8*)address >> pin_number & 1);
}

static u8 GetPortAddress(Enum_Ports port)
{
	u8 address;
	
	switch (port)
	{
		case (A):
		address = Port_A_Address;
		
		break;
		
		case (B):
		address = Port_B_Address;
		
		break;
		
		case (C):
		address = Port_C_Address;
		
		break;
		
		case (D):
		address = Port_D_Address;
		
		break;
	}
	
	return (address);
}

static u8 GetDDRAddress(Enum_Ports port)
{
	u8 address;
	
	switch (port)
	{
		case (A):
		address = DDR_A_Address;
		
		break;
		
		case (B):
		address = DDR_B_Address;
		
		break;
		
		case (C):
		address = DDR_C_Address;
		
		break;
		
		case (D):
		address = DDR_D_Address;
		
		break;
	}
	
	return (address);
}

static u8 GetPinAddress(Enum_Ports port)
{
	u8 address;
	
	switch (port)
	{
		case (A):
		address = Pin_A_Address;
		
		break;
		
		case (B):
		address = Pin_B_Address;
		
		break;
		
		case (C):
		address = Pin_C_Address;
		
		break;
		
		case (D):
		address = Pin_D_Address;
		
		break;
	}
	
	return (address);
}

static Enum_Ports GetPinPort(Enum_Pins pin)
{
	Enum_Ports port;
	
	switch (pin)
	{
		case (Port_a_pin_0):
		case (Port_a_pin_1):
		case (Port_a_pin_2):
		case (Port_a_pin_3):
		case (Port_a_pin_4):
		case (Port_a_pin_5):
		case (Port_a_pin_6):
		case (Port_a_pin_7):
		
		port = A;
		
		break;
		
		case (Port_b_pin_0):
		case (Port_b_pin_1):
		case (Port_b_pin_2):
		case (Port_b_pin_3):
		case (Port_b_pin_4):
		case (Port_b_pin_5):
		case (Port_b_pin_6):
		case (Port_b_pin_7):
		
		port = B;
		
		break;
		
		case (Port_c_pin_0):
		case (Port_c_pin_1):
		case (Port_c_pin_2):
		case (Port_c_pin_3):
		case (Port_c_pin_4):
		case (Port_c_pin_5):
		case (Port_c_pin_6):
		case (Port_c_pin_7):
		
		port = C;
		
		break;
		
		case (Port_d_pin_0):
		case (Port_d_pin_1):
		case (Port_d_pin_2):
		case (Port_d_pin_3):
		case (Port_d_pin_4):
		case (Port_d_pin_5):
		case (Port_d_pin_6):
		case (Port_d_pin_7):
		
		port = D;
		
		break;
	}
	
	return (port);
}

static u8 GetPinNumber (Enum_Pins pin)
{
	u8 pin_number;
	
	switch (pin)
	{
		case (Port_a_pin_0):
		case (Port_b_pin_0):
		case (Port_c_pin_0):
		case (Port_d_pin_0):
		
		pin_number = 0;
		
		break;
		
		case (Port_a_pin_1):
		case (Port_b_pin_1):
		case (Port_c_pin_1):
		case (Port_d_pin_1):
		
		pin_number = 1;
		
		break;
		
		case (Port_a_pin_2):
		case (Port_b_pin_2):
		case (Port_c_pin_2):
		case (Port_d_pin_2):
		
		pin_number = 2;
		
		break;
		
		case (Port_a_pin_3):
		case (Port_b_pin_3):
		case (Port_c_pin_3):
		case (Port_d_pin_3):
		
		pin_number = 3;
		
		break;
		
		case (Port_a_pin_4):
		case (Port_b_pin_4):
		case (Port_c_pin_4):
		case (Port_d_pin_4):
		
		pin_number = 4;
		
		break;
		
		case (Port_a_pin_5):
		case (Port_b_pin_5):
		case (Port_c_pin_5):
		case (Port_d_pin_5):
		
		pin_number = 5;
		
		break;
		
		case (Port_a_pin_6):
		case (Port_b_pin_6):
		case (Port_c_pin_6):
		case (Port_d_pin_6):
		
		pin_number = 6;
		
		break;
		
		case (Port_a_pin_7):
		case (Port_b_pin_7):
		case (Port_c_pin_7):
		case (Port_d_pin_7):
		
		pin_number = 7;
		
		break;
	}
	
	return (pin_number);
}