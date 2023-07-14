/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
#ifndef	TIMER1_CONFIG_H
#define TIMER1_CONFIG_H

/*********************System Sellection ************/
#define TIMER1_MODE 		TIMER1_PhaseCorrect_OCRA_TOP_MODE
#define TIMER1_SCALER 		TIMER1_SCALER_8
#define TIMER1_OC1A_MODE  	OC1A_DISCONNECTED
#define TIMER1_OC1B_MODE  	OC1B_NON_INVERTING
/*****************************************************/



// Timer 1 Modes
#define	TIMER1_NORMAL_MODE   			 	 0
#define	TIMER1_CTC_ICR_TOP_MODE 		 	 1
#define	TIMER1_CTC_OCRA_TOP_MODE 		  	 2
#define	TIMER1_FASTPWM_ICR_TOP_MODE 	  	 3
#define	TIMER1_FASTPWM_OCRA_TOP_MODE 	   	 4
#define	TIMER1_PhaseCorrect_OCRA_TOP_MODE	 5
#define	TIMER1_PhaseCorrect_ICR_TOP_MODE  	 6


//Timer 1 PreScaler
#define		TIMER1_STOP			0
#define		TIMER1_SCALER_1		1
#define		TIMER1_SCALER_8		2
#define		TIMER1_SCALER_64	3
#define		TIMER1_SCALER_256	4
#define		TIMER1_SCALER_1024	5
#define		EXTERNAL1_FALLING	6
#define		EXTERNAL1_RISING	7

//OC1A Modes
#define		OC1A_DISCONNECTED 	0
#define		OC1A_TOGGLE  		1
#define		OC1A_NON_INVERTING	2
#define		OC1A_INVERTING		3

//OC1B Modes
#define		OC1B_DISCONNECTED 	0
#define		OC1B_TOGGLE  		1
#define		OC1B_NON_INVERTING	2
#define		OC1B_INVERTING		3



#endif


