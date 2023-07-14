/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 28 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef TIMER2_INTERFACE_H
#define TIMER2_INTERFACE_H


/****************************** TIMER 0 ********************************************/

void TIMER2_Init(void);

void TIMER2_Set_OCR2_Value(u8 OCR2_Value);

void TIMER2_OVF_Interrupt_Enable(void);
void TIMER2_OVF_Interrupt_Disable(void);
void TIMER2_OVF_SetCallBack(void (*Copy_Ptr)(void));

void TIMER2_CTC_SetCallBack(void (*Copy_Ptr)(void));
void TIMER2_CTC_Interrupt_Enable(void);
void TIMER2_CTC_Interrupt_Disable(void);



#endif