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
#include "GIE.h"
#include "EXTI.h"

//========================================================================



//=========================================================================

int main(void)
{
	//PD2 (INT0) config as PU input
	DIO_PIN_DIRECTION(DIOD,PIN2,INPUT);
	DIO_WRITE_PIN(DIOD,PIN2,HIGH);
	//PA0 config as output
	DIO_PIN_DIRECTION(DIOA,PIN0,OUTPUT);
	
	//Enable global interrupt
	GIE_ENABLE();
	
	//EXTI
	EXTI0_INIT(RISING_EDGE);
	
	while(1)
	{
		
	}
	
	return 0;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	DIO_WRITE_PIN(DIOA,PIN0,HIGH);
}
