#include "DIO.h"
#include "type_def.h"
#include "bit_operations.h"
#define F_CPU 16000000
#include <avr/delay.h>

#ifndef INCFILE1_H_
#define INCFILE1_H_

//Enum_Pins Enable = Port_b_pin_3;
//Enum_Pins Rs = Port_b_pin_1;
//Enum_Pins Rw = Port_b_pin_2;
//Enum_Pins Data1 = Port_a_pin_4;
//Enum_Pins Data2 = Port_a_pin_5;
//Enum_Pins Data3 = Port_a_pin_6;
//Enum_Pins Data4 = Port_a_pin_7;

//define Enable Enum_Pins.Port_b_pin_3
//define Rs Enum_Pins.Port_b_pin_1
//define Rw Enum_Pins.Port_b_pin_2
//define Data1 Enum_Pins.Port_a_pin_4
//define Data2 Enum_Pins.Port_a_pin_5
//define Data3 Enum_Pins.Port_a_pin_6
//define Data4 Enum_Pins.Port_a_pin_7

#define Command_clear_display 0x01
#define Command_return_home 0x02
#define Command_4bit_mode 0x28
#define Command_8bit_mode 0x38
#define Command_display_on 0x0E
#define Command_display_off 0x08
#define Command_shift_cursor_left 0x04
#define Command_shift_cursor_right 0x06
#define Command_shift_display_right 0x05
#define Command_shift_display_left 0x07
#define Command_cursor_on_first_line 0x80
#define Command_cursor_on_second_line 0xC0


void LCD_Init();
void LCD_Command(u8 address);
void LCD_WriteChar(u8 data);
void LCD_Command_8bitVersion(u8 command);
void LCD_WriteChar_8bitVersion(u8 data);
void LCD_WriteString(u8* text);
void LCD_WriteNumber(int number);
void LCD_Trigger();
void SetCursorPosition(u8 xPosition, u8 yPosition);
void LCD_Go_To(u8 row, u8 col);

#endif /* INCFILE1_H_ */