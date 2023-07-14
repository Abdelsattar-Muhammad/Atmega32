/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 June 2023            */
/* Version : V01					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H


#define REGISTER_SIZE 8
#define SET_BIT(Reg,BitN) Reg |= (1<<BitN)
#define CLR_BIT(Reg,BitN) Reg &= (~(1<<BitN))
#define TOGGLE_BIT(Reg,BitN) Reg ^= (1<<BitN)
#define GET_BIT(Reg,BitN) ((Reg>>BitN)&1)
#define ROL(Reg,Num) reg=(Reg<<Num)|(Reg>>(REGISTER_SIZE-Num))
#define ROR(reg,num) reg=(Reg>>Num)|(Reg<<(REGISTER_SIZE-Num))

#endif /* STD_MACRO_H_ */