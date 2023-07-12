/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

void LED_Init(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber);
void LED_TurnOn(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber);
void LED_TurnOff(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber);
void LED_Toggle(PORT_t Copy_u8PortName,PINS_t Copy_u8PinNumber);

#endif /* LED_H_ */