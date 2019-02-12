/*
 * TIM0_reg.h
 *
 *  Created on: Nov 10, 2018
 *      Author: abood
 */

#ifndef TIM0_REG_H_
#define TIM0_REG_H_


#define TCCR0 (*(volatile u8*)0x53)
#define TCNT0 (*(volatile u8*)0x52)
#define TIMSK (*(volatile u8*)0x59)
#define OCR0  (*(volatile u8*)0x5C)
#define SREG  (*(volatile u8*)0x5F)

#define I 7

#define WGM00 6
#define WGM01 3


#define CS02 2
#define CS01 1
#define CS00 0






#endif /* TIM0_REG_H_ */
