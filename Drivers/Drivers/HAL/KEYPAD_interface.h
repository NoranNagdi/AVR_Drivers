/*
 * KEYPAD_interface.h
 *
 * Created: 10/21/2023 2:54:25 PM
 *  Author: DELL
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "../Std_Types.h"

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH


uint8 KEYPAD_getPressedKey(void);



#endif /* KEYPAD_INTERFACE_H_ */