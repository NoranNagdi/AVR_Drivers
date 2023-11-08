/*
 * I2C_interface.h
 *
 * Created: 11/3/2023 2:42:29 PM
 *  Author: DELL
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "../Std_Types.h"


typedef enum {
	I2C_ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_MT_SLA_W_Error,
	I2C_MR_SLA_R_Error,
	I2C_MT_Data_Error,
	I2C_MR_Data_Error,

}I2C_Error;


void I2C_MASTER_init(void);
 
void I2C_SLAVE_init(uint8 slaveAddress);

I2C_Error I2C_sendStartCondition(void);

I2C_Error I2C_sendRepeatedStartCondition(void);

I2C_Error I2C_sendSlaveAddressWrite(uint8 slaveAddress);

I2C_Error I2C_sendSlaveAddressRead(uint8 slaveAddress);

I2C_Error I2C_sendMasterSendByte(uint8 data);

I2C_Error I2C_sendMasterReadByte(uint8 *data);

void I2C_sendStopCondition(void);

void I2C_SLAVE_receive(uint8* value);
 
uint8 I2C_getStatus(void);




#endif /* I2C_INTERFACE_H_ */