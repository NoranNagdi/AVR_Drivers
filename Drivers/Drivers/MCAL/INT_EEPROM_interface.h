/*
 * INT_EEPROM_interface.h
 *
 * Created: 11/4/2023 6:04:13 PM
 *  Author: DELL
 */ 


#ifndef INT_EEPROM_INTERFACE_H_
#define INT_EEPROM_INTERFACE_H_

#include "../Std_Types.h"


void INT_EEPROM_init(void);

void INT_EEPROM_writeData(uint16 Address , uint8 data);

void INT_EEPROM_readData(uint16 Address , uint8* data);


#endif /* INT_EEPROM_INTERFACE_H_ */