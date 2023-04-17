/*
 * _7_Segment.h
 *
 * Created: 16/04/2023 01:33:16 ص
 *  Author: Abdelsattar
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_
#include "data_types.h"
#define  COMMON_CATHOD
#define ZERO    0b00111111
#define ONE     0b00000110
#define TWO     0b01011011
#define THREE   0b01001111
#define FOUR    0b01100110
#define FIVE    0b01101101
#define SIX     0b01111101
#define SEVEN   0b00000111
#define EIGHT   0b01111111
#define NINE    0b01101111
#define DOT     0b10000000

void SEVEN_SEG_initi(u8 portnamue);
void SEVEN_SEG_Write(u8 portName,u8 Number);
void SEVEN_SEG_BCD_initi(u8 portName);

void SEVEN_SEG_BCD_Write(u8 portName,u8 Number);



#endif /* 7 SEGMENT_H_ */