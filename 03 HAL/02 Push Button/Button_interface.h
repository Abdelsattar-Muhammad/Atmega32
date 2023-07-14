/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

void Button_Init(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber);

void Button_PullupInit(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber);
u8 	 Button_u8Read(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber);




#endif 