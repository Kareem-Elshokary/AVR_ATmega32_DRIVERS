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

//========================================================================

//Task1
void LED_ON_OFF();

//Task2
void BUTTON_LED();
u8 LED_NUM = 4;

//Task3

//=========================================================================

int main(void)
{
	// Task 1
	// Configuring portA (pins 0:7) as output 
	//DIO_PORT_DIRECTION(DIOA,OUTPUT);
	
	// Task 2
	//DIO_PIN_DIRECTION(DIOC,PIN3,INPUT);	//button
	//DIO_PIN_DIRECTION(DIOB,PIN4,OUTPUT);	//led1
	//DIO_PIN_DIRECTION(DIOB,PIN5,OUTPUT);	//led2
	//DIO_PIN_DIRECTION(DIOB,PIN6,OUTPUT);	//led3
	//DIO_PIN_DIRECTION(DIOB,PIN7,OUTPUT);	//led4
	
	// Task 3
	static u8 SEGMENT_7[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	u8 SEG7_Flag1, SEG7_Flag2 ;
	DIO_PORT_DIRECTION(DIOB,OUTPUT);
	
	
    while (1) 
    {
		for (SEG7_Flag1=0; SEG7_Flag1<10; SEG7_Flag1++)
		{
			for (SEG7_Flag2=0; SEG7_Flag2<10; SEG7_Flag2++)
			{
				PORTB = 0b1011 | (SEG7_Flag1<<4);
				_delay_ms(50);
				PORTB = 0b0111 | (SEG7_Flag2<<4);
				_delay_ms(50);
			}
		}
    }
	
}



void LED_ON_OFF()
{
	// ON
	DIO_WRITE_PIN(DIOA,PIN0,HIGH);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN1,HIGH);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN2,HIGH);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN3,HIGH);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN4,HIGH);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN5,HIGH);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN6,HIGH);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN7,HIGH);
	_delay_ms(500);
	
	// OFF
	DIO_WRITE_PIN(DIOA,PIN0,LOW);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN1,LOW);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN2,LOW);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN3,LOW);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN4,LOW);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN5,LOW);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN6,LOW);
	_delay_ms(500);
	DIO_WRITE_PIN(DIOA,PIN7,LOW);
	_delay_ms(500);
}

void BUTTON_LED()
{
	if (DIO_GET_PIN_VAL(DIOC,PIN3) == 1)
	{
		if (LED_NUM <= 7)
		{
			DIO_WRITE_PIN(DIOB,LED_NUM,HIGH);
			LED_NUM++;
		}
		else
		{
			DIO_WRITE_PORT(DIOB,LOW);
			LED_NUM = 4;
		}
		while(DIO_GET_PIN_VAL(DIOC,PIN3) == 1);
	}
	_delay_ms(200);
}