/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : KEYPAD.c						                     			      	*/
/* Date          : 8/4/2024		                                    				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "KEYPAD.h"

//========================================================================

/************************************************************************/
/*                      Generic Macros                                  */
/************************************************************************/

int Key_padRow[] = {R0, R1, R2, R3};	//Rows 
int Key_padCol[] = {C0, C1, C2, C3};	//Columns

//========================================================================

void HAL_KEYPAD_INIT(){
	CLR_BIT(KEYPAD_PORT_DIR,R0);
	CLR_BIT(KEYPAD_PORT_DIR,R1);
	CLR_BIT(KEYPAD_PORT_DIR,R2);
	CLR_BIT(KEYPAD_PORT_DIR,R3);
	
	SET_BIT(KEYPAD_PORT_DIR,C0);
	SET_BIT(KEYPAD_PORT_DIR,C1);
	SET_BIT(KEYPAD_PORT_DIR,C2);
	SET_BIT(KEYPAD_PORT_DIR,C3);
	
	KEYPAD_PORT = 0xFF;
}


char HAL_KEYPAD_GETKEY(){
	int i,j;
	for (i = 0; i < 4; i++){
		KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));
		KEYPAD_PORT &= ~(1<<Key_padCol[i]);
		
		for(j = 0; j < 4; j++){
			if (!(KEYPAD_PIN & (1 << Key_padRow[j])))
			{
				while(!(KEYPAD_PIN & (1 << Key_padRow[j])));
				switch(i){
					case (0):
					if (j == 0) return '7';
					else if (j == 1) return '4';
					else if (j == 2) return '1';
					else if (j == 3) return '?';
					break;
					case (1):
					if (j == 0) return '8';
					else if (j == 1) return '5';
					else if (j == 2) return '2';
					else if (j == 3) return '0';
					break;
					case (2):
					if (j == 0) return '9';
					else if (j == 1) return '6';
					else if (j == 2) return '3';
					else if (j == 3) return '=';
					break;
					case (3):
					if (j == 0) return '/';
					else if (j == 1) return '*';
					else if (j == 2) return '-';
					else if (j == 3) return '+';
					break;
				}
			}
		}
	}
	return 'A';
}
