/*
 * I2C.h
 *
 * Created: 04/05/2023 05:01:27 م
 *  Author: Abdelsattar
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "data_types.h"
#include "std_macro.h"
/* Functions for Master*/
void I2C_vInit(u32 SCL_Freq);
void I2C_Start(void);
void I2C_Write_address(u8 address);
void I2C_Write_Data(u8 data);
void I2C_Stop(void);
/* Functions for Slave */
void I2C_Set_address(u8 address);
u8   I2C_Read_Data_With_ACK(void);
u8   I2C_Read_Data_With_NACK(void);
#endif /* I2C_H_ */