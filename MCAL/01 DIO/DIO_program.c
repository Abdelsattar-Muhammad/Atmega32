/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 June 2023            */
/* Version : V01					*/
/* MCU 	   : ATMEGA32               */
/************************************/ 
#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_vSetPinDirection(PORT_t Copy_PortName,PINS_t Copy_PinNumber,DIR_t Copy_Direction )
{
	if (OUTPUT==Copy_Direction)
	{
		switch(Copy_PortName)
		{
			case APORT:
			SET_BIT(DDRA,Copy_PinNumber);
			break;
			case BPORT:
			SET_BIT(DDRB,Copy_PinNumber);
			break;
			case CPORT:
			SET_BIT(DDRC,Copy_PinNumber);
			break;
			case DPORT:
			SET_BIT(DDRD,Copy_PinNumber);
			break;
			
		}//end switch
		
		
	} //end if 
	else
	{
		switch(Copy_PortName)
		{
			case APORT:
			CLR_BIT(DDRA,Copy_PinNumber);
			break;
			case BPORT:
			CLR_BIT(DDRB,Copy_PinNumber);
			break;
			case CPORT:
			CLR_BIT(DDRC,Copy_PinNumber);
			break;
			case DPORT:
			CLR_BIT(DDRD,Copy_PinNumber);
			break;
			}//end switch
		}//end else				
}//end Function

void DIO_vSetPortDirection(PORT_t Copy_PortName,u8 Copy_Direction )
{
		switch(Copy_PortName)
		{
			case APORT:
			DDRA=Copy_Direction;
			break;
			case BPORT:
			DDRB=Copy_Direction;
			break;
			case CPORT:
			DDRC=Copy_Direction;
			break;
			case DPORT:
			DDRD=Copy_Direction;
			break;
			
		}//end switch
		
}//end Function

void DIO_vSetPinValue(PORT_t Copy_PortName,PINS_t Copy_PinNumber,u8 value)
{
	if (HIGH==value)
	{
		switch(Copy_PortName)
		{
			case APORT:
			SET_BIT(PORTA,Copy_PinNumber);
			break;
			case BPORT:
			SET_BIT(PORTB,Copy_PinNumber);
			break;
			case CPORT:
			SET_BIT(PORTC,Copy_PinNumber);
			break;
			case DPORT:
			SET_BIT(PORTD,Copy_PinNumber);
			break;
			
		}//end switch
		
		
	} //end if
	else
	{
		switch(Copy_PortName)
		{
			case APORT:
			CLR_BIT(PORTA,Copy_PinNumber);
			break;
			case BPORT:
			CLR_BIT(PORTB,Copy_PinNumber);
			break;
			case CPORT:
			CLR_BIT(PORTC,Copy_PinNumber);
			break;
			case DPORT:
			CLR_BIT(PORTD,Copy_PinNumber);
			break;
		}//end switch
	}//end else
}//end Function


void DIO_vSetPortValue(PORT_t Copy_PortName,u8 value)
{
		switch(Copy_PortName)
		{
			case APORT:
			PORTA=value;
			break;
			case BPORT:
			PORTB=value;
			break;
			case CPORT:
			PORTC=value;
			break;
			case DPORT:
			PORTD=value;
			break;
			
		}//end switch
		
}//end Function


u8 DIO_u8GetPortValue(PORT_t Copy_PortName)
{
	u8 Loca_u8value=0;
	switch(Copy_PortName)
	{
		case APORT:
		Loca_u8value=PINA;
		break;
		case BPORT:
		Loca_u8value=PINB;
		break;
		case CPORT:
		Loca_u8value=PINC;
		break;
		case DPORT:
		Loca_u8value=PIND;
		break;
	}//end switch
	return Loca_u8value;
}//end function

u8 DIO_u8GetPinValue(PORT_t Copy_PortName,PINS_t Copy_PinNumber)
{
	u8 Loca_u8value=0;
	switch(Copy_PortName)
	{
		case APORT:
		Loca_u8value=GET_BIT(PINA,Copy_PinNumber);
		break;
		case BPORT:
		Loca_u8value=GET_BIT(PINB,Copy_PinNumber);
		break;
		case CPORT:
		Loca_u8value=GET_BIT(PINC,Copy_PinNumber);
		break;
		case DPORT:
		Loca_u8value=GET_BIT(PIND,Copy_PinNumber);
		break;
	}//end switch
	return Loca_u8value;
}//end function


void DIO_vSetPullupPin(PORT_t Copy_PortName,PINS_t Copy_PinNumber)
{
	switch(Copy_PortName)
	{
		case APORT:
		CLR_BIT(DDRA,Copy_PinNumber);
		SET_BIT(PORTA,Copy_PinNumber);
		break;
		case BPORT:
		CLR_BIT(DDRB,Copy_PinNumber);
		SET_BIT(PORTB,Copy_PinNumber);
		break;
		case CPORT:
		CLR_BIT(DDRC,Copy_PinNumber);
		SET_BIT(PORTC,Copy_PinNumber);
		break;
		case DPORT:
		CLR_BIT(DDRD,Copy_PinNumber);
		SET_BIT(PORTD,Copy_PinNumber);
		break;
	}//end switch
	
}		//end function
void DIO_vTogglePin(PORT_t Copy_PortName,PINS_t Copy_PinNumber)
{
	switch(Copy_PortName)
	{
		case APORT:
		TOGGLE_BIT(PORTA,Copy_PinNumber);
		break;
		case BPORT:
		TOGGLE_BIT(PORTB,Copy_PinNumber);
		break;
		case CPORT:
		TOGGLE_BIT(PORTC,Copy_PinNumber);
		break;
		case DPORT:
		TOGGLE_BIT(PORTD,Copy_PinNumber);
		break;
	}//end switch
	
}		//end function
