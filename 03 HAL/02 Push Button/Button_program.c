/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "Button_interface.h"

void Button_Init(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber)
{
	DIO_vSetPinDirection(Copy_u8PortName,Copy_u8PinNumber,INPUT);
}
void Button_PullupInit(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber)
{
	DIO_vSetPullupPin(Copy_u8PortName,Copy_u8PinNumber);
	
}
u8 	 Button_u8Read(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber)
{
	u8 Local_u8Value=0;
	Local_u8Value=DIO_u8GetPinValue(Copy_u8PortName,Copy_u8PinNumber);
	return Local_u8Value;
}
