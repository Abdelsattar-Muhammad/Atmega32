/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 28 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 
 #include "DATA_TYPES.h"
 #include "BIT_MATH.h"

 
 #include "TIMER2_interface.h"
 #include "TIMER2_private.h"
 
 #include "TIMER2_config.h"
 /***************************************************************************************/
 /********************************* TIMER 2 *********************************************/
#define  NULL_PTR ((void *)0) 

static void (*Timer2_OVF_CallBack)(void)=NULL_PTR;
static void (*Timer2_CTC_CallBack)(void)=NULL_PTR;
/*****************Init functions**********/


/*****************Init functions**********/
void TIMER2_Init(void)
{
		/* Select Clock Source*/
		#if (TIMER2_CLOCk_SOURCE == EXTERNAL )
		SET_BIT(ASSR,AS2);
		#endif	
		#if TIMER2_MODE == TIMER2_NORMAL_MODE
				CLR_BIT(TCCR2,WGM20);
				CLR_BIT(TCCR2,WGM21);
		#elif TIMER2_MODE == TIMER2_CTC_MODE
				CLR_BIT(TCCR2,WGM20);
				SET_BIT(TCCR2,WGM21);
		#elif TIMER2_MODE == TIMER2_FASTPWM_MODE
				SET_BIT(TCCR2,WGM20);
				SET_BIT(TCCR2,WGM21);
		#elif TIMER2_MODE == TIMER2_PhaseCorrect_MODE
				SET_BIT(TCCR2,WGM20);
				CLR_BIT(TCCR2,WGM21);
		#endif
			
			
		#if   TIMER2_OC2_MODE == OC2_DISCONNECTED
				CLR_BIT(TCCR2,COM20);
				CLR_BIT(TCCR2,COM21);
			#elif TIMER2_OC2_MODE == OC2_TOGGLE
				SET_BIT(TCCR2,COM20);
				CLR_BIT(TCCR2,COM21);
			#elif TIMER2_OC2_MODE == OC2_INVERTING
				SET_BIT(TCCR2,COM20);
				SET_BIT(TCCR2,COM21);
			#elif TIMER2_OC2_MODE == OC2_NON_INVERTING
				CLR_BIT(TCCR2,COM20);
				SET_BIT(TCCR2,COM21);
			#endif
			
			TCCR2 &= 0xF8; //0b 1111 1000
			TCCR2 |= TIMER2_SCALER;
}
void TIMER2_Set_OCR2_Value(u8 OCR2_Value)
{
	OCR2=OCR2_Value;
	
}

void TIMER2_OVF_SetCallBack(void (*Copy_Ptr)(void))
{
	Timer2_OVF_CallBack=Copy_Ptr;
}

void TIMER2_OVF_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,TOIE2);
}
void TIMER2_OVF_Interrupt_Disable(void)
{
	CLR_BIT(TIMSK,TOIE2);
}

void TIMER2_CTC_SetCallBack(void (*Copy_Ptr)(void))
{
	Timer2_CTC_CallBack=Copy_Ptr;
}
void TIMER2_CTC_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE2);
}
void TIMER2_CTC_Interrupt_Disable(void)
{
	CLR_BIT(TIMSK,OCIE2);
}


ISR(TIMER2_OVF_vect)
{
	 if(Timer2_OVF_CallBack != NULL_PTR)
	 {
		 Timer2_OVF_CallBack();
	 }
	 
}
ISR(TIMER2_COMP_vect)
{
	 if(Timer2_CTC_CallBack!= NULL_PTR)
	 {
		 Timer2_CTC_CallBack();
	 }
	 
}
 