/*
 * _7_Segment.c
 *
 * Created: 16/04/2023 01:32:32 ص
 *  A uthor: Abdelsattar
 */ 
#include "DIO.h"
#include "SEVEN_SEGMENT.h"
	

void SEVEN_SEG_initi(u8 portName)
{
	DIO_vSetPortDir(portName,OUTPUT);
}


void SEVEN_SEG_Write(u8 portName,u8 Number)
{
	u8 arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
		
	#if defined COMMON_CATHOD
	DIO_vSetPortValue(portName,arr[Number]);
	#elif defined COMMON_ANODE 
	DIO_vSetPortValue(portName,~arr[Number]);
	#endif
	
}

void SEVEN_SEG_BCD_initi(u8 portName)//low niblle
{
	DIO_vSetPortLowNibbleDir(portName,OUTPUT);
}


void SEVEN_SEG_BCD_Write(u8 portName,u8 Number)
{
	DIO_vSetPortLowNibbleValue(portName,Number);
}


