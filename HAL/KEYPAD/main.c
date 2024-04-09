/*
 * ATMEGA32_DRIVERS.c
 *
 * Created: 3/21/2024 6:59:19 PM
 * Author : KARIM
 */ 

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "ATmega32.h"
#include "DIO.h"
#include "LCD.h"
#include "KEYPAD.h"

//========================================================================



//=========================================================================

int main(void)
{
	//LCD initialization
	HAL_LCD_INIT();
	
	//Write to LCD
	HAL_LCD_WRITE_STRING("Ready");
	_delay_ms(1000);
	HAL_LCD_CLR_SCREEN();
	
	//Keypad initialization
	HAL_KEYPAD_INIT();
	u8 key_pressed;
	_delay_ms(50);
	
	
	while(1)
	{
		key_pressed = HAL_KEYPAD_GETKEY();
		
		switch(key_pressed){
			case 'A':
			break;
			case '?':
			HAL_LCD_CLR_SCREEN();
			break;
			default:
			HAL_LCD_WRITE_CHAR(key_pressed);
			break;
		}

	}
	
	return 0;
}

