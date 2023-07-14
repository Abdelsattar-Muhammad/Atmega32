/*
 * RTC.c
 *
 * Created: 13/07/2023 01:08:02 م
 *  Author: Abdelsattar
 */
#define F_CPU 8000000UL
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DATA_TYPES.h"
#include "DIO_interface.h"
#include "TIMER2_interface.h"
#include "SEVEN_SEGMENT_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include <avr/interrupt.h>
volatile u8 Seconds=0,Minutes=0,Hours=0,flag=0,arr[2];
 static void Tick(void)
 {
	 Seconds++;
 }
void RTC_Init(void)
{

	/* initialize LCD */
	LCD_Init();
	_delay_ms(100);
	LCD_WriteSentence("Enter 1 ");
	LCD_Move_Cursor(2,1);
	LCD_WriteSentence("To Set Clock !");
	_delay_ms(100);
	/* initialize Seven Segment */
	SEVEN_SEG_BCD_Init(CPORT);
	/* initialize Keypad */
	KEYPAD_Init();
	/* initialize Timer 2 */
	TIMER2_Init();
	/* Set CallBack Function When Overflow Occures  & Enable ISR*/
	sei();
	TIMER2_OVF_SetCallBack(Tick);
	TIMER2_OVF_Interrupt_Enable();
	/* Set Enable Pins As Output */
	DIO_vSetPortDirection(DPORT,0xFF); 
}

void RTC_Enable(void)
{
		DIO_vSetPortValue(DPORT,1);
		SEVEN_SEG_BCD_Write(CPORT,Seconds%10);
		_delay_ms(2);
		DIO_vSetPortValue(DPORT,2);
		SEVEN_SEG_BCD_Write(CPORT,Seconds/10);
		_delay_ms(2);
		DIO_vSetPortValue(DPORT,4);
		SEVEN_SEG_BCD_Write(CPORT,Minutes%10);
		_delay_ms(2);
		DIO_vSetPortValue(DPORT,8);
		SEVEN_SEG_BCD_Write(CPORT,Minutes/10);
		_delay_ms(2);
		DIO_vSetPortValue(DPORT,16);
		SEVEN_SEG_BCD_Write(CPORT,Hours%10);
		_delay_ms(2);
		DIO_vSetPortValue(DPORT,32);
		SEVEN_SEG_BCD_Write(CPORT,Hours/10);
		_delay_ms(2);
	if (Seconds>=60)
	{
		Seconds=0;
		Minutes++;
	}
	if (Minutes>=60)
	{
		Minutes=0;
		Hours++;
	}
	if (Hours>=24)
	{
		Hours=0;
	}
	
}

void Set_Hours(void)
{
	LCD_ClearScreen();
	_delay_ms(250);
	LCD_WriteSentence("Hours:--");
	LCD_Move_Cursor(1,7);
	
	do
	{
		arr[0]=KEYPAD_Read();
	} while (arr[0]==0xff);
	LCD_WriteNumber(arr[0]-'0');
	_delay_ms(300);
	do
	{
		arr[1]=KEYPAD_Read();
	} while (arr[1]==0xff);
	LCD_WriteNumber(arr[1]-'0');
	_delay_ms(500);
	Hours=(10*(arr[0]-'0'))+(arr[1]-'0');
}
void Set_Mins(void)
{
	
	LCD_ClearScreen();
	LCD_WriteSentence("Mins:--");
	LCD_Move_Cursor(1,6);
	
	do
	{
		arr[0]=KEYPAD_Read();
	} while (arr[0]==0xff);
	LCD_WriteNumber(arr[0]-'0');
	_delay_ms(300);

	do
	{
		arr[1]=KEYPAD_Read();
	} while (arr[1]==0xff);
	LCD_WriteNumber(arr[1]-'0');
	_delay_ms(500);
	Minutes=(10*(arr[0]-'0'))+(arr[1]-'0');
}
void Set_Sec(void)
{
	
	
	LCD_ClearScreen();
	LCD_WriteSentence("Sec:--");
	LCD_Move_Cursor(1,5);
	
	do
	{
		arr[0]=KEYPAD_Read();
	} while (arr[0]==0xff);
	LCD_WriteNumber(arr[0]-'0');
	_delay_ms(300);
	do
	{
		arr[1]=KEYPAD_Read();
	} while (arr[1]==0xff);
	LCD_WriteNumber(arr[1]-'0');
	_delay_ms(500);
	Seconds=(10*(arr[0]-'0'))+(arr[1]-'0');
}
void RTC_Set_Clock(void)
{	flag=KEYPAD_Read();
	if (flag!= NOT_PRESSED)
	{
		
		if (flag=='1')
		{
			
			Set_Hours();
			Set_Mins();
			Set_Sec();
			LCD_ClearScreen();
			LCD_WriteSentence("Done!");
			_delay_ms(1000);
			LCD_ClearScreen();
			LCD_WriteSentence("Enter 1 ");
			LCD_Move_Cursor(2,1);
			LCD_WriteSentence("To Set Clock !");
			flag=0;
			_delay_ms(300);
		}
		else
		{
			LCD_ClearScreen();
			LCD_WriteSentence("Wrong Choice!");
			_delay_ms(1000);
			LCD_ClearScreen();
			LCD_WriteSentence("Enter 1 ");
			LCD_Move_Cursor(2,1);
			LCD_WriteSentence("To Set Clock !");
			flag=0;
		}
		
	}	
}
	
	
