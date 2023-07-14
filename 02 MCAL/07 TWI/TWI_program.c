/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 8 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

	
#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"


void TWI_Master_Init(u32 SCL_Freq)
{
	TWBR= (u8)(((F_CPU/SCL_Freq)-16) / (2*PRESCALER));
	if(1 == PRESCALER )
	{
		TWSR=0;
	}
	else if(4 == PRESCALER)
	{
		TWSR=1;
	}
	else if(16 == PRESCALER)
	{
		TWSR=2;
	}
	else if(64 == PRESCALER )
	{
		TWSR=3;
	}
	TWCR=(1<<TWEN);
}
void TWI_Start(void)
{
	TWCR=  (1 << TWINT) | (1 << TWEN) | (1 << TWSTA) ;
	while( GET_BIT( TWCR,TWINT)==0); //wait util interrupt flag set

	if((TWSR & 0xF8)!= START )
	{
		/*	#error */
	}
}

void TWI_Write_Address(u8 SLA_W )
{
	TWDR=SLA_W;
	TWCR= (1 << TWINT) | (1 << TWEN);
	while( GET_BIT( TWCR,TWINT)==0);//wait util interrupt flag set

	if((TWSR & 0xF8)!=MT_SLA_ACK)
	{
		/*	#error */
	}
	
}
void TWI_Write_Data(u8 Copy_u8Data)
{
	TWDR=Copy_u8Data;
	TWCR= (1 << TWINT) | (1 << TWEN) ;
	while( GET_BIT( TWCR,TWINT)==0);//wait util interrupt flag set
	if((TWSR & 0xF8)!=MT_DATA_ACK)
	{
		/*	#error */
	}
}
void TWI_Stop(void)
{
	
	TWCR= (1 << TWINT) | (1 << TWEN)| (1 << TWSTO) ;

}

u8   TWI_Read_with_NACK(void)
{
	
	TWCR= (1 << TWINT) | (1 << TWEN) ;

	while( GET_BIT( TWCR,TWINT)==0);//wait util interrupt flag set

	if((TWSR & 0xF8)!=MR_DATA_NACK)
	{
		/*	#error */
	}	
	return TWDR;
}

// Slave as Receiver
void TWI_Set_Address(u8 Address)
{
	TWAR=Address;
}
u8 	 TWI_Slave_Read(void)
{
	TWCR= (1 << TWINT) | (1 << TWEN) |  (1 << TWEA);
	while( GET_BIT( TWCR,TWINT)==0);//wait util interrupt flag set
	if((TWSR & 0xF8)!=SR_SLA_ACK)
	{
		/*	#error */
	}
	
	TWCR= (1 << TWINT) | (1 << TWEN) |  (1 << TWEA);
	while( GET_BIT( TWCR,TWINT)==0);//wait util interrupt flag set

	if((TWSR & 0xF8)!=SR_DATA_ACK)
	{
		/*	#error */
	}
	return TWDR;
	
}

