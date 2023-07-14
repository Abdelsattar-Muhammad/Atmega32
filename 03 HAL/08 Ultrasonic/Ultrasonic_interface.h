/*
 * Ultrasonic_interface.h
 *
 * Created: 01/07/2023 10:29:06 م
 *  Author: Abdelsattar
 */ 


#ifndef ULTRASONIC_INTERFACE_H
#define ULTRASONIC_INTERFACE_H

#define  Ultrasonic_PORT DPORT 


typedef enum{
	Ultrasonic1=Pin0,
	Ultrasonic2=Pin1,
	Ultrasonic3=Pin2,
	Ultrasonic4=Pin3,
	Ultrasonic5=Pin4,
	}Ultrasonic_t;
	

void Ultrasonic_Init(void);
u8 Ultrasonic_GetDistance(Ultrasonic_t UltrasonicNumber);


#endif /* ULTRASONIC_INTERFACE_H_ */