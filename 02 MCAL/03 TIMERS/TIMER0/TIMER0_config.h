/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef	TIMER_CONFIG_H
#define TIMER_CONFIG_H

// Timer 0 Modes
#define	TIMER0_NORMAL_MODE   			 	 0
#define	TIMER0_CTC_OCR0_TOP_MODE 		 	 1
#define	TIMER0_FASTPWM_MODE			 	  	 2
#define	TIMER0_PhaseCorrect_MODE	 		 3

//Timer 0 PreScaler
#define		TIMER0_STOP			0
#define		TIMER0_SCALER_1		1
#define		TIMER0_SCALER_8		2
#define		TIMER0_SCALER_64	3
#define		TIMER0_SCALER_256	4
#define		TIMER0_SCALER_1024	5
#define		EXTERNAL0_FALLING	6
#define		EXTERNAL0_RISING	7

//OC0 Modes
#define		OC0_DISCONNECTED 	0
#define		OC0_TOGGLE  		1
#define		OC0_NON_INVERTING	2
#define		OC0_INVERTING		3

/*********************System Sellection ************/

#define TIMER0_MODE 		TIMER0_FASTPWM_MODE
#define TIMER0_SCALER 		TIMER0_SCALER_8
#define TIMER0_OC0_MODE  	OC0_NON_INVERTING



#endif


