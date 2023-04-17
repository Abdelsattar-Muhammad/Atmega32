/*
 * Button.c
 *
 * Created: 14/04/2023 10:16:08 م
 *  Author: Abdelsattar
 */ 

#include "DIO.h"
void Button_initi(u8 portName,u8 pinNumber)
{
	DIO_vSetPinDir(portName,pinNumber,INPUT);
}
u8 Button_u8Read(u8 portName,u8 pinNumber)
{
	return DIO_u8GetPinValue(portName,pinNumber);
}
void Button_Pullup_initi(u8 portName,u8 pinNumber)
{
	DIO_vSetPullupPin(portName,pinNumber);
}