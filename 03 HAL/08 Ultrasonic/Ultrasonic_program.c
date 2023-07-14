/*
 * Ultrasonic_program.c
 *
 * Created: 01/07/2023 10:28:35 م
 *  Author: Abdelsattar
 */ 

#include "BIT_MATH.h"
#include "DATA_TYPES.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "TIMER1_interface.h"
#include "LED_interface.h"

#include "Ultrasonic_interface.h"
static volatile u16 flag,counter,t1,t2;

static void OVF_fun(void)
{
	counter++;
	if (counter==4)
	{LED_Toggle(BPORT,Pin1);
	counter=0;
	}
}
static void ICU_fun(void)
{
	if (flag==0)
	{
		counter=0;
		t1=ICR1_Value();
		flag=1;
		TIMER1_InputCaptureEdge(FALLING);	
	} 
	else if(flag==1) 
	{
		t2=ICR1_Value();
		flag=2;
		TIMER1_InputCaptureEdge(RISING);
		TIMER1_ICU_InterruptDisable();
		TIMER1_OVF_InterruptDisable();
	}
}

void Ultrasonic_Init(void)
{
	TIMER1_Init();
	DIO_vSetPinDirection(DPORT,Pin6,INPUT);
	TIMER1_ICU_SetCallBack(ICU_fun);
	TIMER1_OVF_SetCallBack(OVF_fun);
	
}
u8 Ultrasonic_GetDistance(Ultrasonic_t UltrasonicNumber)
{
		counter=0,flag=0;
		u16 Time=0;
		u8 Distance=0;
		/*Trigger 10us To Enable Ultrasonic*/
		DIO_vSetPinValue(Ultrasonic_PORT,UltrasonicNumber,HIGH);
		_delay_us(10);
		DIO_vSetPinValue(Ultrasonic_PORT,UltrasonicNumber,LOW);
		/* Set ICu To Didected Rising edge */ 
		TIMER1_InputCaptureEdge(RISING);
		TIMER1_ICU_InterruptEnable();
		TIMER1_OVF_InterruptEnable();
		
		while(flag<2);//wait utill flag equal 2
		Time=t2-t1+((u32)counter*65535);	 
		Distance=(Time/58);	
		return Distance;

}