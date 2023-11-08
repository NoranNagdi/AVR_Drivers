/*
 * INT_EEPROM_program.c
 *
 * Created: 11/4/2023 6:03:23 PM
 *  Author: DELL
 */ 

#include "../MCAL/INT_EEPROM_interface.h"
#include "../MCAL/INT_EEPROM_cfg.h"
#include "../MCAL/INT_EEPROM_private.h"
#include "../Common_Macros.h"

#include "../HAL/LCD_interface.h"

void INT_EEPROM_init(void)
{
	/*Disable Interrupts*/
	CLEAR_BIT(EECR,EERIE);
}

void INT_EEPROM_writeData(uint16 Address , uint8 data)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));

	/*Set the address*/
	EEAR = Address;
	
	/*write the data*/
	EEDR = data;

	/*Set EEMWE and clear EEWE at the same time*/
	EECR = 0x04;
	
	/*Enable writing bit*/
	SET_BIT(EECR,EEWE);
}

void INT_EEPROM_readData(uint16 Address , uint8* data)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));

	/*Set the address*/
	EEAR = Address;
	
	/*Enable reading bit*/
	SET_BIT(EECR,EERE);
	
	/*read the data*/
	*data = EEDR;	
}