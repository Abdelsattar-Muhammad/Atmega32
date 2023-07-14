/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 6 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
void SPI_Init_Master(void);
void SPI_Init_Slave(void);
void SPI_Send_Byte(u8 Data_Send);
void SPI_Send_String(u8 *Str);
void SPI_Receive_Byte(u8 *Data_Recived);
void SPI_Receive_String(u8 *Str);

////////////********************* Interrupt *********************//////
void SPI_InterruptEnable(void);
void SPI_InterruptEnable(void);

/****** CallBack Functions **************/

void SPI_SetCallBack(void (*Ptr)(void));

#endif