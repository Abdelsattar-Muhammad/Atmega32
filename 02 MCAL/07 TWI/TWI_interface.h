/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 8 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

// Master as Transmitter

/* Frame OF I2C As Transmitter
(1-bit)S + (8-bit)ADDRESS+(R/W) + (1-bit) ACK + (8-bit) DATA + (1-bit) ACK +(1-bit) STOP
*/
void TWI_Master_Init(u32 SCL_Freq);
void TWI_Start(void);
void TWI_Write_Address(u8 SLA_W );
void TWI_Write_Data(u8 Copy_u8Data);
void TWI_Stop(void);
// Master as Receiver
u8   TWI_Read_with_NACK(void);
// Slave as Receiver
void TWI_Set_Address(u8 Address);
u8 	 TWI_Slave_Read(void);

#endif