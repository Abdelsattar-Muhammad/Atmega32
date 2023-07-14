/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

typedef enum{
	CLEAR_SCREEN=0x01,
	RETURN_HOME	=0x02,
	ENTRY_MODE	=0x06,
	DISPLAY_ON_CURSOR_ON	=0x0E,
	DISPLAY_ON_CURSOR_OFF	=0x0C,
	EIGHT_BIT	=0x38,/* for 8-bit Mode*/
	FOUR_BIT		=0x28,/* for 4-bit Mode*/
	
}Command_t;


void LCD_Init(void);

void LCD_WriteChar(u8 character);
void LCD_WriteSentence(u8* ptrSentence);
void LCD_WriteCommand(Command_t Copy_Command);
void LCD_Move_Cursor(u8 row,u8 colume);
void LCD_WriteNumber(u64 Copy_Number);

void LCD_ClearScreen(void);



#endif 