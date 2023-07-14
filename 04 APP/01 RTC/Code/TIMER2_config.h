/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 28 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef	TIMER2_CONFIG_H
#define TIMER2_CONFIG_H

/******************** Configuration Timer 2 ***********************************/
#define TIMER2_CLOCk_SOURCE 	EXTERNAL		// From TOSC1 and TOSC2 Pins in Port C
#define TIMER2_MODE 			TIMER2_NORMAL_MODE
#define TIMER2_SCALER 			TIMER2_SCALER_128
#define TIMER2_OC2_MODE  		OC2_DISCONNECTED

/******************************************************************************/

// Timer 2 Modes
#define	TIMER2_NORMAL_MODE  		    	 0
#define	TIMER2_CTC_MODE					 	 1
#define	TIMER2_FASTPWM_MODE			 	  	 2
#define	TIMER2_PhaseCorrect_MODE	 		 3

//Timer2 Scaler
#define		TIMER2_STOP			0	     	// (Timer/Counter stopped).
#define		TIMER2_SCALER_1		1	    	//	(No prescaling)
#define		TIMER2_SCALER_8		2	    	// (From prescaler)
#define		TIMER2_SCALER_32	3	    	// (From prescaler)
#define		TIMER2_SCALER_64	4	    	// (From prescaler)
#define		TIMER2_SCALER_128	5	    	// (From prescaler)
#define		TIMER2_SCALER_256	6		    // (From prescaler)
#define		TIMER2_SCALER_1024	7		    // (From prescaler)



//OC2 Mode
#define		OC2_DISCONNECTED	0		//OC0 disconnected.
#define		OC2_TOGGLE 			1		//on compare match
#define		OC2_NON_INVERTING	2		//on compare match
#define		OC2_INVERTING		3		//on compare match

//Clock_Source

#define 	EXTERNAL 1
#define		INTERNAL 0

	
#endif


