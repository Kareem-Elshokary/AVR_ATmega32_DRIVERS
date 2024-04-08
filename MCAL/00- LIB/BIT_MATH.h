/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : BIT_MATH.h					                     			      	*/
/* Date          : 21/3/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*********************************
 * 	Bit Math
 ********************************/

// Set Specific Bit
#define SET_BIT(REG,BIT)			(REG |= (1<<BIT))

// Clear Specific Bit
#define CLR_BIT(REG,BIT)			(REG &= ~(1<<BIT))

// Toggle Specific Bit
#define TOG_BIT(REG,BIT)			(REG ^= (1<<BIT))

// Get Specific Bit Value
#define GET_BIT(REG,BIT)			((REG>>BIT) & 0x01)

// Assign Value to a Specific Bit
#define ASS_BIT(REG,BIT,VAL)		(VAL==0)? CLR_BIT(REG,BIT) : SET_BIT(REG,BIT)

//===========================================================================



#endif /* BIT_MATH_H_ */