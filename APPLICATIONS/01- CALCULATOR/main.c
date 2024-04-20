/*
 * ATMEGA32_DRIVERS.c
 *
 * Created: 3/21/2024 6:59:19 PM
 * Author : KARIM
 */ 

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "CALCULATOR.h"

//========================================================================


//========================================================================

//=========================================================================

int main(void)
{
		
	CALCULATOR_INIT();
	
	
	while (1)
	{
			CALCULATOR_OPERATIONS();
	}
	
	
	return 0;
}

//=========================================================================
