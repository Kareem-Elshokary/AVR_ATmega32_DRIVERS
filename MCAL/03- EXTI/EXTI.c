/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : EXTI.c						                   				      	*/
/* Date          : 22/3/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "EXTI.h"

//========================================================================

/************************************************************************/
/*                      Generic Macros                                  */
/************************************************************************/

//MCU Control Register (MCUCR)
#define MCUCR_ISC00			0	// Interrupt Sense Control 0 (INT0)
#define MCUCR_ISC01			1
#define MCUCR_ISC10			2	// Interrupt Sense Control 1 (INT1)
#define MCUCR_ISC11			3

//MCU Control and Status Register  (MCUCSR)
#define MCUCSR_ISC2			6	// Interrupt Sense Control 2 (INT2)

//General Interrupt Control Register (GICR)
#define GICR_INT1			7	//External Interrupt Request 1 Enable
#define GICR_INT0			6	//External Interrupt Request 0 Enable
#define GICR_INT2			5	//External Interrupt Request 2 Enable


//==========================================================================

void EXTI0_INIT(u8 T_case)
{
	// Enable Global Interrupt
	GIE_ENABLE();

	// Enable External Interrupt Request 0
	SET_BIT(GICR,GICR_INT0);

	// Set trigger case
	switch (T_case) {
		case LOW_LEVEL:
		{
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
		}
		break;
		case RISING_EDGE:
		{
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
		}
		break;
		case FALLING_EDGE:
		{
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
		}
		break;
	}
}



void EXTI1_INIT(u8 T_case)
{
	// Enable Global Interrupt
	GIE_ENABLE();

	// Enable External Interrupt Request 1
	SET_BIT(GICR,GICR_INT1);

	// Set trigger case
	switch (T_case) {
		case LOW_LEVEL:
		{
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
		}
		break;
		case RISING_EDGE:
		{
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
		}
		break;
		case FALLING_EDGE:
		{
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
		}
		break;
	}
}


void EXTI2_INIT(u8 T_case)
{
	// Enable Global Interrupt
	GIE_ENABLE();

	// Enable External Interrupt Request 2
	SET_BIT(GICR,GICR_INT2);

	// Set trigger case
	switch (T_case) {
		case RISING_EDGE:
		{
			SET_BIT(MCUCSR,MCUCSR_ISC2);
		}
		break;
		case FALLING_EDGE:
		{
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
		}
		break;
	}
}
