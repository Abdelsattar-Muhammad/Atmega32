/*
 * SPI.c
 *
 * Created: 03/05/2023 12:55:05 م
 *  Author: Abdelsattar
 */ 
#include "SPI.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/*SPI I/O Data Register*/
#define SPDR *((volatile u8*) 0x2F)

/*SPI Control Register*/
#define SPCR *((volatile u8*) 0x2D)

#define SPR0 0	//SPI Clock Rate Select
#define SPR1 1	//SPI Clock Rate Select
#define CPHA 2	//Clock Phase
#define CPOL 3  //Clock Polarity
#define MSTR 4  //Master/Slave Select
#define DORD 5  //Data Order
#define SPE  6	//SPI Enable
#define SPIE 7	//SPI Interrupt Enable

/*SPI Status Register */
#define SPSR *((volatile u8*) 0x2E)

#define SPI2X  0 //SPI Double Speed Mode
/*Bit 5:1
These are reserved bits.*/
#define WCOL   6 //Write Collision Flag
#define SPIF   7 //SPI Interrupt Flag

 void SPI_Init_Master(void)
 {	
	 DIO_vSetPinDir(SPI_PORT,SS,OUTPUT);
	 DIO_vSetPinDir(SPI_PORT,MOSI,OUTPUT);
	 DIO_vSetPinDir(SPI_PORT,SCK,OUTPUT);
	 DIO_vSetPinDir(SPI_PORT,MISO,INPUT);
	 /*set MCU as Master , Fosc/4, Clock Phase =0, Clock Polarity =0
	 ,Data Order MSB ,Disable Interrupt*/
	 SET_BIT(SPCR,MSTR);
	 SET_BIT(SPCR,SPE);
	 
 }
 void SPI_Init_Slave(void)
{
	DIO_vSetPinDir(SPI_PORT,SS,INPUT);
	DIO_vSetPinDir(SPI_PORT,MOSI,INPUT);
	DIO_vSetPinDir(SPI_PORT,SCK,INPUT);
	DIO_vSetPinDir(SPI_PORT,MISO,OUTPUT);
	 /*set MCU as Slave , Fosc/4, Clock Phase =0, Clock Polarity =0
	,Data Order MSB ,Disable Interrupt*/
	CLR_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPE);
} 
 void SPI_Master_Send_Byte(u8 data)
 {
	 DIO_vSetPinValue(SPI_PORT,SS,INPUT);
	 SPDR=data;
	 while(READ_BIT(SPSR,SPIF)==0);
	
 }
 void SPI_Master_Send_String(u8 *str)
 {
	 while(*str!=0)
	 {
		 SPI_Master_Send_Byte(*str);
		 str++;	
		 _delay_ms(100);
		 }
 }		 
 
 u8 SPI_Slave_Receive_Byte(void)
 {
	 while(READ_BIT(SPSR,SPIF)==0);
	 return SPDR;//Accessing SPDR To Clear SPIF
 }
