/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef	EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum {
				EXTI0=0, // External interrupt 0
				EXTI1=1, // External interrupt 1
				EXTI2=2, // External interrupt 2

			}EXTI_t;
			
typedef enum {
				LOW_LEVEL=0,
				RISING_EDGE=1, 
				FALLING_EDGE=2,
				ON_CHANGE=3, 
				
			}TriggerEdge_t;		
	
void EXTI_SetCallBack(EXTI_t EXTI_Number,void (*Copy_Ptr)(void) );
void EXTI_Enable(EXTI_t EXTI_Number);
void EXTI_Disable(EXTI_t EXTI_Number);
void EXTI_TriggerEdge(EXTI_t EXTI_Number,TriggerEdge_t EXTI_Mode);
	   

#endif /* EXTERNAL INTERRUPT_H_ */