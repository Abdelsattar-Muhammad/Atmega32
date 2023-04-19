/*
 * External_Interrupt.h
 *
 * Created: 17/04/2023 04:10:03 م
 *  Author: Abdelsattar
 */ 


#ifndef EXTERNAL INTERRUPT_H_
#define EXTERNAL INTERRUPT_H_

#define INT0 0 // External interrupt 0
#define INT1 1 // External interrupt 1
#define INT2 2 // External interrupt 2

/*Configuration Of PINS and PORTS of external interrupts*/
#define INT_PORT DPORT /* PORT D consist INT0 and INT1*/
#define INT0_PIN PIN2
#define INT1_PIN PIN3

#define INT2_PORT BPORT /* PORT B consist INT1*/
#define INT2_PIN PIN2


/*General Interrupt Control Register- Used For Enable Interrupt*/
#define GICR_REGISTER *((volatile u8*)0x5B)
#define INT0_EN 6 //Enable bit
#define INT1_EN 7
#define INT2_EN 5

/*General Interrupt Flag Register*/
#define GIFR_REGISTER *((volatile u8*)0x5A)
#define INTF0_PIN 6
#define INTF1_PIN 7
#define INTF2_PIN 5

/*MCU Control Register*/
#define MCUCR_REGISTER *((volatile u8*)0x55)
#define ISC00_PIN 0
#define ISC01_PIN 1
#define ISC10_PIN 2
#define ISC11_PIN 3

/*MCU Control  and Status Register*/
#define MCUCSR_REGISTER *((volatile u8*)0x54) 
#define ISC2_PIN 6

/* Status Register */
#define SREG_REGISTER *((volatile u8*)0x5F)
//where bit 7 for I Bit (Global interrupt bit)
#define I_BIT 7


void External_interrupt_Init(u8 INTNum);


#endif /* EXTERNAL INTERRUPT_H_ */