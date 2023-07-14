/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 5 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_Init(void);

/********************* Synch. Functions **********************/
void UART_SendByte(u8 Copy_u8Data );
u8 UART_ReceiveByte(void);
//u8 UART_Receive_NoBlock(u8 *Data);


/********************* ASynch. Functions **********************/
u8 UART_ReceiveByte_NoBlock(void);
void UART_SendByte_NoBlock(u8 Copy_u8Data );


////////////********************* Interrupt *********************//////
void UART_TX_InterruptEnable(void);
void UART_RX_InterruptEnable(void);

void UART_TX_InterruptDisable(void);
void UART_RX_InterruptDisable(void);

/****** CallBack Functions **************/

void UART_TX_SetCallBack(void (*Ptr)(void));
void UART_RX_SetCallBack(void (*Ptr)(void));

#endif