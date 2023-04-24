/*
 * ADC.c
 *
 * Created: 24/04/2023 02:52:11 م
 *  Author: Abdelsattar
 */ 

#include "std_macro.h"
#include "ADC.h"
void ADC_init(void)
{
	SET_BIT(ADMUX,REFS0);//AVCC with external capacitor at AREF pin
	SET_BIT(ADCSRA,ADEN); // Enable ADC
	//Set Clock of ADC as F_CPU/64
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	
}
u16 ADC_Read(void)
{
	u16 val;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC)==1);
	val=ADCL;
	val|=(ADCH<<8);
	return val;
}