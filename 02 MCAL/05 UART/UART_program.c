/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 5 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

 
#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h" 
#include "UART_config.h"


/*****************Pointer to functions to be assigned to ISR******************************/

#define NULL_PTR ((void *)0)

static void (*UART_TX_Ptr) (void)=NULL_PTR;
static void (*UART_RX_Ptr) (void)=NULL_PTR;


/*****************Init functions*****************************/
const u16 BaudRateArray[TOTAL_SPEED_MODE][TOTAL_CPU_F][TOTAL_BAUD_RATE]=
		 {{{103, 51, 25, 16, 12,  8},{207,103, 51, 34, 25, 16},{416,207,103, 68 ,51, 34}},
		  {{207,103, 51, 34, 25, 16},{416,207,103, 68 ,51, 34},{832,416,207,138,103, 68}}};

void UART_Init(void)
{
		u8  UCSRC_var=0;
		u16 UBRR_var=0; 

/***************************** Transmission speed***************************/
		#if (SPEED_MODE==NORMAL_SPEED)
		CLR_BIT(UCSRA,U2X);
		#elif (SPEED_MODE==DOUBLE_SPEED)
		SET_BIT(UCSRA,U2X);
		#endif

//******************Set URSEL to write data to UCSRC register***************/ 
		SET_BIT(UCSRC_var,URSEL);
 
//********************************synch***********************************/
		#if (SYNCH_MODE==SYNCH)
		SET_BIT(UCSRC_var,UMSEL)
		#elif (SYNCH_MODE==ASYNCH)
		CLR_BIT(UCSRC_var,UMSEL);
		#endif

//*****************************parity mode*******************************/
	
		#if (PARITY_MODE==NO_PARITY)
		CLR_BIT(UCSRC_var,UPM0);
		CLR_BIT(UCSRC_var,UPM1);
		#elif (PARITY_MODE==EVEN_PARITY)
		CLR_BIT(UCSRC_var,UPM0);
		SET_BIT(UCSRC_var,UPM1);
		#elif (PARITY_MODE==ODD_PARITY)
		SET_BIT(UCSRC_var,UPM0);
		SET_BIT(UCSRC_var,UPM1);
		#endif
//************************Data bits*******************************/	
		#if (N_DATA_BITS==_5_DATA_BITS)
		CLR_BIT(UCSRC_var,UCSZ0);
		CLR_BIT(UCSRC_var,UCSZ1);
		CLR_BIT(UCSRC_var,UCSZ2);
		#elif (N_DATA_BITS==_6_DATA_BITS)
		SET_BIT(UCSRC_var,UCSZ0);
		CLR_BIT(UCSRC_var,UCSZ1);
		CLR_BIT(UCSRC_var,UCSZ2);
		#elif (N_DATA_BITS==_7_DATA_BITS)
		CLR_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
		#elif (N_DATA_BITS==_8_DATA_BITS)
		SET_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
		#elif (N_DATA_BITS==_9_DATA_BITS)
		SET_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		SET_BIT(UCSRB,UCSZ2);
		#endif
//************************Stop bits*******************************/	
		#if (N_STOP_BITS==ONE_STOP_BIT)
		CLR_BIT(UCSRC_var,USBS);
		#elif (N_STOP_BITS==TWO_STOP_BIT)
		SET_BIT(UCSRC_var,USBS);
		#endif
//*****************set UCSRC value   *******************************/	
		UCSRC=UCSRC_var;

//************************Baud rate *******************************/	
	
	//************************Baud rate *******************************/

	UBRR_var=BaudRateArray[SPEED_MODE][CPU_F][BUAD_RATE];
	UBRRH = (u8)(UBRR_var>>8);
	UBRRL = (u8)UBRR_var;
	
//************************Enable  *******************************/		
//enable UART  receiver.
		SET_BIT(UCSRB,RXEN);
//enable UART  transmitter .
		SET_BIT(UCSRB,TXEN);
}
/****************** Synch. Functions **********************/
void UART_SendByte(u8 Copy_u8Data )
{
	/* Wait until  Data Register is Empty */
	while(GET_BIT(UCSRA,UDRE)==0);
	
	UDR=Copy_u8Data;
	
}

u8 UART_ReceiveByte(void)
{
	/* Wait until Reciving Complete */
	while(GET_BIT(UCSRA,RXC)==0);
	/* Return Reciving Data */	
	return UDR;
	
}

/*
u8 UART_ReciveByte_NoBlock(u8 *Data)
{
	if (GET_BIT(UCSRA,RXC))
	{
		*Data=UART_Recive();
		return 1;
	}
		
	else
	{
		return 0;
	}
	
	
}*/

/****************** ASynch. Functions **********************/

void UART_SendByte_NoBlock(u8 Copy_u8Data )
{
	UDR=Copy_u8Data;
	
}
u8 UART_ReceiveByte_NoBlock(void)
{
	
	return UDR;
	
}

/***************************** Interrupt Functions******************/
void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
	
}
void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
	
}
void UART_TX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,TXCIE);
	
}
void UART_RX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,RXCIE);
	
}

/*************************** Set CallBack Functions *************/

void UART_TX_SetCallBack(void (*Ptr)(void))
{
	UART_TX_Ptr=Ptr;
}
void UART_RX_SetCallBack(void (*Ptr)(void ) )
{
	UART_RX_Ptr=Ptr;
}
/*********************** ISR ***********************************/
ISR(USART_TXC_vect)
{
	if (UART_TX_Ptr != NULL_PTR)
	{
		UART_TX_Ptr();
	}
}
ISR(USART_RXC_vect)
{
	if (UART_RX_Ptr != NULL_PTR)
	{
		UART_RX_Ptr();
	}	
}