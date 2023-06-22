/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 
 #include "DATA_TYPES.h"
 #include "BIT_MATH.h"
 
 #include "DIO_interface.h"
 
 #include "EXTI_interface.h"
 #include "EXTI_private.h"
 
 #include "EXTI_config.h"
 /*********Pointer to functions to be assigned to ISR************/

#define  NULL_PTR ((void *)0) 

static void (*EXTI0_CallBack)(void)=NULL_PTR;
static void (*EXTI1_CallBack)(void)=NULL_PTR;
static void (*EXTI2_CallBack)(void)=NULL_PTR;


/******Call back functions**************************/
void EXTI_SetCallBack(EXTI_t EXTI_Number,void (*Copy_Ptr)(void) )
{
	switch(EXTI_Number)
	{
		case EXTI0 : EXTI0_CallBack=Copy_Ptr; break;
		case EXTI1 : EXTI1_CallBack=Copy_Ptr; break;
		case EXTI2 : EXTI2_CallBack=Copy_Ptr; break;
	}	
}

/*****************Enable&Disable functions**********/
void EXTI_Enable(EXTI_t EXTI_Number)
{
	switch(EXTI_Number)
	{
		case EXTI0:
		SET_BIT(EXTI_GICR,EXTI0_EN);
		break;
		case EXTI1:
		SET_BIT(EXTI_GICR,EXTI1_EN);
		break;
		case EXTI2:
		SET_BIT(EXTI_GICR,EXTI2_EN);
		break;
	}
}

void EXTI_Disable(EXTI_t EXTI_Number)
{
	switch(EXTI_Number)
	{
		case EXTI0:
		CLR_BIT(EXTI_GICR,EXTI0_EN);
		break;
		case EXTI1:
		CLR_BIT(EXTI_GICR,EXTI1_EN);
		break;
		case EXTI2:
		CLR_BIT(EXTI_GICR,EXTI2_EN);
		break;
		
	}
	
}
void EXTI_TriggerEdge(EXTI_t EXTI_Number,TriggerEdge_t EXTI_Mode)
{
	
	switch(EXTI_Number)
	{
		case EXTI0:
		switch(EXTI_Mode)
		{
			case LOW_LEVEL :
			CLR_BIT(EXTI_MCUCR,ISC00_PIN);
			CLR_BIT(EXTI_MCUCR,ISC01_PIN);
			break;
			case RISING_EDGE : 
			SET_BIT(EXTI_MCUCR,ISC00_PIN);
			SET_BIT(EXTI_MCUCR,ISC01_PIN);	
			break;
			case FALLING_EDGE :
			CLR_BIT(EXTI_MCUCR,ISC00_PIN);
			SET_BIT(EXTI_MCUCR,ISC01_PIN);
			break;
			case ON_CHANGE :
			SET_BIT(EXTI_MCUCR,ISC00_PIN);
			CLR_BIT(EXTI_MCUCR,ISC10_PIN);
			break;
		}
		break;
		case EXTI1:
		switch(EXTI_Mode)
		{
			case LOW_LEVEL :
			CLR_BIT(EXTI_MCUCR,ISC10_PIN);
			CLR_BIT(EXTI_MCUCR,ISC11_PIN);
			break;
			case RISING_EDGE : 
			SET_BIT(EXTI_MCUCR,ISC10_PIN);
			SET_BIT(EXTI_MCUCR,ISC11_PIN);	
			break;
			case FALLING_EDGE :
			CLR_BIT(EXTI_MCUCR,ISC10_PIN);
			SET_BIT(EXTI_MCUCR,ISC11_PIN);
			break;
			case ON_CHANGE :
			SET_BIT(EXTI_MCUCR,ISC10_PIN);
			CLR_BIT(EXTI_MCUCR,ISC10_PIN);
			break;
		}
		break;
		case EXTI2:
		switch(EXTI_Mode)
		{
			case RISING_EDGE : 
			SET_BIT(EXTI_MCUCR,ISC2_PIN);		
			break;
			case FALLING_EDGE :
			CLR_BIT(EXTI_MCUCSR,ISC2_PIN);
			break;
		}
		break;
		default: 
		/* Errorr*/
		break;
	}
	
	
}



ISR(INT0_vect)
{
	if(EXTI0_CallBack != NULL_PTR)
	{
	EXTI0_CallBack();
	}
}
ISR(INT1_vect)
{
	if(EXTI1_CallBack != NULL_PTR)
	{
		EXTI1_CallBack();
	}
}

ISR(INT2_vect)
{
	if(EXTI2_CallBack != NULL_PTR)
	{
		EXTI2_CallBack();
	}
}
