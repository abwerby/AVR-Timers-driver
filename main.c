/*
 * main.c
 *
 *  Created on: Aug 18, 2018
 *      Author: WERBY
 */

#include "avr/io.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_int.h"
#include "TIM0_int.h"
#define F_CPU 12000000UL
#include "avr/delay.h"

u8 u8flag1 = 0 ;
u8 u8flag2 = 0 ;


void toggle1()
{
	static u16 count1 = 0 ;
	count1++;
	DIO_SetPinValue(PORTB,PIN1,HIGH);

	if(count1 == 3)
	{
		u8flag1 ^=1 ;
		count1 = 0 ;
	}
}

void toggle2()
{
	static u16 count = 0 ;
	count++;
	if(count == 100)
	{
		u8flag2 ^=1 ;
		count = 0 ;
	}
}

void main(void)
{
	DIO_SetPinDirection(PORTB,PIN0,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN1,OUTPUT);


	TIM1_CTC_VidInit(TIMER_PRESCALER_64,65000,toggle1);
	//TIM0_OVF_VidInit(TIMER_PRESCALER_64,0,toggle2);

	while(1)
	{
		if(u8flag1 == 0)
		{
			DIO_SetPinValue(PORTB,PIN0,LOW);
		}
		else
		{
			DIO_SetPinValue(PORTB,PIN0,HIGH);

		}

		DIO_SetPinValue(PORTB,PIN1,LOW);


/*
		DIO_SetPinValue(PORTB,PIN1,HIGH);
		_delay_ms(300);
		DIO_SetPinValue(PORTB,PIN1,LOW);
		_delay_ms(300);





		if(u8flag2 == 0)
		{
			DIO_SetPinValue(PORTB,PIN1,LOW);
		}
		else
		{
			DIO_SetPinValue(PORTB,PIN1,HIGH);

		}

		*/
	}

}


