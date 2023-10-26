/*
 * LED_interface.h
 *
 * Created: 10/20/2023 11:46:46 AM
 *  Author: DELL
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


void LED_ON(uint8 PORTID, uint8 PINID);

void LED_OFF(uint8 PORTID, uint8 PINID); 

void LED_TOGGLE(uint8 PORTID, uint8 PINID);

#endif /* LED_INTERFACE_H_ */