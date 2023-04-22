/*
 * LCD.c
 *
 * Created: 19/04/2023 11:29:41 م
 *  Author: Abdelsattar
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "LCD.h"
static void Enable(void)
{
	DIO_vSetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_vSetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(2);
}

void LCD_Init(void)
{
	_delay_ms(100);
	
	#if defined EIGHT_BIT_MODE
	
	DIO_vSetPortDir(LCD_PORT,OUTPUT);
	DIO_vSetPinDir(RS_PORT,RS_PIN,OUTPUT);
	DIO_vSetPinDir(EN_PORT,EN_PIN,OUTPUT);
	LCD_WriteCommand(EIGHT_BITS);
	_delay_ms(1);
	LCD_WriteCommand(DISPLAY_ON_CURSOR_ON);
	_delay_ms(1);
	LCD_WriteCommand(CLEAR_SCREEN);
	_delay_ms(10);
	LCD_WriteCommand(ENTRY_MODE);
	_delay_ms(5);
	
	#elif defined FOUR_BIT_MODE
	
	DIO_vSetPortLowNibbleDir(LCD_PORT,OUTPUT);
	DIO_vSetPinDir(RS_PORT,RS_PIN,OUTPUT);
	DIO_vSetPinDir(EN_PORT,EN_PIN,OUTPUT);
	LCD_WriteCommand(RETURN_HOME);
	_delay_ms(5);
	LCD_WriteCommand(FOUR_BITS);
	_delay_ms(1);
	LCD_WriteCommand(DISPLAY_ON_CURSOR_ON);
	_delay_ms(1);
	LCD_WriteCommand(CLEAR_SCREEN);
	_delay_ms(10);
	LCD_WriteCommand(ENTRY_MODE);
	_delay_ms(1);
	
	#endif
	
}
void LCD_WriteCommand(u8 Command)
{
	#if defined EIGHT_BIT_MODE
	DIO_vSetPortValue(LCD_PORT,Command);
	DIO_vSetPinValue(RS_PORT,RS_PIN,LOW);
	Enable();
	_delay_ms(1);
	#elif defined FOUR_BIT_MODE
	DIO_vSetPortLowNibbleValue(LCD_PORT,(Command>>4));
	DIO_vSetPinValue(RS_PORT,RS_PIN,LOW);
	Enable();
	DIO_vSetPortLowNibbleValue(LCD_PORT,Command);
	DIO_vSetPinValue(RS_PORT,RS_PIN,LOW);
	Enable();
	_delay_ms(1);
	#endif
}
void LCD_WriteChar(u8 character)
{
	#if defined EIGHT_BIT_MODE
	DIO_vSetPortValue(LCD_PORT,character);
	DIO_vSetPinValue(RS_PORT,RS_PIN,HIGH);
	Enable();
	_delay_ms(1);
	#elif defined FOUR_BIT_MODE
	DIO_vSetPortLowNibbleValue(LCD_PORT,(character>>4));
	DIO_vSetPinValue(RS_PORT,RS_PIN,HIGH);
	Enable();
	DIO_vSetPortLowNibbleValue(LCD_PORT,character);
	DIO_vSetPinValue(RS_PORT,RS_PIN,HIGH);
	Enable();
	_delay_ms(1);
	#endif
}
void LCD_WriteSentence(u8* ptrSentence)
{
	while(*ptrSentence!='\0')
	{
		LCD_WriteChar(*ptrSentence);
		ptrSentence++;
		
	}
}

void LCD_Move_Cursor(u8 row,u8 colume)
{
	u8 data=0;
	if (row<1||row>2||colume<1||colume>16)
	{
		data=0x80;
	} 
	else if (row==1)
	{
		data=0x80+colume-1;
	}
	else
	{
		data=0xc0+colume-1;
	}
	LCD_WriteCommand(data);
	_delay_ms(1);
	
}
void LCD_Clear(void)
{
	LCD_WriteCommand(CLEAR_SCREEN);
	_delay_ms(10);
}

