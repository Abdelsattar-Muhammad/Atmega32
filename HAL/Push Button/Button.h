
/*
 * Button.h
 *
 * Created: 14/04/2023 10:16:52 م
 *  Author: Abdelsattar
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
void Button_initi(u8 portName,u8 pinNumber);

void Button_Pullup_initi(u8 portName,u8 pinNumber);
u8 Button_u8Read(u8 portName,u8 pinNumber);




#endif /* BUTTON_H_ */
