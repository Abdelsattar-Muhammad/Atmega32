/*
 * SPI.h
 *
 * Created: 03/05/2023 01:38:57 م
 *  Author: Abdelsattar
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "data_types.h"
#include "DIO.h"
#include "std_macro.h"

#define SPI_PORT BPORT
#define SS		 PIN4
#define MOSI	 PIN5
#define MISO	 PIN6 
#define SCK		 PIN7


void SPI_Init_Master(void);
void SPI_Init_Slave(void);
void SPI_Master_Send_Byte(u8 data);
void SPI_Master_Send_String(u8 *str); 
u8 SPI_Slave_Receive_Byte(void);

#endif /* SPI_H_ */