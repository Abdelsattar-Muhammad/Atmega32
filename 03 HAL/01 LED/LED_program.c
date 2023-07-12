/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"

/*initialization pin as output at given port*/
void LED_Init(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber)
{
	DIO_vSetPinDirection(Copy_u8PortName,Copy_u8PinNumber,OUTPUT);
	
}

void LED_TurnOn(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber)
{
	DIO_vSetPinValue(Copy_u8PortName,Copy_u8PinNumber,HIGH);
}

void LED_TurnOff(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber)
{
	DIO_vSetPinValue(Copy_u8PortName,Copy_u8PinNumber,LOW);
}

void LED_Toggle(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber)
{
	DIO_vTogglePin(Copy_u8PortName,Copy_u8PinNumber);
}