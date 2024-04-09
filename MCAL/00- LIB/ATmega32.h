/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : ATmega32.h				                     				      	*/
/* Date          : 21/3/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "STD_TYPES.H"
#include "BIT_MATH.h"

//========================================================================

/************************************************************************/
/*                          Register Macros                             */
/************************************************************************/

/*
	DIO
*/
// DIOA
#define DDRA				*((volatile uint8_t*) 0x3A)
#define PORTA				*((volatile uint8_t*) 0x3B)
#define PINA				*((volatile uint8_t*) 0x39)
// DIOB
#define DDRB				*((volatile uint8_t*) 0x37)
#define PORTB				*((volatile uint8_t*) 0x38)
#define PINB				*((volatile uint8_t*) 0x36)
// DIOC
#define DDRC				*((volatile uint8_t*) 0x34)
#define PORTC				*((volatile uint8_t*) 0x35)
#define PINC				*((volatile uint8_t*) 0x33)
// DIOD
#define DDRD				*((volatile uint8_t*) 0x31)
#define PORTD				*((volatile uint8_t*) 0x32)
#define PIND				*((volatile uint8_t*) 0x30)

/*
	GIE
*/
#define SREG				*((volatile uint8_t*) 0x5F)

/*
	EXTI
*/
#define GICR				*((volatile uint8_t*) 0x5B)
#define GIFR				*((volatile uint8_t*) 0x5A)
#define MCUCR				*((volatile uint8_t*) 0x55)
#define MCUCSR				*((volatile uint8_t*) 0x54)


#endif /* ATMEGA32_H_ */