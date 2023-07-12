/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 
#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_config.h"
#include "TIMER1_private.h" 

/*****************Pointer to functions to be assigned to ISR******************************/
#define NULL_PTR ((void *)0)
static void (*TIMER1_OVF_Ptr) (void)=NULL_PTR;
static void (*TIMER1_OCA_Ptr) (void)=NULL_PTR;
static void (*TIMER1_OCB_Ptr) (void)=NULL_PTR;
static void (*TIMER1_ICU_Ptr) (void)=NULL_PTR;

/*****************Init functions*****************************/

void TIMER1_Init(void)
{
	#if TIMER1_MODE == TIMER1_NORMAL_MODE
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_MODE == TIMER1_CTC_ICR_TOP_MODE
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_MODE == TIMER1_CTC_OCRA_TOP_MODE
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_MODE == TIMER1_FASTPWM_ICR_TOP_MODE
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_MODE == TIMER1_FASTPWM_OCRA_TOP_MODE
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_MODE == TIMER1_PhaseCorrect_OCRA_TOP_MODE
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_MODE == TIMER1_PhaseCorrect_ICR_TOP_MODE
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
	#endif
	
		
	#if   TIMER1_OC1A_MODE  == OC1A_DISCONNECTED
			CLR_BIT(TCCR1A,COM1A0);
			CLR_BIT(TCCR1A,COM1A1);
	#elif TIMER1_OC1A_MODE == OC1A_TOGGLE
			SET_BIT(TCCR1A,COM1A0);
			CLR_BIT(TCCR1A,COM1A1);
	
	#elif TIMER1_OC1A_MODE == OC1A_NON_INVERTING
			CLR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
	
	#elif TIMER1_OC1A_MODE == OC1A_INVERTING
			SET_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
	
	#endif
	
	
	#if   TIMER1_OC1B_MODE   == OC1B_DISCONNECTED
			CLR_BIT(TCCR1A,COM1B0);
			CLR_BIT(TCCR1A,COM1B1);
	#elif TIMER1_OC1B_MODE == OC1B_TOGGLE
			SET_BIT(TCCR1A,COM1B0);
			CLR_BIT(TCCR1A,COM1B1);
	#elif TIMER1_OC1B_MODE == OC1B_NON_INVERTING
			CLR_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
	#elif TIMER1_OC1B_MODE == OC1B_INVERTING
			SET_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
	#endif

		TCCR1B&=0XF8;
		TCCR1B|=TIMER1_SCALER;	
	
}

void TIMER1_Set_OCR1A_Value(u16 OCR1A_Value)
{
	OCR1A=OCR1A_Value;
}
void TIMER1_Set_OCR1B_Value(u16 OCR1B_Value)
{
	OCR1B=OCR1B_Value;
}

void TIMER1_Set_ICR1_TOP_Value(u16 ICR1_TOP)
{
	ICR1=ICR1_TOP;
}
void TIMER1_InputCaptureEdge(ICU_Edge_t Edge)
{
//	SET_BIT(TCCR1B, ICNC1); // To Cancle Noise
	
	if(Edge==RISING)
	{
	SET_BIT(TCCR1B,ICES1);
	}
	else if(Edge==FALLING)
	{
	CLR_BIT(TCCR1B,ICES1);
	}
}
/****************************Timer 1 Interrupt functions**************************************/

void TIMER1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void TIMER1_ICU_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}
void TIMER1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void TIMER1_OVF_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE1);
}
void TIMER1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void TIMER1_OCA_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1A);
}
void TIMER1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void TIMER1_OCB_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1B);
}
u16 ICR1_Value(void)
{
	u16 Local=0;
	Local=ICR1;
	return Local;
}

/*********************************Timer 1 Call Back functions*****************************************/

void TIMER1_OVF_SetCallBack(void(*Copy_Ptr)(void))
{
	TIMER1_OVF_Ptr=Copy_Ptr;
}
void TIMER1_OCA_SetCallBack(void(*Copy_Ptr)(void))
{
	TIMER1_OCA_Ptr=Copy_Ptr;
}
void TIMER1_OCB_SetCallBack(void(*Copy_Ptr)(void))
{
	TIMER1_OCB_Ptr=Copy_Ptr;
}
void TIMER1_ICU_SetCallBack(void(*Copy_Ptr)(void))
{
	TIMER1_ICU_Ptr=Copy_Ptr;
}

/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if( TIMER1_OVF_Ptr !=NULL_PTR)
	{
		TIMER1_OVF_Ptr();
	}
}
ISR(TIMER1_COMPA_vect)
{
	if(TIMER1_OCA_Ptr!=NULL_PTR)
	{
		TIMER1_OCA_Ptr();
	}
}
ISR(TIMER1_COMPB_vect)
{
	if(TIMER1_OCB_Ptr!=NULL_PTR)
	{
		TIMER1_OCB_Ptr();
	}
}
ISR(TIMER1_CAPT_vect)
{
	if(TIMER1_ICU_Ptr!=NULL_PTR)
	{
		TIMER1_ICU_Ptr();
	}
}