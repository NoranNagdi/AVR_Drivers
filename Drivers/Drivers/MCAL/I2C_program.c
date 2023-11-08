/*
 * I2C_program.c
 *
 * Created: 11/3/2023 2:41:52 PM
 *  Author: DELL
 */ 

#include "../MCAL/I2C_interface.h"
#include "../MCAL/I2C_cfg.h"
#include "../MCAL/I2C_private.h"
#include "../MCAL/DIO_interface.h"
#include "../Common_Macros.h"
#include "../Std_Types.h"


void I2C_MASTER_init(void)
{
	/*Set prescaler*/
	CLEAR_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	
    /*Set CLK 100kHZ -> Fcpu= 16MHZ */
	TWBR = 72;
	
	/*activate ACK*/
	SET_BIT(TWCR,TWEA);
	
	/*activate I2C*/
	SET_BIT(TWCR,TWEN);
}

void I2C_SLAVE_init(uint8 slaveAddress)
{
	/*Set Slave Address*/
	TWAR = slaveAddress<<1;
	 
	/*activate ACK*/
	SET_BIT(TWCR,TWEA);
	
	/*activate I2C*/
	SET_BIT(TWCR,TWEN);
}

I2C_Error I2C_sendStartCondition(void)
{
	I2C_Error errorType = I2C_ok;
	
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWINT);
	while(BIT_IS_CLEAR(TWCR,TWINT));
	
	if(I2C_getStatus() != I2C_START)
	{
		errorType = I2C_SC_Error;
	}
	return errorType;
}

I2C_Error I2C_sendRepeatedStartCondition(void)
{
	I2C_Error errorType = I2C_ok;
	
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWINT);
	while(BIT_IS_CLEAR(TWCR,TWINT));
	
	if(I2C_getStatus() != I2C_REP_START)
	{
		errorType = I2C_RSC_Error;
	}
	return errorType;
}

I2C_Error I2C_sendSlaveAddressWrite(uint8 slaveAddress)
{
	I2C_Error errorType = I2C_ok;
	
	/*Set Slave Address*/
	TWDR = slaveAddress<<1;
	
	 /*Write Operation R/W bit*/
	 CLEAR_BIT(TWDR,TWD0);
	 
	 /*Clear start condition*/
	 CLEAR_BIT(TWCR,TWSTA);
	 
	 /*clear flag*/
	 SET_BIT(TWCR,TWINT);
	 
	 while(BIT_IS_CLEAR(TWCR,TWINT));
	 
	 if(I2C_getStatus() != I2C_MT_SLA_W_ACK)
	 {
		 errorType = I2C_MT_SLA_W_Error;
	 }
	 return errorType;
}

I2C_Error I2C_sendSlaveAddressRead(uint8 slaveAddress)
{
	I2C_Error errorType = I2C_ok;
	
	/*Set Slave Address*/
	TWDR = slaveAddress<<1;
	
	/*Write Operation R/W bit*/
	SET_BIT(TWDR,TWD0);
	
	/*Clear start condition*/
	CLEAR_BIT(TWCR,TWSTA);
	
	/*clear flag*/
	SET_BIT(TWCR,TWINT);
	
	while(BIT_IS_CLEAR(TWCR,TWINT));
	
	if(I2C_getStatus() != I2C_MT_SLA_R_ACK)
	{
		errorType = I2C_MT_SLA_R_ACK;
	}
	return errorType;
}

I2C_Error I2C_sendMasterSendByte(uint8 data)
{
	I2C_Error errorType = I2C_ok;
	
	TWDR = data;
	
	/*clear flag*/
	SET_BIT(TWCR,TWINT);
	
	while(BIT_IS_CLEAR(TWCR,TWINT));
	
	if(I2C_getStatus() != I2C_MT_DATA_ACK)
	{
		errorType = I2C_MT_Data_Error;
	}
	return errorType;
}

I2C_Error I2C_sendMasterReadByte(uint8 *data)
{
	I2C_Error errorType = I2C_ok;
	
	/*clear flag*/
	SET_BIT(TWCR,TWINT);
	
	while(BIT_IS_CLEAR(TWCR,TWINT));
	
	if(I2C_getStatus() != I2C_MR_DATA_ACK)
	{
		errorType = I2C_MR_Data_Error;
	}
	else
	{
		*data = TWDR;
	}
	return errorType;
}

void I2C_sendStopCondition(void)
{
	SET_BIT(TWCR,TWSTO);
	SET_BIT(TWCR,TWINT);
}

void I2C_SLAVE_receive(uint8* value)
{
	while(BIT_IS_CLEAR(TWCR,TWINT));
	TWDR = *value;
	SET_BIT(TWCR,TWINT);
}

uint8 I2C_getStatus(void)
{
	uint8 status;
	/* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	status = TWSR & 0xF8;
	return status;
}