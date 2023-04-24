/*
 * ADC.h
 *
 * Created: 24/04/2023 02:53:01 م
 *  Author: Abdelsattar
 */ 

#include "data_types.h"
#ifndef ADC_H_
#define ADC_H_
//ADC Multiplexer Selection Register –ADMUX
#define ADMUX	 *((volatile u8*)0x27)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

//ADC Control and Status Register A –ADCSRA
#define ADCSRA	 *((volatile u8*)0x26)

#define ADPS0	 0
#define ADPS1	 1
#define ADPS2	 2
#define ADIE	 3
#define ADIF	 4
#define ADATE	 5	
#define ADSC     6	//ADC Start Conversion
#define ADEN	 7 //ADC ENABLE 

#define ADCH	 *((volatile u8*)0x25)
#define ADCL	 *((volatile u8*)0x24)



void ADC_init(void);
u16 ADC_Read(void);
#endif /* ADC_H_ */