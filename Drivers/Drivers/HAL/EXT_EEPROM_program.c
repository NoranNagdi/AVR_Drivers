/*
 * EXT_EEPROM_program.c
 *
 * Created: 11/4/2023 2:31:14 PM
 *  Author: DELL
 */ 

#include "../MCAL/I2C_interface.h"
#include "../HAL/EXT_EEPROM_interface.h"
#include "../HAL/EXT_EEPROM_cfg.h"
#include "../HAL/EXT_EEPROM_private.h"

void EXT_EEPROM_writeData(uint16 Address , uint8 data)
{
	/*     Send Start Condition      */
	I2C_sendStartCondition();

	/*     Send Fixed Address      */
	I2C_sendSlaveAddressWrite((EEPROM_FIXED_ADDRESS)|(EEPROM_A2_VALUE<<2)|((Address >>8)&3));

	/*     Send  Address     */
	I2C_sendMasterSendByte((uint8)Address);
	
	/*     Send data     */
	I2C_sendMasterSendByte(data);
	
	/*     Send Stop Condition     */
	I2C_sendStopCondition();
}

void EXT_EEPROM_readData(uint16 Address , uint8 * data)
{
	/*     Send Start Condition      */
	I2C_sendStartCondition();

	/*     Send Fixed Address with write      */
	I2C_sendSlaveAddressWrite((EEPROM_FIXED_ADDRESS)|(EEPROM_A2_VALUE<<2)|((Address>>8)&3));
	
	/*     Send Actual Address     */
	I2C_sendMasterSendByte((uint8)Address);
	
	/*     Send Repeated Start Condition      */
	I2C_sendRepeatedStartCondition();
	/*     Send Fixed Address with Read      */
	I2C_sendSlaveAddressRead((EEPROM_FIXED_ADDRESS)|(EEPROM_A2_VALUE<<2)|((Address>>8)&3));
	/*Read Data*/
	I2C_sendMasterReadByte(data);
	/*        STOP CONDITION          */
	I2C_sendStopCondition();
}
