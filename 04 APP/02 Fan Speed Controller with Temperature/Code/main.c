/*
 * Fan_Speed_Controller_with_Temperature.c
 *
 * Created: 03/07/2023 02:04:01 م
 *  Author: Abdelsattar
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "fan.h"
#include <avr/io.h>

int main(void)
{	

	
	Fan_Init();
    while(1)
    {
	Fan_Enable();
         
    }
}