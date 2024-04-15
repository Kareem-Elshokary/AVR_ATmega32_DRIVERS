/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : TIM.c					                       				      	*/
/* Date          : 14/4/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/



/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "TIM.h"

//=========================================================================

/************************************************************************/
/*                      Generic functions                               */
/************************************************************************/
void (* TIM0_NotificationFunction)(void) = NULL;


//=========================================================================

void TIM0_INIT(u8 mode, u8 prescaler, u8 com_mode, u8 com_output_mode)
{
	//Set the waveform generation mode of the TIM0
	if (mode == OV_MODE)
	{
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
	}
	else if (mode == PWM_MODE)
	{
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
	}
	else if (mode == CTC_MODE)
	{
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
	}
	else if (mode == FAST_PWM_MODE)
	{
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
	}
	
	//If compare match mode selected, Set the compare output mode
	if (com_mode == COM_NONPWM_MODE)
	{
		switch(com_output_mode)
		{
			case NORMAL_COM_NONPWM_MODE:
			{
				CLR_BIT(TCCR0,4);
				CLR_BIT(TCCR0,5);
			}
			break;
			case TOGGLE_COM_NONPWM_MODE:
			{
				SET_BIT(TCCR0,4);
				CLR_BIT(TCCR0,5);
			}
			break;
			case CLEAR_COM_NONPWM_MODE:
			{
				CLR_BIT(TCCR0,4);
				SET_BIT(TCCR0,5);
			}
			break;
			case SET_COM_NONPWM_MODE:
			{
				SET_BIT(TCCR0,4);
				SET_BIT(TCCR0,5);
			}
			break;
		}
	}
	else if (com_mode == COM_FASTPWM_MODE)
	{
		switch(com_output_mode)
		{
			case NORMAL_COM_FASTPWM_MODE:
			{
				CLR_BIT(TCCR0,4);
				CLR_BIT(TCCR0,5);
			}
			break;
			case CLEAR_COM_FASTPWM_MODE:
			{
				CLR_BIT(TCCR0,4);
				SET_BIT(TCCR0,5);
			}
			break;
			case SET_COM_FASTPWM_MODE:
			{
				SET_BIT(TCCR0,4);
				SET_BIT(TCCR0,5);
			}
			break;
		}
	}
	else if (com_mode == COM_PWM_MODE)
	{
		switch(com_output_mode)
		{
			case NORMAL_COM_PWM_MODE:
			{
				CLR_BIT(TCCR0,4);
				CLR_BIT(TCCR0,5);
			}
			break;
			case CLEAR_COM_PWM_MODE:
			{
				CLR_BIT(TCCR0,4);
				SET_BIT(TCCR0,5);
			}
			break;
			case SET_COM_PWM_MODE:
			{
				SET_BIT(TCCR0,4);
				SET_BIT(TCCR0,5);
			}
			break;
		}
	}
	
	//Set the clock source and prescaler 
	switch(prescaler)
	{
		case CLK_DIV_BY_0:
		{
			SET_BIT(TCCR0,0);
			CLR_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
		}
		break;
		case CLK_DIV_BY_8:
		{
			CLR_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
		}
		break;
		case CLK_DIV_BY_64:
		{
			SET_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
		}
		break;
		case CLK_DIV_BY_256:
		{
			CLR_BIT(TCCR0,0);
			CLR_BIT(TCCR0,1);
			SET_BIT(TCCR0,2);
		}
		break;
		case CLK_DIV_BY_1024:
		{
			SET_BIT(TCCR0,0);
			CLR_BIT(TCCR0,1);
			SET_BIT(TCCR0,2);
		}
		break;
		case ECS_ON_T0_FALLING_EDGE:
		{
			CLR_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			SET_BIT(TCCR0,2);
		}
		break;
		case ECS_ON_T0_RISING_EDGE:
		{
			SET_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			SET_BIT(TCCR0,2);
		}
		break;
	}
	
}


void TIM0_SET_COM_VAL(u8 com_value)
{
	//Set the OCR0 value to compare with TCNT0 value
	OCR0 = com_value;
}


void TIM0_PWM_GENERATION(u8 duty_cycle)
{
	//Initialize timer with 0
	TCNT0 = 0; 

	//Set Compare value
	OCR0 = (duty_cycle * 255) / 100; 
}


void TIM0_SETCALLBACK(void (*NotificationFunction)(void))
{
	//Assign the function address to the global pointer to function
	TIM0_NotificationFunction = NotificationFunction;
}
