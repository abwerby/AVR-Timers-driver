/*
 * TIM0_prog.c
 *
 *  Created on: Nov 10, 2018
 *      Author: abood
 */
#include "avr/interrupt.h"
#include "avr/io.h"
#include "LIB/STD_TYPES.h"
#include "TIM0_int.h"
#include "LIB/BIT_MATH.h"

void (*CTC_t0_func)();
void (*OVF_t0_func)();
void (*CTC_t1_func)();
void (*OVF_t1_func)();


void TIM0_CTC_VidInit(u8 prescaler, u8 Init_Ticks , void (*f)() )
{

	CTC_t0_func = f;

	/* set ctc mode */
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/* set timer count */
	OCR0 = Init_Ticks ;


	/* set  pin OC0 mode */
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);


	/* set prescaller */

	switch (prescaler)
	{
	case 1 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
	case 2 :
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
	case 3 :
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;

	case 4 :
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;

	case 5 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	}

	SET_BIT(TIMSK,OCIE0);
	SET_BIT(SREG,7);
}

ISR(TIMER0_COMP_vect){
	CTC_t0_func();

}

void TIM0_OVF_VidInit(u8 prescaler, u8 Init_Ticks , void (*f)() )
{

	OVF_t0_func = f;

	/* set normal mode */
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

	/* set timer count */
	TCNT0 = Init_Ticks ;

	/* set prescaller */

	switch (prescaler)
	{
	case 1 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
	case 2 :
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
	case 3 :
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;

	case 4 :
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;

	case 5 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	}

	SET_BIT(TIMSK,TOIE0);
	SET_BIT(SREG,7);
}

ISR(TIMER0_OVF_vect)
{
	OVF_t0_func();
}

void TIM0_Stop()
{
	TCCR0 = 0;
}


void TIM1_OVF_VidInit(u8 prescaler, u16 Init_Ticks , void (*f)() )
{
	OVF_t1_func = f;
	/* set normal mode */
	CLR_BIT(TCCR1A,WGM00);
	CLR_BIT(TCCR1A,WGM01);

	/* set timer count */
	TCNT1 = Init_Ticks ;

	/* set prescaller */

	switch (prescaler)
	{
	case 1 :
		SET_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;
	case 2 :
		CLR_BIT(TCCR1B,CS00);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;
	case 3 :
		SET_BIT(TCCR1B,CS00);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;

	case 4 :
		CLR_BIT(TCCR1B,CS00);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;

	case 5 :
		SET_BIT(TCCR1B,CS00);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
	}

	SET_BIT(TIMSK,TOIE1);
	SET_BIT(SREG,7);
}

ISR(TIMER1_OVF_vect)
{
	OVF_t1_func();
}

void TIM1_CTC_VidInit(u8 prescaler, u16 Init_Ticks , void (*f)() )
{
	CTC_t1_func = f;
	/* set CTC mode */
	CLR_BIT(TCCR1A,WGM00);
	CLR_BIT(TCCR1A,WGM01);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);

	/* set timer count */
	OCR1A = Init_Ticks ;

	/* set  pin OC0 mode */
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);


	/* set prescaller */

	switch (prescaler)
	{
	case 1 :
		SET_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;
	case 2 :
		CLR_BIT(TCCR1B,CS00);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;
	case 3 :
		SET_BIT(TCCR1B,CS00);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;

	case 4 :
		CLR_BIT(TCCR1B,CS00);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;

	case 5 :
		SET_BIT(TCCR1B,CS00);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
	}

	SET_BIT(TIMSK,OCIE1A);
	SET_BIT(SREG,7);
}

ISR(TIMER1_COMPA_vect)
{
	CTC_t1_func();
}

void TIM1_Stop()
{
	TCCR1A = 0;
}
