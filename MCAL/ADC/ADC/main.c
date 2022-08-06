#include <avr/io.h>
#include "ADC/ADC.h"
#include "LCD.h"
#include "type_def.h"

int main(void)
{
	ADC_Init(Volt_Vcc, 2, 1);
	LCD_Init();
	
    while (1) 
    {
		u16 val = ADC_Read(1);
		LCD_Go_To(0, 0);
		//LCD_Command(Command_clear_display);
		LCD_WriteNumber(val);
		_delay_ms(500);
    }
}