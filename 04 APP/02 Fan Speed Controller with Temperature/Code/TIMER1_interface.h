/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H


typedef enum{
	FALLING,
	RISING
	
}ICU_Edge_t;

void TIMER1_Init(void);
void TIMER1_InputCaptureEdge(ICU_Edge_t Edge);

/* This Functions Used if We Choose One Mode Of Them : 
	
		1-CTC_ICR_TOP_MODE 
		2-FASTPWM_ICR_TOP_MODE
		3-PhaseCorrect_ICR_TOP_MODE		
*/
void TIMER1_Set_ICR1_TOP_Value(u16 ICR1_TOP);

/* This Functions Used to Set OCR1A or OCR1B Values */
void TIMER1_Set_OCR1A_Value(u16 OCR1A_Value);
void TIMER1_Set_OCR1B_Value(u16 OCR1B_Value);
u16 ICR1_Value(void);
/*********************************** Iterrupts **************************************/

void TIMER1_OVF_InterruptEnable(void);
void TIMER1_OVF_InterruptDisable(void);

void TIMER1_OCA_InterruptEnable(void);
void TIMER1_OCA_InterruptDisable(void);
 
void TIMER1_OCB_InterruptEnable(void);
void TIMER1_OCB_InterruptDisable(void);

void TIMER1_ICU_InterruptEnable(void);
void TIMER1_ICU_InterruptDisable(void);

void TIMER1_OVF_SetCallBack(void (*Copy_Ptr)(void));
void TIMER1_OCA_SetCallBack(void (*Copy_Ptr)(void));
void TIMER1_OCB_SetCallBack(void (*Copy_Ptr)(void));
void TIMER1_ICU_SetCallBack(void (*Copy_Ptr)(void));


#endif