/*
 * _seven_segment_interface.h
 *
 * Created: 10/21/2023 9:37:28 AM
 *  Author: DELL
 */ 


#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_

#include "../Std_Types.h"


void sevenSegment_init();

void sevenSegment_display(uint8 num);

void display_all(uint16 num);

void enableOne(uint8 com_port,uint8 com_pin);

void disableOne(uint8 com_port,uint8 com_pin);

void sevenSegment_deinit();


#endif /* SEVEN_SEGMENT_INTERFACE_H_ */