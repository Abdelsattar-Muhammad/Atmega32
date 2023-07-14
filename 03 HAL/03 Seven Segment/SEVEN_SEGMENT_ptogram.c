/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "SEVEN_SEGMENT_interface.h"
	

void SEVEN_SEG_Init(PORT_t Copy_PortName)
{
	DIO_vSetPortDirection(Copy_PortName,0xFF);
}


void SEVEN_SEG_Write(PORT_t Copy_PortName,u8 Copy_u8Number)
{
	u8 arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
		
	#if defined COMMON_CATHOD
	DIO_vSetPortValue(Copy_PortName,arr[Copy_u8Number]);
	#elif defined COMMON_ANODE 
	DIO_vSetPortValue(Copy_PortName,~arr[Copy_u8Number]);
	#endif
}

void SEVEN_SEG_BCD_Init(PORT_t Copy_PortName)//low niblle
{
	DIO_vSetPinDirection(Copy_PortName,Pin0,OUTPUT);
	DIO_vSetPinDirection(Copy_PortName,Pin1,OUTPUT);
	DIO_vSetPinDirection(Copy_PortName,Pin2,OUTPUT);
	DIO_vSetPinDirection(Copy_PortName,Pin3,OUTPUT);
}


void SEVEN_SEG_BCD_Write(PORT_t Copy_PortName,u8 Copy_u8Number)
{
	DIO_vSetPinValue(Copy_PortName,Pin0,GET_BIT(Copy_u8Number,0));
	DIO_vSetPinValue(Copy_PortName,Pin1,GET_BIT(Copy_u8Number,1));
	DIO_vSetPinValue(Copy_PortName,Pin2,GET_BIT(Copy_u8Number,2));
	DIO_vSetPinValue(Copy_PortName,Pin3,GET_BIT(Copy_u8Number,3));
}


