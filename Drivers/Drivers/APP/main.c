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
#include "../MCAL/WDT_interface.h"
#include "../MCAL/UART_interface.h"
#include <util/delay.h>

uint8 receivedValue ;
uint16* ptr = NULL;
uint16 analogValue = 0;
uint8 percentage = 0;


int main(void)
{
	DIO_voidSetPinDirection(PORTA_ID,PIN0_ID,INPUT_PIN);
	ADC_init();
	LCD_init();
	UART_init(9600);
	LCD_moveCursor(0,0);
	LCD_displayString("Temp: ");
	

    while (1) 
    {	
		ADC_readChannel(CH_0,ptr);
		analogValue = (*ptr * 5000UL)/1023;
		percentage = (analogValue*100UL)/1023;
		UART_receive(&receivedValue);
		UART_transmit(percentage);
		LCD_moveCursor(0,5);
		LCD_intgerToString(receivedValue);
	}
}

