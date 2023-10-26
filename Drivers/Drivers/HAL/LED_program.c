/*
 * LED_program.c
 *
 * Created: 10/20/2023 11:46:08 AM
 *  Author: DELL
 */ 
#include "../MCAL/DIO_interface.h"
#include "../HAL/LED_interface.h"
#define F_CPU 16000000
#include <util/delay.h>


void LED_ON(uint8 PORTID, uint8 PINID)
{
	DIO_voidSetPinDirection(PORTID,PINID,OUTPUT_PIN);
	DIO_voidSetPinValue(PORTID, PINID, LOGIC_HIGH);
}

void LED_OFF(uint8 PORTID, uint8 PINID)
{
	DIO_voidSetPinDirection(PORTID,PINID,OUTPUT_PIN);
	DIO_voidSetPinValue(PORTID, PINID, LOGIC_LOW);
}
void LED_TOGGLE(uint8 PORTID, uint8 PINID)
{
	DIO_voidSetPinDirection(PORTID,PINID,OUTPUT_PIN);
	
	DIO_voidSetPinValue(PORTID, PINID, LOGIC_HIGH);
	_delay_ms(3000);
	DIO_voidSetPinValue(PORTID, PINID, LOGIC_LOW);
	_delay_ms(3000);
}