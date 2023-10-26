/*
 * PUSHBUTTON_program.c
 *
 * Created: 10/20/2023 2:49:55 PM
 *  Author: DELL
 */ 

#include "../HAL/PUSHBUTTON_interface.h"
#include "../MCAL/DIO_interface.h"
#include <util/delay.h>


uint8 buttonIsPressed(uint8 PORTID, uint8 PINID)
{
	DIO_voidSetPinDirection(PORTID,PINID,INPUT_PIN);
	if(DIO_voidGetBitValue(PORTID,PINID))
	{
		_delay_ms(30);
		if(DIO_voidGetBitValue(PORTID,PINID))
		{
		return LOGIC_LOW;
		}
		while(DIO_voidGetBitValue(PORTID,PINID));
	}
	else
	{
		return LOGIC_HIGH;
	}
}
