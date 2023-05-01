/*
 * Servo_Motor.c
 *
 * Created: 01/05/2023 03:53:58 ص
 *  Author: Abdelsattar
 */ 
#include "Servo Motor.h"
void Servo_motor(s8 angle)
{
	d32 val;
	if (angle>0)
	{
		val=((0.5/90)*angle)+1.5;
		TIMER1_FastPWM(val);
	} 
	else
	{
		val=1.5+((0.5/90)*angle);
		TIMER1_FastPWM(val);
	}
}