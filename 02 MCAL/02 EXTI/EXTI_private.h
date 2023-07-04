/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef	EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Interrupt Service Routine */

#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)

/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3

/*General Interrupt Control Register- Used For Enable Interrupt*/
#define EXTI_GICR *((volatile u8*)0x5B)

#define EXTI0_EN 6 //Enable bit For EXTI0
#define EXTI1_EN 7 //Enable bit For EXTI1
#define EXTI2_EN 5 //Enable bit For EXTI2

/*General Interrupt Flag Register*/
#define EXTI_GIFR *((volatile u8*)0x5A)

/*MCU Control Register*/
#define EXTI_MCUCR *((volatile u8*)0x55)

#define ISC00_PIN 0
#define ISC01_PIN 1
#define ISC10_PIN 2
#define ISC11_PIN 3

/*MCU Control  and Status Register*/
#define EXTI_MCUCSR *((volatile u8*)0x54) 

#define ISC2_PIN 6

/* Status Register */
#define SREG *((volatile u8*)0x5F)

//where bit 7 for I Bit (Global interrupt bit)
#define I_BIT 7







#define EXTI0_PIN 6
#define EXTI1_PIN 7
#define EXTI2_PIN 5




#define ISC2_PIN 6



#endif


