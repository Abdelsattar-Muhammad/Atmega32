/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef	TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

/*Timer/Counter Control Register*/

#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define OCR0  *((volatile u8*)0x5C)
#define TIMSK *((volatile u8*)0x59)

/* TIMSK */
#define	TOIE0	0
#define	OCIE0	1

/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/* Interrupt Service Routine */
#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11

#endif


