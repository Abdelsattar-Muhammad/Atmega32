/*
 * UART_service.h
 *
 * Created: 05/07/2023 10:23:55 م
 *  Author: Abdelsattar
 */ 


#ifndef UART_SERVICE_H_
#define UART_SERVICE_H_

void UART_SendString(u8 *Str);
void UART_ReceiveString(u8 *Str);

u8 UART_ReceiveStringMyProtocol(u8 *Str);
void UART_SendStringMyProtocol(u8 *Str);

void UART_SendString_Asynch(u8 *Str);
void UART_ReceiveString_Asynch(u8 *Str);



#endif /* UART_SERVICE_H_ */