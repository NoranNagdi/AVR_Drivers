/*
 * _seven_segment_program.c
 *
 * Created: 10/21/2023 9:36:09 AM
 *  Author: DELL
 */ 
#define F_CPU 16000000
#include "../Common_Macros.h"
#include "../MCAL/DIO_interface.h"
#include "../HAL/seven_segment_interface.h"
#include "../HAL/seven_segment_cfg.h"
#include <util/delay.h>


void sevenSegment_init()
{
	DIO_voidSetPinDirection(SEVEN_PORT,SEVEN_PIN_1,OUTPUT_PIN);
	DIO_voidSetPinDirection(SEVEN_PORT,SEVEN_PIN_2,OUTPUT_PIN);
	DIO_voidSetPinDirection(SEVEN_PORT,SEVEN_PIN_3,OUTPUT_PIN);
	DIO_voidSetPinDirection(SEVEN_PORT,SEVEN_PIN_4,OUTPUT_PIN);
	
	DIO_voidSetPinDirection(SEVEN_COM_1_2_PORT,SEVEN_COM_1,OUTPUT_PIN);
	DIO_voidSetPinDirection(SEVEN_COM_1_2_PORT,SEVEN_COM_2,OUTPUT_PIN);
	DIO_voidSetPinDirection(SEVEN_COM_3_4_PORT,SEVEN_COM_3,OUTPUT_PIN);
	DIO_voidSetPinDirection(SEVEN_COM_3_4_PORT,SEVEN_COM_4,OUTPUT_PIN);
		
	//DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_1,LOGIC_LOW);
	//DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_2,LOGIC_LOW);
	//DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_3,LOGIC_LOW);
	//DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_4,LOGIC_LOW);
	
	//DIO_voidSetPinValue(SEVEN_PORT,SEVEN_PIN_1,LOGIC_LOW);
	//DIO_voidSetPinValue(SEVEN_PORT,SEVEN_PIN_2,LOGIC_LOW);
	//DIO_voidSetPinValue(SEVEN_PORT,SEVEN_PIN_3,LOGIC_LOW);
	//DIO_voidSetPinValue(SEVEN_PORT,SEVEN_PIN_4,LOGIC_LOW);
	
}

void sevenSegment_deinit()
{
	DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_1,LOGIC_HIGH);
	DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_2,LOGIC_HIGH);
	DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_3,LOGIC_HIGH);
	DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_4,LOGIC_HIGH);
}
void sevenSegment_display(uint8 num)
{
	DIO_voidSetPinValue(SEVEN_PORT,SEVEN_PIN_1,GET_BIT(num,0));
	DIO_voidSetPinValue(SEVEN_PORT,SEVEN_PIN_2,GET_BIT(num,1));
	DIO_voidSetPinValue(SEVEN_PORT,SEVEN_PIN_3,GET_BIT(num,2));
	DIO_voidSetPinValue(SEVEN_PORT,SEVEN_PIN_4,GET_BIT(num,3));		
}

void enableOne(uint8 com_port,uint8 com_pin)
{
	switch(com_port)
	{
		case PORTA_ID:
		if(com_pin == PIN3_ID)
		{
			DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_1,LOGIC_LOW);
			//DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_2,LOGIC_HIGH);
			//DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_3,LOGIC_HIGH);
			//DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_4,LOGIC_HIGH);
		}
		else if(com_pin == PIN2_ID)
		{
			//DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_1,LOGIC_HIGH);
			DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_2,LOGIC_LOW);
			//DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_3,LOGIC_HIGH);
			//DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_4,LOGIC_HIGH);
		}
		break;
		case PORTB_ID:
		if(com_pin == PIN5_ID)
		{
			//DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_1,LOGIC_HIGH);
			//DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_2,LOGIC_HIGH);
			DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_3,LOGIC_LOW);
			//DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_4,LOGIC_HIGH);
		}
		else if(com_pin == PIN6_ID)
		{
			//DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_1,LOGIC_HIGH);
			//DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_2,LOGIC_HIGH);
			//DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_3,LOGIC_HIGH);
			DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_4,LOGIC_LOW);
		}
		break;
	}
}

void disableOne(uint8 com_port,uint8 com_pin)
{
	switch(com_port)
	{
		case PORTA_ID:
		if(com_pin == PIN3_ID)
		{
			DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_1,LOGIC_HIGH);
		}
		else if(com_pin == PIN2_ID)
		{
			DIO_voidSetPinValue(SEVEN_COM_1_2_PORT,SEVEN_COM_2,LOGIC_HIGH);
		}
		break;
		case PORTB_ID:
		if(com_pin == PIN5_ID)
		{
			DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_3,LOGIC_HIGH);
		}
		else if(com_pin == PIN6_ID)
		{
			DIO_voidSetPinValue(SEVEN_COM_3_4_PORT,SEVEN_COM_4,LOGIC_HIGH);
		}
		break;
	}
}

void display_all(uint16 num)
{
	if(num<10000)
	{
		char num1=num/1000;//1
		num=num%1000;//234
		char num2=num/100;//2.34
		num=num%100;//2
		char num3=num/10;//255
		char num4=num%10;
		
		sevenSegment_deinit();
		sevenSegment_display(num4);
		enableOne(SEVEN_COM_1_2_PORT,SEVEN_COM_1);
		_delay_ms(10);
		disableOne(SEVEN_COM_1_2_PORT,SEVEN_COM_1);
		sevenSegment_display(num3);
		enableOne(SEVEN_COM_1_2_PORT,SEVEN_COM_2);
		_delay_ms(10);
		disableOne(SEVEN_COM_1_2_PORT,SEVEN_COM_2);
		sevenSegment_display(num2);
		enableOne(SEVEN_COM_3_4_PORT,SEVEN_COM_3);
		_delay_ms(10);
		disableOne(SEVEN_COM_3_4_PORT,SEVEN_COM_3);
		sevenSegment_display(num1);
		enableOne(SEVEN_COM_3_4_PORT,SEVEN_COM_4);
		_delay_ms(10);
	}
}