/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 June 2023            */
/* Version : V01					*/
/* MCU 	   : ATMEGA32               */
/************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define LOW 0
#define HIGH 1

typedef enum
{
 INPUT=0,
 OUTPUT=1

}DIR_t;


typedef enum
{
 Pin0=0,
 Pin1=1,
 Pin2=2,
 Pin3=3,
 Pin4=4,
 Pin5=5,
 Pin6=6,
 Pin7=7,
}PINS_t;
typedef enum
{
 APORT=0,
 BPORT=1,
 CPORT=2,
 DPORT=3,
}PORT_t;

void DIO_vSetPinDirection(PORT_t Copy_PortName,PINS_t Copy_PinNumber,DIR_t Copy_Direction );

void DIO_vSetPinValue(PORT_t Copy_PortName,PINS_t Copy_PinNumber,u8 value);

u8	 DIO_u8GetPinValue(PORT_t Copy_PortName,PINS_t Copy_PinNumber);

void DIO_vTogglePin(PORT_t Copy_PortName,PINS_t Copy_PinNumber);

void DIO_vSetPullupPin(PORT_t Copy_PortName,PINS_t Copy_PinNumber);


void DIO_vSetPortDirection(PORT_t Copy_PortName,u8 Copy_Direction );

void DIO_vSetPortValue(PORT_t Copy_PortName,u8 value);

u8 DIO_u8GetPortValue(PORT_t Copy_PortName);



#endif