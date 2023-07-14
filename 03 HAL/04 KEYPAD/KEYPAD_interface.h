/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#define KEYPAD_PORT CPORT

void KEYPAD_Init(void);
u8 	 KEYPAD_Read(void);



#endif 