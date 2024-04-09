/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : KEYPAD.h						                     			      	*/
/* Date          : 8/4/2024		                                    				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/


#ifndef KEYPAD_H_
#define KEYPAD_H_

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#define F_CPU 1000000UL

#include "ATmega32.h"
#include "DIO.h"
#include "util/delay.h"

//========================================================================

/************************************************************************/
/*                     User Configuration                               */
/************************************************************************/

#define KEYPAD_PORT				  PORTD
#define KEYPAD_PORT_DIR			DDRD
#define KEYPAD_PIN				  PIND

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

//========================================================================

/************************************************************************/
/*                            APIs                                      */
/************************************************************************/

void HAL_KEYPAD_INIT();
char HAL_KEYPAD_GETKEY();


#endif /* KEYPAD_H_ */
