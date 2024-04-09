/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : GPIO.h					                       				      	*/
/* Date          : 21/3/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/


#ifndef GPIO_H_
#define GPIO_H_

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "ATmega32.h"

//=========================================================================

/************************************************************************/
/*                        Pin Configuration                             */
/************************************************************************/
/*
To use a pin as input/output pin you should configure the following:
1- Port
2- Pin Number
3- Pin Direction (Input/Output)
*/

// Port Macros
#define DIOA		0
#define DIOB		1
#define DIOC		3
#define DIOD		4

// Pin Macros
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

// Pin Direction Macros
#define INPUT		0
#define OUTPUT		1

// Pin status
#define LOW			0
#define HIGH		1

//===============================================================

/************************************************************************/
/*                            APIs                                      */
/************************************************************************/

// Pin and Port direction initialization
void DIO_PIN_DIRECTION(u8 PORT, u8 PIN, u8 DIRECTION);
void DIO_PORT_DIRECTION(u8 PORT, u8 DIRECTION);

// Write Value to a Pin (high/low)
void DIO_WRITE_PIN(u8 PORT, u8 PIN, u8 STATUS);
void DIO_WRITE_PORT(u8 PORT, u8 STATUS);

// Read Pin/Port Value
u8 DIO_GET_PIN_VAL(u8 PORT, u8 PIN);
u8 DIO_GET_PORT_VAL(u8 PORT);

// Toggle Pin/Port Value
void DIO_TOG_PIN(u8 PORT, u8 PIN);




#endif /* GPIO_H_ */
