/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H
#define  COMMON_CATHOD

typedef enum {
	ZERO =0b00111111,
	ONE  =0b00000110,
	TWO  =0b01011011,
	THREE=0b01001111,
	FOUR =0b01100110,
	FIVE =0b01101101,
	SIX  =0b01111101,
	SEVEN=0b00000111,
	EIGHT=0b01111111,
	NINE =0b01101111,
	DOT  =0b10000000,
}Numbers_SS;

void SEVEN_SEG_Init(PORT_t Copy_PortName);
void SEVEN_SEG_Write(PORT_t Copy_PortName,u8 Copy_u8Number);
void SEVEN_SEG_BCD_Init(PORT_t Copy_PortName);

void SEVEN_SEG_BCD_Write(PORT_t Copy_PortName,u8 Copy_u8Number);



#endif 