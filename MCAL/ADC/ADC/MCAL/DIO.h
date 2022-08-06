#include "type_def.h"

#ifndef DIO_H_
#define DIO_H_

#define Port_A_Address 0x3b
#define Port_B_Address 0x38
#define Port_C_Address 0x35
#define Port_D_Address 0x32

#define DDR_A_Address 0x3a
#define DDR_B_Address 0x37
#define DDR_C_Address 0x34
#define DDR_D_Address 0x31

#define Pin_A_Address 0x39
#define Pin_B_Address 0x36
#define Pin_C_Address 0x33
#define Pin_D_Address 0x30

typedef enum
{
	A, B, C, D
} Enum_Ports;

typedef enum
{
	Port_a_pin_0,
	Port_a_pin_1,
	Port_a_pin_2,
	Port_a_pin_3,
	Port_a_pin_4,
	Port_a_pin_5,
	Port_a_pin_6,
	Port_a_pin_7,
	
	Port_b_pin_0,
	Port_b_pin_1,
	Port_b_pin_2,
	Port_b_pin_3,
	Port_b_pin_4,
	Port_b_pin_5,
	Port_b_pin_6,
	Port_b_pin_7,
	
	Port_c_pin_0,
	Port_c_pin_1,
	Port_c_pin_2,
	Port_c_pin_3,
	Port_c_pin_4,
	Port_c_pin_5,
	Port_c_pin_6,
	Port_c_pin_7,
	
	Port_d_pin_0,
	Port_d_pin_1,
	Port_d_pin_2,
	Port_d_pin_3,
	Port_d_pin_4,
	Port_d_pin_5,
	Port_d_pin_6,
	Port_d_pin_7,
} Enum_Pins;

typedef enum
{
	Input, Output
}Enum_Data_Direction;

typedef enum
{
	Low = 0, High = 1
} Enum_Volt_Value;


void DIO_SetPortDirection (Enum_Ports port, Enum_Data_Direction direction);
void DIO_SetPortValue(Enum_Ports port, u8 val);
void DIO_SetRegisterValue(u8 address, u8 val);

void DIO_SetPinDirection(Enum_Pins pin, Enum_Data_Direction direction);
void DIO_SetPinValue(Enum_Pins pin, Enum_Volt_Value val);

u8 DIO_GetPinValue(Enum_Pins pin);
u8 DIO_GetPortValue(Enum_Ports port);
u8 DIO_GetRegisterValue(u8 address);
void DIO_SetRegisterPin(u8 address, u8 pin_number, Enum_Volt_Value val);

static u8 GetPortAddress(Enum_Ports port);
static u8 GetDDRAddress(Enum_Ports port);
static u8 GetPinAddress(Enum_Ports port);
static Enum_Ports GetPinPort(Enum_Pins pin);
static u8 GetPinNumber (Enum_Pins pin);


#endif /* DIO_H_ */