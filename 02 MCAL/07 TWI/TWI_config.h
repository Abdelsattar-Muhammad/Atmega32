/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 8 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 
#ifndef TWI_CONFIG_H
#define TWI_CONFIG_H


/*
TWPS	  TWPS0 			Prescaler Value
0 			0				 1
0			1 				 4
1			0 				 16
1			1 				 64 

prescaler is 1 , 2 ,3 ,4 
*/

#define PRESCALER 1

#define F_CPU	  8000000

#endif