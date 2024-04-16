/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : LCD.h						                     			      	          */
/* Date          : 23/3/2024                                        				  	*/
/* Version       : V2                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		  */
/*************************************************************************/


#ifndef LCD_H_
#define LCD_H_

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#define F_CPU 1000000UL

#include "ATmega32.h"
#include "DIO.h"
#include "util/delay.h"
#include <string.h>

//===================================================================================================

/************************************************************************/
/*                     User Configuration                               */
/************************************************************************/

//lcd data
#define LCD_PORT				  PORTA
#define LCD_PORT_DDR			DDRA
#define LCD_INPUT				  PINA


//lcd control
#define LCD_CTRL				PORTB
#define RS						  1
#define RW						  2
#define EN						  3
#define DATA_SHIFT			0		// in 8 bit mode 0 and in 4 bit mode 4


// When you select a mode, put the other in a comment
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE



//LCD Commands
#define LCD_FUNCTION_8BIT_2LINES   					0x38	
#define LCD_FUNCTION_4BIT_2LINES   					0x28	
#define LCD_MOVE_DISP_RIGHT       					0x1C
#define LCD_MOVE_DISP_LEFT   						    0x18
#define LCD_MOVE_CURSOR_RIGHT   					  0x14
#define LCD_MOVE_CURSOR_LEFT 	  					  0x10
#define LCD_DISP_OFF   								      0x08
#define LCD_DISP_ON_CURSOR   						    0x0E
#define LCD_DISP_ON_CURSOR_BLINK   					0x0F
#define LCD_DISP_ON_BLINK   						    0x0D
#define LCD_DISP_ON   								      0x0C	
#define LCD_ENTRY_DEC   							      0x04
#define LCD_ENTRY_DEC_SHIFT   						  0x05
#define LCD_ENTRY_INC_   							      0x06	
#define LCD_ENTRY_INC_SHIFT   						  0x07
#define LCD_BEGIN_AT_FIRST_ROW						  0x80	
#define LCD_BEGIN_AT_SECOND_ROW						  0xC0
#define LCD_CLEAR_SCREEN							      0x1	
#define LCD_ENTRY_MODE								      0x6
#define LCD_RETURN_HOME								      0x2


//=============================================================================================================

/************************************************************************/
/*                            APIs                                      */
/************************************************************************/

void HAL_LCD_INIT(void);
void HAL_LCD_ISBUSY(void);
void HAL_LCD_CLR_SCREEN(void);

void HAL_LCD_SEND_COMMAND(unsigned char command );
void HAL_LCD_WRITE_CHAR(unsigned char);
void HAL_LCD_WRITE_STRING(unsigned char*);
void HAL_LCD_WRITE_NUMBER(s16 number);
void HAL_LCD_gotoXY(u8 line , u8 position);

#endif /* LCD_H_ */
