/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

/****************************** TIMER 0 ********************************************/

void TIMER0_Init(void);

void TIMER0_Set_OCR0_Value(u8 OCR0_Value);

void TIMER0_OVF_Interrupt_Enable(void);
void TIMER0_OVF_Interrupt_Disable(void);
void TIMER0_OVF_SetCallBack(void (*Copy_Ptr)(void));

void TIMER0_CTC_SetCallBack(void (*Copy_Ptr)(void));
void TIMER0_CTC_Interrupt_Enable(void);
void TIMER0_CTC_Interrupt_Disable(void);

#endif