/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 8 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 

#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

u8 EEPROM_Read(u16 Address)
{
	EEARL=(u8)(Address);
	EEARH=(u8)(Address>>8);
	SET_BIT(EECR,EERE);
	return EEDR;
	
}
void EEPROM_Write(u16 Address, u8 Data)
{
	
	EEARL=(u8)(Address);
	EEARH=(u8)(Address>>8);
	EEDR=Data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while((EECR & (1<<EEWE)));
	
}
