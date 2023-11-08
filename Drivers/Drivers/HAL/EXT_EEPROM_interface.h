/*
 * EXT_EEPROM_interface.h
 *
 * Created: 11/4/2023 2:32:00 PM
 *  Author: DELL
 */ 
#include "../Std_Types.h"

#ifndef EXT_EEPROM_INTERFACE_H_
#define EXT_EEPROM_INTERFACE_H_

void EXT_EEPROM_writeData(uint16 Address , uint8 data);

void EXT_EEPROM_readData(uint16 Address , uint8 * data);



#endif /* EXT_EEPROM_INTERFACE_H_ */