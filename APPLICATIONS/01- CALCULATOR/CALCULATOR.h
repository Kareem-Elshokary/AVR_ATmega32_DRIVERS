/*************************************************************************/
/* Author        : Kareem Abdelkader                                   	  */
/* Project       : ATmega32_Drivers		  	                             		*/
/* File          : CALCULATOR.h						                   			      	*/
/* Date          : 22/3/2024                                        			*/
/* Version       : V1                                                			*/
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS	 */
/*************************************************************************/

/*
This project is a simple calculator that can make addition, subtraction, multiplication, division operations on two operands.
Used 4*4 keypad for getting operands and operator, and 2*16 LCD for displaying the result.
You should check the configuration files before running the code (LCD.h & KEYPAD.h).
*/


#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "ATmega32.h"
#include "DIO.h"
#include "LCD.h"
#include "KEYPAD.h"

//========================================================================

//Key pressed in the keypad
u8 KeyPressed;

//Operands and Operators
static u16 NUM1 =0, NUM2 =0, RES;
static u8  FLAG = 0 , OPERATOR;

//========================================================================

/************************************************************************/
/*                            APIs                                      */
/************************************************************************/
void CALCULATOR_INIT();
void CALCULATOR_OPERATIONS();


#endif /* CALCULATOR_H_ */
