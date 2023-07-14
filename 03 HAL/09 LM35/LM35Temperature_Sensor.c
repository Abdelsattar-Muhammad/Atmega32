/*
 * LM35Temperature_Sensor.c
 *
 * Created: 01/07/2023 09:50:53 م
 *  Author: Abdelsattar
 */ 
#include "BIT_MATH.h"
#include "DATA_TYPES.h"

#include "LM35Temperature_Sensor.h"

#include "ADC_interface.h"

u8 LM35_GetTemperature(void)
{
	u8 Temp=((f32)ADC_Read()*.488);
	return Temp;
}