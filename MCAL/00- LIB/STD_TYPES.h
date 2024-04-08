/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : STD_TYPES.h					                     			      	*/
/* Date          : 21/3/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*********************************
 * 	Includes
 ********************************/
#include "stdint.h"
#include "stdio.h"


//===========================================================================

typedef unsigned char 					    u8;
typedef signed char 					      s8;
typedef volatile unsigned char 			vu8;


typedef unsigned short int 				      u16;
typedef signed short int 				        s16;
typedef volatile unsigned short int		  vu16;

typedef unsigned long  int 				    u32;
typedef signed long  int 				      s32;
typedef volatile unsigned long  int		vu32;

typedef float  							f32;
typedef double 							f64;


//===========================================================================


#endif /* STD_TYPES_H_ */
