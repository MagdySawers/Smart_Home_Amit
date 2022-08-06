#include "LCD.h"


/* Command Codes

// 0x02 -> return home
// 0x28 -> 4-bit mode, 2 lines, 5*7
// 0x38 -> 8-bit mode, 2 lines, 5*7
// 0x0E -> display on, cursor on, and blinking on
// 0x08 -> display off, cursor off
// 0x01 -> clear display screen
// 0x04 -> shift cursor left on each character
// 0x06 -> shift cursor right on each character
// 0x05 -> shift display right
// 0x07 -> shift display left
// 0x80 -> force cursor to beginning of first line
// 0x81 -> cursor line 1 position 1
// 0x82 -> cursor line 1 position 2
// 0x83 -> cursor line 1 position 3
// .. and so on
// 0xC0 -> force cursor to beginning of second line
// 0xC1 -> cursor line 2 position 1
// 0xC2 -> cursor line 2 position 2
// 0xC3 -> cursor line 2 position 3
// .. and so on

*/

Enum_Pins Rs = Port_b_pin_1;
Enum_Pins Rw = Port_b_pin_2;
Enum_Pins Enable = Port_b_pin_3;
Enum_Pins Data4 = Port_a_pin_4;
Enum_Pins Data5 = Port_a_pin_5;
Enum_Pins Data6 = Port_a_pin_6;
Enum_Pins Data7 = Port_a_pin_7;


void LCD_Init()
{
	// Enable-> B3.
	DIO_SetPinDirection(Enable, Output);
	
	// Rw-> B2 (1 = write, 0 = read)
	DIO_SetPinDirection(Rw, Output);
	
	// Rs-> B1 (sending data = 1, or command = 0)
	DIO_SetPinDirection(Rs, Output);
	// set Rw as write
	DIO_SetPinValue(Rw, Low);// always write data
	
	// data pins
	DIO_SetPinDirection(Data4, Output);
	DIO_SetPinDirection(Data5, Output);
	DIO_SetPinDirection(Data6, Output);
	DIO_SetPinDirection(Data7, Output);
	
	// min time to wait until the volt reaches the display is 39 ms
	_delay_ms(1);
	
// 	LCD_Command(Command_4bit_mode);
// 	LCD_Command(Command_return_home);
// 	LCD_Command(Command_display_on);
// 	LCD_Command(Command_clear_display);
// 	_delay_ms(1);
// 	LCD_Command(Command_shift_cursor_right);

LCD_Command(0x02);
LCD_Command(0x28);
LCD_Command(0x0F);
LCD_Command(0x01);
_delay_ms(100);
LCD_Command(0x06);





}

void LCD_Command(u8 command)
{
	// every command requires:
	// 1- reset, 2- write, 3- reactive the enable
	DIO_SetPinValue(Rs, Low);
	
	DIO_SetPinValue(Data7, (Enum_Volt_Value)  GetBit(command, 7));
	DIO_SetPinValue(Data6, (Enum_Volt_Value)  GetBit(command, 6));
	DIO_SetPinValue(Data5, (Enum_Volt_Value)  GetBit(command, 5));
	DIO_SetPinValue(Data4, (Enum_Volt_Value)  GetBit(command, 4));
	LCD_Trigger();
	DIO_SetPinValue(Data7, (Enum_Volt_Value)  GetBit(command, 3));
	DIO_SetPinValue(Data6, (Enum_Volt_Value)  GetBit(command, 2));
	DIO_SetPinValue(Data5, (Enum_Volt_Value)  GetBit(command, 1));
	DIO_SetPinValue(Data4, (Enum_Volt_Value)  GetBit(command, 0));
	LCD_Trigger();
}

void LCD_Command_8bitVersion(u8 command)
{
	// every command requires:
	// 1- reset, 2- write, 3- reactive the enable
	DIO_SetPinValue(Rs, High);
	DIO_SetPortValue(A, command);
	LCD_Trigger();
}

void LCD_WriteChar(u8 data)
{
	// every command requires:
	// 1- reset, 2- write, 3- reactive the enable
	DIO_SetPinValue(Rs, High);
	
	DIO_SetPinValue(Data7, (Enum_Volt_Value) GetBit(data, 7));
	DIO_SetPinValue(Data6, (Enum_Volt_Value)  GetBit(data, 6));
	DIO_SetPinValue(Data5, (Enum_Volt_Value)  GetBit(data, 5));
	DIO_SetPinValue(Data4, (Enum_Volt_Value)  GetBit(data, 4));
	LCD_Trigger();
	DIO_SetPinValue(Data7, (Enum_Volt_Value)  GetBit(data, 3));
	DIO_SetPinValue(Data6, (Enum_Volt_Value)  GetBit(data, 2));
	DIO_SetPinValue(Data5, (Enum_Volt_Value)  GetBit(data, 1));
	DIO_SetPinValue(Data4, (Enum_Volt_Value) GetBit(data, 0));
	LCD_Trigger();
}

void LCD_WriteChar_8bitVersion(u8 data)
{
	// every command requires:
	// 1- reset, 2- write, 3- reactive the enable
	DIO_SetPinValue(Rs, Low);
	DIO_SetPortValue(A, data);
	LCD_Trigger();
}

void LCD_WriteString(u8* text)
{
	while(*text != '\0')
	{
		LCD_WriteChar(*text);
		text++;
	}
}

void LCD_WriteNumber(int number)
{
	u8 reminder = 0;
	s8 arr[10];
	s8 i = 0;
	if(number == 0)
	{
		LCD_WriteChar('0');
		return;
	}
	else if(number < 0)
	{
		number*= -1;
		LCD_WriteChar('-');
	}
	
	while (number > 0)
	{
		reminder = number % 10;
		reminder = reminder + '0';
		arr[i] = (char)reminder;
		number = number / 10;
		i++;
	}
	
	// j>=0, j must be a signed number
	for(s8 j = i-1; j >= 0; j--)
	{
		LCD_WriteChar(arr[j]);
	}
}

void SetCursorPosition(u8 xPosition, u8 yPosition)
{
	u8 address = 0;
	
	if (yPosition == 0)
	address = Command_cursor_on_first_line;
	else if (yPosition == 1)
	address = Command_cursor_on_second_line;
	
	if (xPosition < 16)
	address += xPosition;
	
	LCD_Command(address);
}

void LCD_Trigger()
{
	DIO_SetPinValue(Enable, High);
	_delay_ms(1);
	DIO_SetPinValue(Enable, Low);
	_delay_ms(1);
}

void LCD_Go_To(u8 row, u8 col)
{
	switch(row)
	{
		case 0:
		LCD_Command(0x80 + col); 
		break;
		case 1:
		LCD_Command(0x80 + 0x40 +col);
		
		break;
	}
}