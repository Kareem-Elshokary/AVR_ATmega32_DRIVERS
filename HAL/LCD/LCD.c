/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  */
/* Project       : ATmega32_Drivers		  	                             	  */
/* File          : LCD.c						                  */
/* Date          : 23/3/2024                                        			  */
/* Version       : V2                                                			  */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		  */
/*************************************************************************/


/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "LCD.h"


//=========================================================================

/************************************************************************/
/*                        Generic Functions                             */
/************************************************************************/

void HAL_LCD_ENABLE(void)
{
	//EN (1 then 0 --> falling edge)
	SET_BIT(LCD_CTRL,EN);
	_delay_ms(10);
	CLR_BIT(LCD_CTRL,EN);
}

//=========================================================================

//Function to check if LCD is busy
void HAL_LCD_ISBUSY(void)
{
	
	LCD_PORT = 0;
	
	//Control pins initialization
	DIO_PIN_DIRECTION(LCD_CTRL, RW, OUTPUT);
	DIO_PIN_DIRECTION(LCD_CTRL, RS, OUTPUT);
	DIO_PIN_DIRECTION(LCD_CTRL, EN, OUTPUT);
	
	//Set data direction to input for reading busy flag
	DIO_PORT_DIRECTION(LCD_PORT_DDR, INPUT);
	
	//Read command mode
	DIO_WRITE_PIN(LCD_CTRL, RW, HIGH);
	DIO_WRITE_PIN(LCD_CTRL, RS, LOW);
	DIO_WRITE_PIN(LCD_CTRL, EN, HIGH);
	
	//Delay for stable operation
	while( (LCD_PORT & (1<<7) >> 7 ) );   
	
	//Disable LCD
	DIO_WRITE_PIN(LCD_CTRL, EN, LOW);       
	
	//Set data direction back to output for writing data
	DIO_PORT_DIRECTION(LCD_PORT_DDR, INPUT);  
	
	//Write mode
	DIO_WRITE_PIN(LCD_CTRL, RW, LOW);
}


// Function to initialize the LCD
void HAL_LCD_INIT(void)
{
	_delay_ms(50);
	
	//Control pins initialization
	DIO_PIN_DIRECTION(DIOB, RW, OUTPUT);
	DIO_PIN_DIRECTION(DIOB, RS, OUTPUT);
	DIO_PIN_DIRECTION(DIOB, EN, OUTPUT);
	
	//Data pins initialization
	DIO_PORT_DIRECTION(LCD_PORT_DDR, OUTPUT);
	
	//Write command mode
	DIO_WRITE_PIN(LCD_CTRL, RW, LOW);
	DIO_WRITE_PIN(LCD_CTRL, RS, LOW);
	DIO_WRITE_PIN(LCD_CTRL, EN, LOW);
	
	//Delay for stable operation
	_delay_ms(50);										

	// Initialize LCD with specific commands
	HAL_LCD_ISBUSY();
	HAL_LCD_SEND_COMMAND(LCD_CLEAR_SCREEN);
	HAL_LCD_ISBUSY();
	HAL_LCD_SEND_COMMAND(LCD_RETURN_HOME);
	HAL_LCD_ISBUSY();
	HAL_LCD_SEND_COMMAND(LCD_ENTRY_MODE);
	
	HAL_LCD_ISBUSY();
	HAL_LCD_SEND_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	HAL_LCD_ISBUSY();
	HAL_LCD_SEND_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
	HAL_LCD_ISBUSY();
	HAL_LCD_SEND_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	
}


void HAL_LCD_CLR_SCREEN(void)
{
	HAL_LCD_SEND_COMMAND(LCD_CLEAR_SCREEN);	
}


void HAL_LCD_SEND_COMMAND(unsigned char command)
{
	//Check if LCD is busy
	HAL_LCD_ISBUSY();
	
	DIO_WRITE_PORT(LCD_PORT,command);
	
	CLR_BIT(LCD_CTRL,RS);
	
	HAL_LCD_ENABLE();
}


void HAL_LCD_WRITE_CHAR(unsigned char ch)
{
	//Check if LCD is busy
	HAL_LCD_ISBUSY();
	
	DIO_WRITE_PORT(LCD_PORT,ch);
	
	SET_BIT(LCD_CTRL,RS);
	
	HAL_LCD_ENABLE();
}


void HAL_LCD_WRITE_STRING(unsigned char*p)
{
	char index=0;
	
	//Check if LCD is busy
	HAL_LCD_ISBUSY();
	
	while(p[index])
	{
		if(index == 16)
		{
			LCD_CTRL &= ~(1<<RS);
			HAL_LCD_SEND_COMMAND(LCD_BEGIN_AT_SECOND_ROW);
			HAL_LCD_ENABLE();
			LCD_CTRL |= (1<<RS);
		}
		LCD_PORT = p[index];
		
		SET_BIT(LCD_CTRL,RS);
		
		
		HAL_LCD_ENABLE();
		index++;
	}
}


void HAL_LCD_WRITE_NUMBER(s16 number)
{
	u8 str[10];
	sprintf(str,"%d",number);
	HAL_LCD_WRITE_STRING(str);
}


void HAL_LCD_gotoXY(u8 line , u8 position)
{
	//line 1
	if (line == 1) 
	{
		if(position < 16 && position >= 0)
		HAL_LCD_SEND_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
	}
	//line 2
	if (line == 2) 
	{
		if(position < 16 && position >= 0)
		HAL_LCD_SEND_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
	}
}
