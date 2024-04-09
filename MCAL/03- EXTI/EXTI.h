/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : EXTI.h						                   				      	*/
/* Date          : 22/3/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/


#ifndef EXTI_H_
#define EXTI_H_

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "ATmega32.h"
#include "GIE.h"

//========================================================================

/*
 * To use the EXTI pins, you should to configure the following:
 * 1- INT Pin (0/1/2)
 * 2- Trigger Case
 */

// Trigger Case
#define FALLING_EDGE		2
#define RISING_EDGE			1
#define LOW_LEVEL			  0	//Only with INT0/1

//========================================================================

/************************************************************************/
/*                            APIs                                      */
/************************************************************************/

void EXTI0_INIT(u8 T_case);
void EXTI1_INIT(u8 T_case);
void EXTI2_INIT(u8 T_case);


#endif /* EXTI_H_ */
