/*
 * ATMEGA32_DRIVERS.c
 *
 * Created: 3/21/2024 6:59:19 PM
 * Author : KARIM
 */ 

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "ATmega32.h"
#include "DIO.h"
#include "TIM.h"

#define F_CPU 1000000UL
#include "util/delay.h"

//========================================================================



//=========================================================================

int main(void)
{
	//Set PortB Pin3 as output (OC0)
	DIO_PIN_DIRECTION(DIOB,PIN3,OUTPUT);
	
	//Initialize TIM0
	TIM0_INIT(PWM_MODE,CLK_DIV_BY_8,COM_PWM_MODE,CLEAR_COM_PWM_MODE);
	
	while(1)
	{
		TIM0_PWM_GENERATION(0);
		_delay_ms(2000);
		TIM0_PWM_GENERATION(25);
		_delay_ms(2000);
		TIM0_PWM_GENERATION(50);
		_delay_ms(2000);
		TIM0_PWM_GENERATION(75);
		_delay_ms(2000);
		TIM0_PWM_GENERATION(100);
		_delay_ms(2000);
	}
	
	return 0;
}

