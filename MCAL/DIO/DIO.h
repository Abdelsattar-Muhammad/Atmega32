/*
 * DIO.h
 *
 * Created: 12/04/2023 05:11:06 م
 *  Author: Abdelsattar
 */ 

#ifndef DIO_H_
#define DIO_H_
#include "data_types.h"
#include "std_macro.h"

/*local defines*/

// PORTA  Register
#define PORTA *((volatile u8*)0x3B)
#define DDRA  *((volatile u8*)0x3A)
#define PINA  *((volatile u8*)0x39)

// PORTB  Register
#define PORTB *((volatile u8*)0x38)
#define DDRB  *((volatile u8*)0x37)
#define PINB  *((volatile u8*)0x36)

// PORTC  Register
#define PORTC *((volatile u8*)0x35)
#define DDRC  *((volatile u8*)0x34)
#define PINC  *((volatile u8*)0x33)

// PORTD  Register
#define PORTD *((volatile u8*)0x32)
#define DDRD  *((volatile u8*)0x31)
#define PIND  *((volatile u8*)0x30)

/*	0 -> INPUT
	1 -> OUTPUT */

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN8 6
#define PIN7 7

#define APORT 0
#define BPORT 1
#define CPORT 2
#define DPORT 3

void DIO_vSetPinDir(u8 PortName,u8 PinNumber,u8 Direction );

void DIO_vSetPortLowNibbleDir(u8 portName,u8 direction);

void DIO_vSetPortHighNibbleDir(u8 portName,u8 direction);

void DIO_vSetPortDir(u8 PortName,u8 Direction );

void DIO_vSetPinValue(u8 PortName,u8 PinNumber,u8 value);

void DIO_vSetPortValue(u8 PortName,u8 value);

u8 DIO_u8GetPortValue(u8 portName);

u8 DIO_u8GetPinValue(u8 portName,u8 pinNumber);


void DIO_vSetPortHighNibbleValue(u8 portName,u8 value);

void DIO_vSetPortLowNibbleValue(u8 portName,u8 value);

void DIO_vSetPullupPin(u8 portName,u8 pinNumber);

void DIO_vTogglePin(u8 portName,u8 pinNumber);

#endif /* DIO_H_ */