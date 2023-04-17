/*	
 * EEPROM.c
 *
 * Created: 17/04/2023 02:46:12 ص
 *  Author: Abdelsattar
 */ 

#include "EEPROM.h"

u8 EEPROM_Read(u16 address)
{
	//set address Register
	EEARL=(u8)address;
	EEARH=(u8)(address>>8);
	// Write  Logic 1 To EERE
	SET_BIT(EECR,EERE);
	//Return Data
	return EEDR;
	
}
void EEPROM_Write(u16 address, u8 data)
{
	//set address Register
	EEARL=(u8)address;
	EEARH=(u8)(address>>8);
	//set Data Register
	EEDR=data;
	// Write  Logic 1 To EEMWE & EEWE
	SET_BIT(EECR,EEMWE); //EEMWE will Clear After 4 Clock Cycle
	SET_BIT(EECR,EEWE);
	while(READ_BIT(EECR,EEWE)==1);//after Writing process done EEWE will Clear
}