/*
 * Ultrasonic.h
 *
 * Created: 30/04/2023 10:17:52 م
 *  Author: Abdelsattar
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define   TRIGER_DDR    DDRD
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTD
#define   TRIGER        0
#define   ECHO          6

void Ultrasonic_init(void);
u8 Ultrasonic_Read(void);
void Ultrasonic_Trigger(void);
#endif /* ULTRASONIC_H_ */