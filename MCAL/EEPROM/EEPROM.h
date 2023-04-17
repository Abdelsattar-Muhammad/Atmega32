/*
 * EEPROM.h
 *
 * Created: 17/04/2023 02:47:28 ص
 *  Author: Abdelsattar
 */ 

#include "data_types.h"
#include "std_macro.h"
#ifndef EEPROM_H_
#define EEPROM_H_

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