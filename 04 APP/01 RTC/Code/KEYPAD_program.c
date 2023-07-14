/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "KEYPAD_interface.h"


void KEYPAD_Init(void)
{
	DIO_vSetPortDirection(KEYPAD_PORT,0x0F);
	DIO_vSetPortValue(KEYPAD_PORT,0xFF);
}

u8 KEYPAD_Read(void)
{
	u8 row,colume,returnVal=NOT_PRESSED;
	u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}};
		
	for (row=0;row<4;row++)
	{
		DIO_vSetPortValue(KEYPAD_PORT,0xFF);
		DIO_vSetPinValue(KEYPAD_PORT,row,0);
		for (colume=0;colume<4;colume++)
		{
			if (DIO_u8GetPinValue(KEYPAD_PORT,(colume+4))==0)
			{
				returnVal=arr[row][colume];
				break;
			}//end if 
		}//end nested for
		if (returnVal!=NOT_PRESSED)	
		{
			break;
			}//end if
	} // end second for
	return returnVal;
}//end function
