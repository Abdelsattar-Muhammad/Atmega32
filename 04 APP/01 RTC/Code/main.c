/*
 * RTC.c
 *
 * Created: 13/07/2023 11:03:06 ص
 *  Author: Abdelsattar
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "RTC.h"

int main(void)
{
	RTC_Init();

    while(1)
    {
		RTC_Set_Clock();
		RTC_Enable();
    }
}

