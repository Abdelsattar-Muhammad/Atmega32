/*
 * UART.h
 *
 * Created: 02/05/2023 10:10:36 م
 *  Author: Abdelsattar
 */ 


#ifndef UART_H_
#define UART_H_
#include "data_types.h"
#include "std_macro.h"
void UART_vInit(u32 BaudRate);
void UART_vSendChar(u8 data);
void UART_vSendSentence(u8 *ptr);
u8 UART_u8ReciveChar(void);




#endif /* UART_H_ */