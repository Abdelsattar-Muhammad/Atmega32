/*
 * std_macro.h
 *
 * Created: 12/04/2023 04:31:32 م
 *  Author: Abdelsattar
 */ 


#ifndef STD_MACRO_H_
#define STD_MACRO_H_


#define REGISTER_SIZE 8
#define SET_BIT(reg,bit) reg |= (1<<bit)
#define CLR_BIT(reg,bit) reg &= (~(1<<bit))
#define TOGGLE_BIT(reg,bit) reg ^= (1<<bit)
#define READ_BIT(reg,bit) ((reg>>bit)&1)
#define ROL(reg,num) reg=(reg<<num)|(reg>>(REGISTER_SIZE-num))
#define ROR(reg,num) reg=(reg>>num)|(reg<<(REGISTER_SIZE-num))
#define SET_HighNibble(reg) reg|=0xF0//240==0xF0==0b11110000
#define SET_LowNibble(reg) reg|=0x0F//15==0x0F==0b00001111
#define ClR_HighNibble(reg) reg&=0x0F
#define ClR_LowNibble(reg) reg&=0xF0
#define ass_LowNibble(reg,val) reg=(reg&0xF0)|(0x0F&val)
#define ass_HighNibble(reg,val) reg=(reg&0x0F)|(0xF0&val<<4)

#endif /* STD_MACRO_H_ */