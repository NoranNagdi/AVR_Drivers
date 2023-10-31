/*
 * WDT_program.c
 *
 * Created: 10/29/2023 10:13:08 AM
 *  Author: DELL
 */ 
#include "../MCAL/WDT_interface.h"
#include "../MCAL/WDT_cfg.h"
#include "../MCAL/WDT_private.h"
#include "../Common_Macros.h"

void WDT_enable(void)
{
	/*select pre scaler*/
	SET_BIT(WDTCR,WDP0); 
	SET_BIT(WDTCR,WDP1); 
	SET_BIT(WDTCR,WDP2); 
	
	/*enable WDT*/
	SET_BIT(WDTCR,WDE);
}

void WDT_disable(void)
{
	WDTCR = 0x18; //set bit 3,4 at the same time 
	CLEAR_BIT(WDTCR,WDE);
}