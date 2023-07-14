/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 5 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/


#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_service.h"

/***** Global Pointer To Shared Bet. Functions*******/
static u8  *Asynch_Send_Str;
static u8  *Asynch_Receive_Str;
/************* Synch. Functions ****************/
void UART_SendString(u8 *Str)
{
	int i=0;
	while(Str[i]!='\0')
	{
		UART_SendByte(Str[i]);
		i++;
	}	
}
void UART_ReciveString(u8 *Str)
{
	int i=0;
	Str[i]=UART_ReceiveByte();
	while(Str[i]!='#')
	{
		i++;
		Str[i]=UART_ReceiveByte();
	}
	Str[i]='\0';
}
/************** My Protocol is divided into 3 info.
		first number of String	
		then string 
		then 2 bit to check sum error*******************/
void UART_SendStringMyProtocol(u8 *Str)
{
	int i=0,lenght=0,sum=0;
	while(Str[lenght]!='\0')
	{ 
		sum +=Str[lenght];
		lenght++;
		}
	
	UART_SendByte(lenght);
	while(Str[i]!='\0')
	{
	UART_SendByte(Str[i++]);
	}
	UART_SendByte((u8)sum);
	UART_SendByte((u8)(sum>>8));
}

u8 UART_ReciveStringMyProtocol(u8 *Str)
{
	u16 sum_receive=0,sum_cal=0;
	u8 Lenght=UART_ReciveByte();
	for(int i=0;i<Lenght;i++)
	{
		Str[i]=UART_ReciveByte();
		sum_cal+=Str[i];
	}
	
	sum_receive=(Str[Lenght+1]+Str[Lenght+2]);
	if (sum_cal==sum_receive)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	
}

/************* Asynch. Functions ****************/
static void TX_FUNC(void)
{
	static u8 i=1;
	if (Asynch_Send_Str[i]!= '\0')
	{
		UART_SendByte_NoBlock(Asynch_Send_Str[i]);
		i++;
	}
	else
	{
		i==1;
		UART_TX_InterruptDisable();
	}
}
static void RX_FUNC(void)
{
	static	u8 i=0;
	Asynch_Receive_Str[i]=UART_ReciveByte_NoBlock();
	i++;
	/*if (Asynch_Receive_Str[i]=='\0')
	{
		i=0;
	}
	*/
}

void UART_SendString_Asynch(u8 *Str)
{
	Asynch_Send_Str=Str;
	UART_SendByte(Str[0]);
	UART_TX_SetCallBack(TX_FUNC);
	UART_TX_InterruptEnable();
	
}
void UART_ReciveString_Asynch(u8 *Str)
{
	Asynch_Receive_Str=Str;
	UART_RX_SetCallBack(RX_FUNC);
	UART_RX_InterruptEnable();
		
}

