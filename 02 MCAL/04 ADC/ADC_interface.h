/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

typedef enum{
	ADC0=0, //ADC CHANNEL 0 - A0
	ADC1=1,	//ADC CHANNEL 1 - A1
	ADC2=2,	//ADC CHANNEL 2 - A2
	ADC3=3,	//ADC CHANNEL 3 - A3
	ADC4=4,	//ADC CHANNEL 4 - A4
	ADC5=5,	//ADC CHANNEL 5 - A5
	ADC6=6,	//ADC CHANNEL 6 - A6
	ADC7=7,	//ADC CHANNEL 7 - A7
}ADC_CH_t;

typedef enum{
	
	ADC_PS_2 =0,
	ADC_PS_4 =2,
	ADC_PS_8 =3,
	ADC_PS_16=4,
	ADC_PS_32=5,
	ADC_PS_64=6,
	ADC_PS_128=7

}ADC_PS_t;

void ADC_Init(ADC_CH_t Channel,ADC_PS_t Prescaler );
u16 ADC_Read(void);

#endif