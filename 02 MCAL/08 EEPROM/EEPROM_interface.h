/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 8 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 

#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

u8 EEPROM_Read(u16 Address);
void EEPROM_Write(u16 Address, u8 Data);

#endif 