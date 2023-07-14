/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 8 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "EEPROM_interface.h"
#include "EXT_EEPROM_interface.h"

void External_EEPROM_Write(u16 Address,u8 Date)
{
	u8 Address_H= (u8)((0b10100000)|((Address>>7) & 0x0E));;
	u8 Address_L=(u8)Address;
	TWI_Master_Init(50000);
	_delay_ms(150);
	TWI_Start();
	TWI_Write_Address(Address_H);
	TWI_Write_Data(Address_L);
	TWI_Write_Data(Date);
	TWI_Stop();
}


u8	 External_EEPROM_Read(u16 Address)
{	
	u8 Date=0;
	u8 Address_H= (u8)((0b10100000)|((Address>>7) & 0x0E));
	u8 Address_L=(u8)Address;
	TWI_Master_Init(50000);
	_delay_ms(150);
	TWI_Start();
	TWI_Write_Address(Address_H);
	TWI_Write_Data(Address_L);
	TWI_Start();
	SET_BIT(Address_H,0);
	TWI_Write_Address(Address_H);
	Date=TWI_Read_with_NACK();
	TWI_Stop();
	return Date;
}