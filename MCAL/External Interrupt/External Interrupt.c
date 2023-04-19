/*
 * External_Interrupt.c
 *
 * Created: 17/04/2023 04:08:52 م
 *  Author: Abdelsattar
 */ 
 
 #include "data_types.h"
 #include "std_macro.h"
 #include "External Interrupt.h"
 #include "DIO.h"

void External_interrupt_Init(u8 INTNum)
{
	switch(INTNum)
	{
		case INT0:
		/*Set PIN 2 At PORT D As Input*/
		DIO_vSetPinDir(INT_PORT,INT0_PIN,INPUT);
		/*Set Pullup Resistance */
		DIO_vSetPullupPin(INT_PORT,INT0_PIN);
		/*for falling Edge*/
		SET_BIT(MCUCR_REGISTER,ISC01_PIN);
		/*for Rising Edge*/
		//SET_BIT(MCUCR_REGISTER,ISC00_PIN);
		//SET_BIT(MCUCR_REGISTER,ISC01_PIN);
		/*for any logical change in INT0*/
		//SET_BIT(MCUCR_REGISTER,ISC00_PIN);
		/*  Enable INT0 and Global inturrupt bit at SREG   */
		SET_BIT(GICR_REGISTER,INT0_EN);
		SET_BIT(SREG_REGISTER,I_BIT);
		break;
		
		case INT1:		
		/*Set PIN 3 At PORT D As Input*/
		DIO_vSetPinDir(INT_PORT,INT1_PIN,INPUT);
		/*Set Pullup Resistance */
		DIO_vSetPullupPin(INT_PORT,INT1_PIN);
		
		/*for falling Edge*/
		SET_BIT(MCUCR_REGISTER,ISC11_PIN);
		
		/*for Rising Edge*/
		//SET_BIT(MCUCR_REGISTER,ISC10_PIN);
		//SET_BIT(MCUCR_REGISTER,ISC11_PIN);
		/*for any logical change in INT0*/
		//SET_BIT(MCUCR_REGISTER,ISC10_PIN);
		
		/*  Enable INT1 and Global inturrupt bit at SREG   */
		SET_BIT(GICR_REGISTER,INT1_EN);
		SET_BIT(SREG_REGISTER,I_BIT);
		
		break;
		case INT2:
		/*Set PIN 2 At PORT B As Input*/
		DIO_vSetPinDir(INT2_PORT,INT2_PIN,INPUT);
		/*Set Pullup Resistance */
		DIO_vSetPullupPin(INT2_PORT,INT2_PIN);
		/*for falling Edge*/
		SET_BIT(MCUCSR_REGISTER,ISC2_PIN);
		/*for Rising Edge*/
		//SET_BIT(MCUCR_REGISTER,ISC2_PIN);
		
		/*  Enable INT2 and Global inturrupt bit at SREG   */
		SET_BIT(GICR_REGISTER,INT2_EN);
		SET_BIT(SREG_REGISTER,I_BIT);
		break;
	}
}