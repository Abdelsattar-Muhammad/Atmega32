/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 8 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 

#ifndef EEPROM_PRIVATE_H
#define EEPROM_PRIVATE_H

#define EEARL *((volatile u8*)0x3E)
#define EEARH *((volatile u8*)0x3F)
#define EEDR  *((volatile u8*)0x3D)
#define EECR  *((volatile u8*)0x3C)
	
#define EERE	0
#define EEWE	1
#define EEMWE	2
#define EERIE	3

u8 EEPROM_Read(u16 address);
void EEPROM_Write(u16 address, u8 val);

#endif /* EEPROM_H_ */