/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : DIO.h					                       				      	*/
/* Date          : 21/3/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/


/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "DIO.h"

//=========================================================================

void DIO_PIN_DIRECTION(u8 PORT, u8 PIN, u8 DIRECTION)
{
	// Port A
	if (PORT == DIOA)
	{
		if (DIRECTION == INPUT) //Input
		{
			CLR_BIT(DDRA,PIN);
		}
		else if(DIRECTION == OUTPUT) //Output
		{
			SET_BIT(DDRA,PIN);
		}
	}

	// Port B
	if (PORT == DIOB)
	{
		if (DIRECTION == INPUT) //Input
		{
			CLR_BIT(DDRB,PIN);
		}
		else if(DIRECTION == OUTPUT) //Output
		{
			SET_BIT(DDRB,PIN);
		}
	}

	// Port C
	if (PORT == DIOC)
	{
		if (DIRECTION == INPUT) //Input
		{
			CLR_BIT(DDRC,PIN);
		}
		else if(DIRECTION == OUTPUT) //Output
		{
			SET_BIT(DDRC,PIN);
		}
	}

	// Port D
	if (PORT == DIOD)
	{
		if (DIRECTION == INPUT) //Input
		{
			CLR_BIT(DDRD,PIN);
		}
		else if(DIRECTION == OUTPUT) //Output
		{
			SET_BIT(DDRD,PIN);
		}
	}

}


void DIO_PORT_DIRECTION(u8 PORT, u8 DIRECTION)
{
	// Port A
	if (PORT == DIOA) //Input
	{
		if (DIRECTION == INPUT)
		{
			DDRA = 0x00;
		}
		else if (DIRECTION == OUTPUT) //Output
		{
			DDRA = 0xFF;
		}
	}

	// Port B
	if (PORT == DIOB) //Input
	{
		if (DIRECTION == INPUT)
		{
			DDRB = 0x00;
		}
		else if (DIRECTION == OUTPUT) //Output
		{
			DDRB = 0xFF;
		}
	}

	// Port C
	if (PORT == DIOC) //Input
	{
		if (DIRECTION == INPUT)
		{
			DDRC = 0x00;
		}
		else if (DIRECTION == OUTPUT) //Output
		{
			DDRC = 0xFF;
		}
	}


	// Port D
	if (PORT == DIOD) //Input
	{
		if (DIRECTION == INPUT)
		{
			DDRD = 0x00;
		}
		else if (DIRECTION == OUTPUT) //Output
		{
			DDRD = 0xFF;
		}
	}
}



void DIO_WRITE_PIN(u8 PORT, u8 PIN, u8 STATUS)
{
	switch(PORT)
	{
		case DIOA:
		{
			if (STATUS == LOW)
			{
				CLR_BIT(PORTA,PIN); //pin is driven high (one)
			}
			else
			{
				SET_BIT(PORTA,PIN); //pin is driven low (zero)
			}
		}
		break;
		case DIOB:
		{
			if (STATUS == LOW)
			{
				CLR_BIT(PORTB,PIN); //pin is driven high (one)
			}
			else
			{
				SET_BIT(PORTB,PIN); //pin is driven low (zero)
			}
		}
		break;
		case DIOC:
		{
			if (STATUS == LOW)
			{
				CLR_BIT(PORTC,PIN); //pin is driven high (one)
			}
			else
			{
				SET_BIT(PORTC,PIN); //pin is driven low (zero)
			}
		}
		break;
		case DIOD:
		{
			if (STATUS == LOW)
			{
				CLR_BIT(PORTD,PIN); //pin is driven high (one)
			}
			else
			{
				SET_BIT(PORTD,PIN); //pin is driven low (zero)
			}
		}
		break;
	}
}


void DIO_WRITE_PORT(u8 PORT, u8 STATUS)
{
	switch(PORT)
	{
		case DIOA:
		{
			PORTA = STATUS;
		}
		break;
		case DIOB:
		{
			PORTB = STATUS;
		}
		break;
		case DIOC:
		{
			PORTC = STATUS;
		}
		break;
		case DIOD:
		{
			PORTD = STATUS;
		}
		break;
	}
}


u8 DIO_GET_PIN_VAL(u8 PORT, u8 PIN)
{
	volatile u8 pin_val;

	switch(PORT)
	{
		case DIOA:
		{
			pin_val = GET_BIT(PINA,PIN);
		}
		break;

		case DIOB:
		{
			pin_val = GET_BIT(PINB,PIN);
		}
		break;
		case DIOC:
		{
			pin_val = GET_BIT(PINC,PIN);
		}
		break;
		case DIOD:
		{
			pin_val = GET_BIT(PIND,PIN);
		}
		break;
	}

	return pin_val;
}


u8 DIO_GET_PORT_VAL(u8 PORT)
{
	volatile u8 port_val;

	switch (PORT)
	{
		case DIOA:
		{
			port_val = PINA;
		}
		break;
		case DIOB:
		{
			port_val = PINB;
		}
		break;
		case DIOC:
		{
			port_val = PINC;
		}
		break;
		case DIOD:
		{
			port_val = PIND;
		}
		break;
	}

	return port_val;
}


void DIO_TOG_PIN(u8 PORT, u8 PIN)
{
	switch(PORT)
	{
		case DIOA:
		{
			TOG_BIT(PORTA,PIN);
		}
		break;
		case DIOB:
		{
			TOG_BIT(PORTB,PIN);
		}
		break;
		case DIOC:
		{
			TOG_BIT(PORTC,PIN);
		}
		break;
		case DIOD:
		{
			TOG_BIT(PORTD,PIN);
		}
		break;
	}
}

