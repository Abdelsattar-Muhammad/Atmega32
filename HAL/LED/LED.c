/*
 * LED.c
 *
 * Created: 14/04/2023 06:15:50 ص
 *  Author: Abdelsattar
 */ 

#include "DIO.h"

void LED_initi(u8 portName,u8 pinNumber)
{
	DIO_vSetPinDir(portName,pinNumber,OUTPUT);
}//end function

void LED_On(u8 portName,u8 pinNumber)
{
	DIO_vSetPinValue(portName,pinNumber,HIGH);
}//end function

void LED_Off(u8 portName,u8 pinNumber)
{
	DIO_vSetPinValue(portName,pinNumber,LOW);
}//end function

void LED_TOGGLE(u8 portName,u8 pinNumber)
{
	DIO_vTogglePin(portName,pinNumber);
}//end function