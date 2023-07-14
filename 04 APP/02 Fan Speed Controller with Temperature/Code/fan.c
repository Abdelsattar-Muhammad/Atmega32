/*
 * fan.c
 *
 * Created: 14/07/2023 10:40:01 م
 *  Author: Abdelsattar
 */ 

#include "BIT_MATH.h"
#include "DATA_TYPES.h"
#include "fan.h"
#include "DIO_interface.h"
#include "TIMER1_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "LM35Temperature_Sensor.h"


u8 Temperature=0;
u16 Fan_Speed=0;
static void Speed_of_Fan(void)
{
	if (Temperature<30)
	{
		Fan_Speed=0;
	}
	else if(Temperature>=30 && Temperature <=60)
	{
		Fan_Speed=2500;
	}
	else if(Temperature>=60 && Temperature <=90)
	{
		Fan_Speed=5000;
	}
	else if(Temperature>=90 && Temperature <=120)
	{	
		Fan_Speed=7500;
	}
	else if(Temperature>=120)
	{
		Fan_Speed=10000;
	
	}
}
void Fan_Init(void)
{
	// Set PD4 as output of PWM
	DIO_vSetPinDirection(DPORT,Pin4,OUTPUT);
	// Set PA0 as Input of ADC
	DIO_vSetPinDirection(APORT,Pin0,INPUT);
	LCD_Init();
	//set ADC Channel And Prescaler
	ADC_Init(ADC0,ADC_PS_64);
	//Select Timer Mode As Phase Correct 
	TIMER1_Init();
	TIMER1_Set_OCR1A_Value(10000);
}

void Fan_Enable(void)
{
	
	Temperature=LM35_GetTemperature();
	Speed_of_Fan();
	
	if (Temperature<30)
	{
		LCD_Move_Cursor(1,1);
		LCD_WriteSentence("Fan is Off ");
	}
	else
	{
		LCD_Move_Cursor(1,1);
		LCD_WriteSentence("Fan is On ");
	}
	
	LCD_Move_Cursor(2,1);
	//Show Temperature on LCD
	LCD_WriteSentence("Temperature ");
	LCD_WriteNumber(Temperature);
	LCD_WriteChar(0xDF);//degree celsius symbol ascii
	LCD_WriteChar('C');
	LCD_WriteChar(' ');
	TIMER1_Set_OCR1B_Value(Fan_Speed);
}