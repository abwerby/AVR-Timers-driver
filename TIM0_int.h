/*
 * TIM0_int.h
 *
 *  Created on: Nov 10, 2018
 *      Author: abood
 */

#ifndef TIM0_INT_H_
#define TIM0_INT_H_

#define CLK 12000000

#define TIMER_PRESCALER_1 1
#define TIMER_PRESCALER_8 2
#define TIMER_PRESCALER_64 3
#define TIMER_PRESCALER_256 4
#define TIMER_PRESCALER_1024 5

void TIM0_OVF_VidInit(u8 prescaler, u8 Init_Ticks , void (*f)());
void TIM0_CTC_VidInit(u8 prescaler, u8 Init_Ticks , void (*f)());
void TIM1_OVF_VidInit(u8 prescaler, u16 Init_Ticks , void (*f)());
void TIM1_CTC_VidInit(u8 prescaler, u16 Init_Ticks , void (*f)());


void TIM0_Stop();
void TIM1_Stop();


#endif /* TIM0_INT_H_ */
