/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 
 #include "DATA_TYPES.h"
 #include "BIT_MATH.h"
 
 #include "TIMER0_interface.h"
 #include "TIMER0_config.h"
 #include "TIMER0_private.h"
 

 /***************************************************************************************/
 /********************************* TIMER 0 *********************************************/

#define  NULL_PTR ((void *)0) 


static void (*Timer0_OVF_CallBack)(void)=NULL_PTR;
static void (*Timer0_CTC_CallBack)(void)=NULL_PTR;

/*****************Init functions**********/
void TIMER0_Init(void)
{
	#if TIMER0_MODE == TIMER0_NORMAL_MODE
			CLR_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);
	#elif TIMER0_MODE == TIMER0_CTC_OCR0_TOP_MODE
			CLR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
	#elif TIMER0_MODE == TIMER0_FASTPWM_MODE
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
	#elif TIMER0_MODE == TIMER0_PhaseCorrect_MODE
			SET_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);
	#endif
		
		#if   TIMER0_OC0_MODE == OC0_DISCONNECTED
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		#elif TIMER0_OC0_MODE == OC0_TOGGLE
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		#elif TIMER0_OC0_MODE == OC0_INVERTING
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		#elif TIMER0_OC0_MODE == OC0_NON_INVERTING
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		#endif
		
		TCCR0 &= 0xF8; //0b 1111 1000
		TCCR0 |= TIMER0_SCALER;
}

void TIMER0_Set_OCR0_Value(u8 OCR0_Value)
{
	OCR0=OCR0_Value;
	
}
void TIMER0_OVF_SetCallBack(void (*Copy_Ptr)(void))
{
	Timer0_OVF_CallBack=Copy_Ptr;
}

void TIMER0_OVF_Interrupt_Enable(void)
{
 	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_OVF_Interrupt_Disable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}


void TIMER0_CTC_SetCallBack(void (*Copy_Ptr)(void))
{
	Timer0_CTC_CallBack=Copy_Ptr;
}

void TIMER0_CTC_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE0);
}
void TIMER0_CTC_Interrupt_Disable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}




ISR(TIMER0_OVF_vect)
{
	 if(Timer0_OVF_CallBack != NULL_PTR)
	 {
		 Timer0_OVF_CallBack();
	 }
	 
}
ISR(TIMER0_COMP_vect)
{
	 if(Timer0_CTC_CallBack != NULL_PTR)
	 {
		 Timer0_CTC_CallBack();
	 }
	 
}
 