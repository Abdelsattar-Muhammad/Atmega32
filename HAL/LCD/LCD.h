/*
 * LCD.h
 *
 * Created: 19/04/2023 11:30:20 م
 *  Author: Abdelsattar
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "data_types.h"
#include "LCD Confugarution.h"
#include "DIO.h"
#define CLEAR_SCREEN 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define DISPLAY_ON_CURSOR_ON 0x0E
#define DISPLAY_ON_CURSOR_OFF 0x0C
/* for 8-bit Mode*/
#define EIGHT_BITS 0x38
/* for 4-bit Mode*/ 
#define FOUR_BITS 0x28

void LCD_Init(void);
void LCD_WriteChar(u8 character);
void LCD_WriteSentence(u8* ptrSentence);
void LCD_WriteCommand(u8 Command);
void LCD_Move_Cursor(u8 row,u8 colume);
void LCD_Clear(void);



#endif /* LCD_H_ */