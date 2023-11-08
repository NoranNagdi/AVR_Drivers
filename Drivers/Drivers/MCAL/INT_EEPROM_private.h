/*
 * INT_EEPROM_private.h
 *
 * Created: 11/4/2023 6:03:51 PM
 *  Author: DELL
 */ 


#ifndef INT_EEPROM_PRIVATE_H_
#define INT_EEPROM_PRIVATE_H_

#include "../Std_Types.h"


/*INTERNAL EEPROM Registers*/
#define EEDR     *((volatile uint8*)(0x3D))
#define EECR     *((volatile uint8*)(0x3C))
#define EEARH    *((volatile uint8*)(0x3F))
#define EEARL    *((volatile uint8*)(0x3E))

#define EEAR     *((volatile uint16*)(0x3E))


/*EECR bits*/
typedef enum{
	EERE,EEWE,EEMWE,EERIE
}EECR_bits;



#endif /* INT_EEPROM_PRIVATE_H_ */