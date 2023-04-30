/*
 * Ultrasonic.c
 *
 * Created: 30/04/2023 10:17:31 م
 *  Author: Abdelsattar
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>
#include "avr/io.h"
#include "std_macro.h"
#include "data_types.h"
#include "Ultrasonic.h"
void Ultrasonic_init(void)
{
	SET_BIT(TRIGER_DDR,TRIGER); //set Triger pin as Output
	
}
void Ultrasonic_Trigger(void)
{
	SET_BIT(TRIGER_PORT,TRIGER); //set Triger pin as High
	_delay_us(30);
	CLR_BIT(TRIGER_PORT,TRIGER); //set Triger pin as Low
}
u8 Ultrasonic_Read(void)
{
		
	u16 a,b,Ton, distance=0;
	//set timer1 as ICu
	 SET_BIT(TIFR,ICF1);

	 //TCCR1B=0xC1;
	SET_BIT(TCCR1B,CS10); //set prescal as F_CPU/8
	SET_BIT(TCCR1B,ICNC1);
	SET_BIT(TCCR1B,ICES1);//start timing at rising edge
	
	while(READ_BIT(TIFR,ICF1)==0);//waiting untill catch raising edge
	a=ICR1;
	SET_BIT(TIFR,ICF1); //write 1 at icf1 to clear flag

	//TCCR1B=0x81
	CLR_BIT(TCCR1B,ICES1);//start timing at falling edge
	while(READ_BIT(TIFR,ICF1)==0);//waiting untill catch falling edge
	b=ICR1;	
	Ton=b-a;
	distance=(34600*Ton)/(2*F_CPU);
	SET_BIT(TIFR,ICF1);//write 1 at icf1 to clear flag
	TCCR1B=0; //stop timer0;
	return distance;
}