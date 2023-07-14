/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 8 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 

#ifndef EXT_EEPROM_INTERFACE_H
#define EXT_EEPROM_INTERFACE_H
void External_EEPROM_Write(u16 Address,u8 Date);

u8	 External_EEPROM_Read(u16 Address);
#endif