/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 
 #include "DATA_TYPES.h"
 #include "BIT_MATH.h"

 
 #include "ADC_interface.h"
 #include "ADC_private.h"
 
 #include "ADC_config.h"

/*****************Init functions**********/
void ADC_Init(ADC_CH_t Channel,ADC_PS_t Prescaler )
{
	// initialize the adc as user Config.	
	ADMUX  = (ADC_REF<<6)| (Channel);
	// Select prescaler and enable ADC 
	ADCSRA |=(Prescaler)|(1<<ADEN);
	
	
}

u16 ADC_Read(void)
{
	u16 Local_u16Value=0;
	// Start Conversion
	SET_BIT(ADCSRA,ADSC);
	while((GET_BIT(ADCSRA,ADSC)) == 1);
	Local_u16Value  =(ADCL);
	Local_u16Value |= (ADCH<<8) ;
	return Local_u16Value;
	
}
 