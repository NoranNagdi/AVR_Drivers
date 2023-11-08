/*
 * I2C_private.h
 *
 * Created: 11/3/2023 2:42:10 PM
 *  Author: DELL
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/* I2C Status Bits in the TWSR Register */
#define I2C_START         0x08 /* start has been sent */
#define I2C_REP_START     0x10 /* repeated start */
#define I2C_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define I2C_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define I2C_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave. */
#define I2C_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave. */
#define I2C_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave. */


#define TWCR    *((volatile uint8*)(0x56))
#define TWDR    *((volatile uint8*)(0x23))
#define TWAR    *((volatile uint8*)(0x22))
#define TWSR    *((volatile uint8*)(0x21))
#define TWBR    *((volatile uint8*)(0x20))

/*TWBR_bits*/
typedef enum{
	TWBR0,TWBR1,TWBR2,TWBR3,TWBR4,TWBR5,TWBR6,TWBR7
}TWBR_bits;


/*TWCR_bits*/
typedef enum{
	TWIE,TWEN=2,TWWC,TWSTO,TWSTA,TWEA,TWINT
}TWCR_bits;

/*TWSR_bits*/
typedef enum{
	TWPS0,TWPS1,TWS3=3,TWS4,TWS5,TWS6,TWS7
}TWSR_bits;

/*TWDR_bits*/
typedef enum{
	TWD0,TWD1,TWD2,TWD3,TWD4,TWD5,TWD6,TWD7
}TWDR_bits;

/*TWAR_bits*/
typedef enum{
	TWGCE,TWA0,TWA1,TWA2,TWA3,TWA4,TWA5,TWA6
}TWAR_bits;



#endif /* I2C_PRIVATE_H_ */