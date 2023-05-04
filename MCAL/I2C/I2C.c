/*
 * I2C.c
 *
 * Created: 04/05/2023 05:01:17 م
 *  Author: Abdelsattar
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "I2C.h"
#define PRESCALAR 1
/* Functions for Master*/
void I2C_vInit(u32 SCL_Freq)
{
	/* Set SCL */
	TWBR=(u8)(((F_CPU/SCL_Freq)-16)/(2*PRESCALAR));
		 if (1==PRESCALAR)
		{   TWSR=0; } 
	else if (4==PRESCALAR)
		{	TWSR=1;	}
	else if (16==PRESCALAR)
		{   TWSR=2;	}
	else if (64==PRESCALAR)
		{   TWSR=3; }
	TWCR=(1<<TWEN);
}
void I2C_Start(void)
{
	TWCR= ( 1<<TWINT ) | ( 1<<TWEN ) | ( 1<<TWSTA ) ;
	while(READ_BIT(TWCR,TWINT)==0);
	
	while ((TWSR & 0XF8) != 0x08); // start condition has been transmitted
}
void I2C_Write_address(u8 address)
{
	TWDR=address;//adress is 7 bit and 0's bit is R/Not Write bit
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x18); // SLA+write has been transmitted and ACK has been received
}
void I2C_Write_Data(u8 data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x28); // data has been transmitted and ACK has been received
}
void I2C_Stop(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

/* Functions for Slave */
void I2C_Set_address(u8 address)
{
	TWAR=address;
}

u8   I2C_Read_Data(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);// Enable sending ACK after reading or receiving data TWEA=1
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x60); // own SLA+W has been received and ACK has been returned
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x80);
	return TWDR;
}
