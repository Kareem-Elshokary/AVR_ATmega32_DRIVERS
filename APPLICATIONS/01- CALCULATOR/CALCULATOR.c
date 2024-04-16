/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : CALCULATOR.c					                   				      	*/
/* Date          : 22/3/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "CALCULATOR.h"

//========================================================================

void CALCULATOR_INIT()
{
	//LCD initialization
	HAL_LCD_INIT();

	//Keypad initialization
	HAL_KEYPAD_INIT();
	
	_delay_ms(50);
	
	HAL_LCD_WRITE_STRING("READY");
	_delay_ms(1000);
	HAL_LCD_CLR_SCREEN();
}


void CALCULATOR_OPERATIONS()
{
	
	KeyPressed = HAL_KEYPAD_GETKEY();
	
	switch(KeyPressed)
	{
		case 'A':
		{
			//No key pressed
		}
		break;
		case '?':
		{
			HAL_LCD_CLR_SCREEN();
			NUM1 =0;
			NUM2 =0;
			FLAG =0;
		}
		break;
		default:
		{
			//Send the key to LCD
			HAL_LCD_WRITE_CHAR(KeyPressed);
			if(KeyPressed == '=')
			{
				HAL_LCD_gotoXY(2,0);
				
				if (OPERATOR == '*')
				{
					RES = NUM1*NUM2;
					HAL_LCD_WRITE_NUMBER(RES);
					
				}
				else if (OPERATOR == '/')
				{
					if (NUM2  != 0)
					{
						RES = NUM1/NUM2;
						HAL_LCD_WRITE_NUMBER(RES);
					}
					else
					{
						HAL_LCD_CLR_SCREEN();
						HAL_LCD_WRITE_STRING("Error... divide by 0 !!");
					}
					
				}
				else if (OPERATOR == '+')
				{
					RES = NUM1+NUM2;
					HAL_LCD_WRITE_NUMBER(RES);
				}
				else if (OPERATOR == '-')
				{
					RES = NUM1-NUM2;
					HAL_LCD_WRITE_NUMBER(RES);
				}
			}
			else if((KeyPressed == '*' )||(KeyPressed ==  '/') ||(KeyPressed ==  '-')||(KeyPressed ==  '+') )
			{
				OPERATOR = KeyPressed;
				FLAG = 1;
			}
			else
			{
				if (FLAG == 0)
				{
					NUM1 = NUM1*10 + (KeyPressed-48);
				}
				else
				{
					NUM2 = NUM2*10 + (KeyPressed-48);
				}
			}
		}
		break;
	}
}