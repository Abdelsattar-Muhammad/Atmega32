/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 6 Jul 2023             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/


#ifndef	SPI_PRIVATE_H
#define SPI_PRIVATE_H


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
/*Bit 5:1 These are reserved bits.*/
#define WCOL   6 //Write Collision Flag
#define SPIF   7 //SPI Interrupt Flag

/******************************************************************************/

/* Interrupt Service Routine */
#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12

#endif


