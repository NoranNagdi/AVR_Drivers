/*
 * WDT_private.h
 *
 * Created: 10/29/2023 10:13:28 AM
 *  Author: DELL
 */ 


#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#include "../Std_Types.h"

#define WDTCR  *((volatile uint8*)(0x41))


/*WDTCR_bits*/
typedef enum{
	WDP0,WDP1,WDP2,WDE,WDTOE
}WDTCR_bits;


#endif /* WDT_PRIVATE_H_ */