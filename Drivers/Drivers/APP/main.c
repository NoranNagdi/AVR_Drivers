/*
 * GccApplication1.c
 *
 * Created: 10/20/2023 10:48:35 AM
 * Author : DELL
 */ 
#define F_CPU 16000000
#include "../HAL/LED_cfg.h"
#include "../HAL/LED_interface.h"
#include "../HAL/PUSHBUTTON_cfg.h"
#include "../HAL/PUSHBUTTON_interface.h"
#include "../MCAL/DIO_interface.h"
#include "../HAL/seven_segment_interface.h"
#include "../HAL/seven_segment_cfg.h"
#include "../HAL/LCD_interface.h"
#include "../HAL/LCD_cfg.h"
#include "../HAL/KEYPAD_interface.h"
#include "../HAL/KEYPAD_cfg.h"
#include "../MCAL/GIE_interface.h"
#include "../MCAL/EXT_interface.h"
#include "../MCAL/ADC_interface.h"
#include "../Std_Types.h"
#include "util/delay.h"


uint16* ptr1 = 0;
uint16* ptr2 = 0;

uint16 analogValue = 0;
uint16 tempValue = 0;

void interrupt1(void)
{
	ADC_autotrigger_init();
	ADC_autotrigger_readChannel(CH_1,ptr2);
	tempValue = ((*ptr2 * 5000UL)/1024)/10;
	
}
int main(void)
{
	DIO_voidSetPinDirection(PORTA_ID,PIN0_ID,INPUT_PIN);
	DIO_voidSetPinDirection(PORTA_ID,PIN1_ID,INPUT_PIN);
	
	DIO_voidSetPinDirection(PORTD_ID,PIN5_ID,INPUT_PIN);
	
	LCD_init();
	LCD_displayString("LDR ");
	//EXT_callback(EXT_0, interrupt0);
	EXT_init(EXT_0, FALLING);
	
	EXT_callback(EXT_1, interrupt1);
	EXT_init(EXT_1, FALLING);
	
	ADC_init();
	GIE_enable();

    while (1) 
    {	
		ADC_init();
		ADC_readChannel(CH_0,ptr1);
		analogValue = (*ptr1 * 5000UL)/1024;
		LCD_moveCursor(0,5);
		LCD_intgerToString(analogValue);
		
		LCD_moveCursor(1,0);
		LCD_displayString("Temp ");
		LCD_moveCursor(1,6);
		LCD_intgerToString(tempValue);
		
    }
}

