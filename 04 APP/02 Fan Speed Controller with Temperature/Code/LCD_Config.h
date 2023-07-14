/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/


#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define 	EIGHT_BIT_MODE 0	
#define 	FOUR_BIT_MODE	1


#define LCD_MODE FOUR_BIT_MODE


#define LCD_PORT CPORT

#define RS_PORT CPORT

#define RS_PIN Pin4

#define EN_PORT CPORT

#define EN_PIN Pin5



#endif 