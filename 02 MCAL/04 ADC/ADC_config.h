/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef	ADC_CONFIG_H
#define ADC_CONFIG_H


/*
	//These slectection of the voltage reference for the ADC :
	AREF=0,			//AREF, Internal Vref turned off
	AVCC=1,			//AVCC with external capacitor at AREF pin 
	AVCC_INTERNAL=3,//Internal 2.56V Voltage Reference with external capacitor at AREF pin
	
*/

#define ADC_REF 1


#endif


