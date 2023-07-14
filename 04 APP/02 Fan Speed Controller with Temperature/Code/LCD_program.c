/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/


#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>


static void Enable(void)
{
	DIO_vSetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_vSetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(2);
}

void LCD_Init(void)
{
	
	#if LCD_MODE == EIGHT_BIT_MODE
	_delay_ms(100);
	DIO_vSetPortDirection(LCD_PORT,0xFF);
	DIO_vSetPinDirection(RS_PORT,RS_PIN,OUTPUT);
	DIO_vSetPinDirection(EN_PORT,EN_PIN,OUTPUT);
	LCD_WriteCommand(EIGHT_BIT);
	
	_delay_ms(1);
	
	LCD_WriteCommand(DISPLAY_ON_CURSOR_ON);
	
	_delay_ms(1);
	
	LCD_WriteCommand(CLEAR_SCREEN);
	
	_delay_ms(10);
	
	LCD_WriteCommand(ENTRY_MODE);
	
	_delay_ms(5);
	
	#elif LCD_MODE == FOUR_BIT_MODE
	_delay_ms(100);
	DIO_vSetPinDirection(LCD_PORT,Pin0,OUTPUT);
	DIO_vSetPinDirection(LCD_PORT,Pin1,OUTPUT);
	DIO_vSetPinDirection(LCD_PORT,Pin2,OUTPUT);
	DIO_vSetPinDirection(LCD_PORT,Pin3,OUTPUT);
	
	DIO_vSetPinDirection(RS_PORT,RS_PIN,OUTPUT);
	DIO_vSetPinDirection(EN_PORT,EN_PIN,OUTPUT);
	
	LCD_WriteCommand(RETURN_HOME);
	_delay_ms(5);
	LCD_WriteCommand(FOUR_BIT);
	_delay_ms(1);
	LCD_WriteCommand(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(1);
	LCD_WriteCommand(CLEAR_SCREEN);
	_delay_ms(10);
	LCD_WriteCommand(ENTRY_MODE);
	_delay_ms(1);
	
	#endif
	
}
void LCD_WriteCommand(Command_t Copy_Command)
{
	#if LCD_MODE == EIGHT_BIT_MODE
	DIO_vSetPortValue(LCD_PORT,Copy_Command);
	DIO_vSetPinValue(RS_PORT,RS_PIN,LOW);
	Enable();
	_delay_ms(1);
	#elif LCD_MODE == FOUR_BIT_MODE
	
	DIO_vSetPinValue(LCD_PORT,Pin0,GET_BIT(Copy_Command,4));
	DIO_vSetPinValue(LCD_PORT,Pin1,GET_BIT(Copy_Command,5));
	DIO_vSetPinValue(LCD_PORT,Pin2,GET_BIT(Copy_Command,6));
	DIO_vSetPinValue(LCD_PORT,Pin3,GET_BIT(Copy_Command,7));

	DIO_vSetPinValue(RS_PORT,RS_PIN,LOW);
	Enable();
	
	DIO_vSetPinValue(LCD_PORT,Pin0,GET_BIT(Copy_Command,0));
	DIO_vSetPinValue(LCD_PORT,Pin1,GET_BIT(Copy_Command,1));
	DIO_vSetPinValue(LCD_PORT,Pin2,GET_BIT(Copy_Command,2));
	DIO_vSetPinValue(LCD_PORT,Pin3,GET_BIT(Copy_Command,3));
	DIO_vSetPinValue(RS_PORT,RS_PIN,LOW);
	Enable();
	_delay_ms(1);
	#endif
}
void LCD_WriteChar(u8 character)
{
	#if LCD_MODE == EIGHT_BIT_MODE
	DIO_vSetPortValue(LCD_PORT,character);
	DIO_vSetPinValue(RS_PORT,RS_PIN,HIGH);
	Enable();
	_delay_ms(1);
	#elif LCD_MODE == FOUR_BIT_MODE
	DIO_vSetPinValue(LCD_PORT,Pin0,GET_BIT(character,4));
	DIO_vSetPinValue(LCD_PORT,Pin1,GET_BIT(character,5));
	DIO_vSetPinValue(LCD_PORT,Pin2,GET_BIT(character,6));
	DIO_vSetPinValue(LCD_PORT,Pin3,GET_BIT(character,7));
	DIO_vSetPinValue(RS_PORT,RS_PIN,HIGH);
	Enable();
	DIO_vSetPinValue(LCD_PORT,Pin0,GET_BIT(character,0));
	DIO_vSetPinValue(LCD_PORT,Pin1,GET_BIT(character,1));
	DIO_vSetPinValue(LCD_PORT,Pin2,GET_BIT(character,2));
	DIO_vSetPinValue(LCD_PORT,Pin3,GET_BIT(character,3));
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
void LCD_ClearScreen(void)
{
	LCD_WriteCommand(CLEAR_SCREEN);
	_delay_ms(10);
}


void LCD_WriteNumber(u64 Copy_Number)
{
	u8 i=0,arr[10],j;
	
	if(Copy_Number==0)
	{
	LCD_WriteChar('0');
	}
	else
	{
	while(Copy_Number)
	{
		arr[i]=Copy_Number%10+'0';
		Copy_Number/=10;
		i++;
	}
		for(j=i;j>0;j--)
		{
			LCD_WriteChar(arr[j-1]);
		}
	}//End else
	for(i=0;i<10;i++)
	{
		arr[i]=' ';
	}
}