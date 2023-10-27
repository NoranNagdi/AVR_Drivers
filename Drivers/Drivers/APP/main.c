/*
 * GccApplication1.c
 *
 * Created: 10/20/2023 10:48:35 AM
 * Author : DELL
 */ 
#define F_CPU 16000000
#include "../MCAL/DIO_interface.h"
#include "../MCAL/GIE_interface.h"
#include "../MCAL/EXT_interface.h"
#include "../MCAL/ADC_interface.h"
#include "../HAL/LED_interface.h"
#include "../HAL/LCD_interface.h"
#include "../HAL/PUSHBUTTON_interface.h"
#include "../HAL/seven_segment_interface.h"
#include "../HAL/KEYPAD_interface.h"
#include "../MCAL/TIMER_interface.h"
#include <util/delay.h>

#define MICRO 0
#define MILLI 1
#define SECOND 2

uint8 sec=0,min=0,hour=0;

void toggle(void)
{
	static uint16 no_of_ovfs = 0;
	
	no_of_ovfs++;
	if(no_of_ovfs == 1000)
	{
		sec++;
		if(sec == 60)
		{
			sec = 0;
			min++;
		}
		if(min == 60)
		{
			min = 0;
			hour++;
		}
		if(hour == 24)
		{
			sec = 0;
			min = 0;
			hour = 0;
		}
		no_of_ovfs = 0;
	}
}
int main(void)
{
	LED_init(RED_LED_PORT,RED_LED_PIN);
	TIMER0_callback(CTC_MODE,toggle);
	TIMER0_init();
	GIE_enable();
	LCD_init();
	LCD_displayString("00:00:00");

    while (1) 
    {	
		if(sec<10)
		{
			LCD_moveCursor(0,7);
			LCD_intgerToString(sec);
		}
		else
		{
			LCD_moveCursor(0,6);
			LCD_intgerToString(sec);
		}
		if(min<10)
		{
			LCD_moveCursor(0,4);
			LCD_intgerToString(min);
		}
		else
		{
			LCD_moveCursor(0,3);
			LCD_intgerToString(min);
		}
		if(hour<10)
		{
			LCD_moveCursor(0,1);
			LCD_intgerToString(hour);
		}
		else
		{
			LCD_moveCursor(0,0);
			LCD_intgerToString(hour);
		}
    }
}

