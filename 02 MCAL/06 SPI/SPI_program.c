/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 6 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

 
#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h" 
#include "SPI_config.h"


/*****************Pointer to functions to be assigned to ISR******************************/

#define NULL_PTR ((void *)0)

static void (*UART_TX_Ptr) (void)=NULL_PTR;

/*****************Init functions*****************************/
void SPI_Init_Master(void)
{
	
	// Initialize MISO,MOSI,SS & SCK
	DIO_vSetPinDirection(BPORT,Pin4,OUTPUT);
	DIO_vSetPinDirection(BPORT,Pin5,OUTPUT);
	DIO_vSetPinDirection(BPORT,Pin6,INPUT);
	DIO_vSetPinDirection(BPORT,Pin7,OUTPUT);
	
	// SPI Clock Rate As OSC/4 And Clock Phase and polarity 0 	
	// Set Device As Master
	SET_BIT(SPCR,MSTR);
	// Enable SPI
	SET_BIT(SPCR,SPE);
	
}

void SPI_Init_Slave(void)
{
	// Initialize MISO,MOSI,SS & SCK
		DIO_vSetPinDirection(BPORT,Pin4,INPUT);
		DIO_vSetPinDirection(BPORT,Pin5,INPUT);
		DIO_vSetPinDirection(BPORT,Pin6,OUTPUT);
		DIO_vSetPinDirection(BPORT,Pin7,INPUT);
		// Set Device As Slave
		CLR_BIT(SPCR,MSTR);
		// Enable SPI
		SET_BIT(SPCR,SPE);
	
}
/****************************** Synch. Functions ***********************/
void SPI_Send_Byte(u8 Data_Send)
{
	SPDR=Data_Send;
	/* Wait Until a serial transfer is complete.	*/
	while(!GET_BIT(SPSR,SPIF));
	
}

void SPI_Send_String(u8 *Str)
{
	u8 i=0;
	while(Str[i]!='\0')
	{
		SPI_Send_Byte(Str[i]);
		i++;
	}
}
u8 SPI_Receive_Byte(void)
{
	while(!GET_BIT(SPSR,SPIF));
	u8 return_val =SPDR;
	return return_val;
	
}


void SPI_Receive_String(u8 *Str)
{
	static u8 i=0;
	Str[i++]=SPI_Receive_Byte();

}

/*********************** ISR ***********************************/
/*ISR(SPI_STC_vect)
{
	if (UART_TX_Ptr != NULL_PTR)
	{
		UART_TX_Ptr();
	}
}
*/