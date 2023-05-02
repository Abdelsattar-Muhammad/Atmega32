/*
 * UART.c
 *
 * Created: 02/05/2023 10:10:20 م
 *  Author: Abdelsattar
 */ 
#include "UART.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/*USART I/O Data Register*/
#define UDR *((volatile u8*) 0x2C)

/*USART Control and Status Register A*/
#define UCSRA *((volatile u8*) 0x2B)

#define MPCM 0	//Multi-Processor Communication Mode
#define U2X  1	//Double Transmission Speed
#define PE   2	//Parity Error
#define DOR	 3  //Data Overrun Error
#define FE   4	//FRAME ERROR
#define UDRE 5  //USART DATA REG. EMPTY--Initial Value =1
#define TXC  6	//Tx COMPELET
#define RXC  7	//Rx COMPELET

/*USART Control and Status Register B*/
#define UCSRB *((volatile u8*) 0x2A)
#define TXB8   0 //Transmit Data Bit 8
#define RXB8   1 //Receive Data Bit 8
#define UCSZ2  2 //Character Size --Initial Value =0
#define TXEN   3 //Transmitter Enable
#define RXEN   4 //Receiver Enable
#define UDRIE  5 //USART Data Register Empty Interrupt Enable
#define TXCIE  6 //TX Complete Interrupt Enable
#define RXCIE  7 //RX Complete Interrupt Enable

/*USART Control and Status Register C*/
#define UCSRC *((volatile u8*) 0x40)
#define UCPOL  0 //Clock Polarity
#define UCSZ0  1 //Character Size--Initial Value =1
#define UCSZ1  2 //Character Size--Initial Value =1
#define UPM0   4 //Parity Mode
#define UPM1   5 //Parity Mode
#define UMSEL  6 //USART Mode Select
#define URSEL  7 //USART Register Select--Initial Value =1

/*USART Baud Rate Registers*/
#define UBRRH *((volatile u8*) 0x40)
#define UBRRL *((volatile u8*) 0x29)


void UART_vInit(u32 BaudRate)
{
	/*Set Baud Rate as BAUD=(F_CPU/16(UBBR-1))*/
	u16 val;
	val=(F_CPU/(16*BaudRate))-1;
	UBRRH=(u8)(val>>8);
	UBRRL=(u8)val;
	// Turn ON Transmitter and Reciver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	/* Set Frame Format as  Asynchronous , 8 data, 1 stop, No Parity
	SET_BIT(UCSRC,URSEL);//bit 7 =1
	SET_BIT(UCSRC,UCSZ0);//bit 1 =1
	SET_BIT(UCSRC,UCSZ1);//bit 2 =1
	UCSRC=10000110
	*/
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	_delay_ms(300);
}
void UART_vSendChar(u8 data)
{
	/*wait until transmit data complete and UDR be Empty*/
	while(READ_BIT(UCSRA,UDRE)==0);
	UDR=data;
}
u8 UART_u8ReciveChar(void)
{
	/*wait utill recive data complete and UDR Content Data*/
	while(READ_BIT(UCSRA,RXC)==0);
	return UDR;
}
void UART_vSendSentence(u8 *ptr)
{
	while(*ptr!=0)
	{
		UART_vSendChar(*ptr);
		ptr++;
		_delay_ms(100);
	}
}