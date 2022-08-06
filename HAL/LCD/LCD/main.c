#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "type_def.h"
#define F_CPU 16000000
#include <avr/delay.h>

int main(void)
{
	LCD_Init();
	_delay_ms(100);

	while (1)
	{
		for (int i = 0; i < 5; i++)
		{
			LCD_WriteString("Besm 3");
			_delay_ms(10000);
		}
		
		_delay_ms(1000);
	}
}