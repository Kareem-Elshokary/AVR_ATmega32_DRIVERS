/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : ATmega32_Drivers		  	                             			  	*/
/* File          : TIM.h					                       				      	*/
/* Date          : 14/4/2024                                        				  	*/
/* Version       : V1                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/AVR_ATmega32_DRIVERS		        */
/*************************************************************************/



#ifndef TIM_H_
#define TIM_H_

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/
#include "ATmega32.h"

//=========================================================================

/************************************************************************/
/*                        User Configuration                            */
/************************************************************************/


/* TIM0 Configurations 
	Timer/Counter0 is a general purpose, single channel, 8-bit Timer/Counter module. The
	main features are:
	  Single Channel Counter
	  Clear Timer on Compare Match (Auto Reload)
	  Glitch-free, Phase Correct Pulse Width Modulator (PWM)
	  Frequency Generator
	  External Event Counter
	  10-bit Clock Prescaler
	  Overflow and Compare Match Interrupt Sources (TOV0 and OCF0)
*/

//Mode (WGM01:0)
#define OV_MODE				  0
#define PWM_MODE			  1
#define CTC_MODE			  2
#define FAST_PWM_MODE		3

//Compare Mode
#define COM_NONPWM_MODE		1
#define COM_FASTPWM_MODE	2
#define COM_PWM_MODE		  3

//Compare Output Mode, non-PWM Mode (COM01:0)
#define NORMAL_COM_NONPWM_MODE			0
#define TOGGLE_COM_NONPWM_MODE			1
#define CLEAR_COM_NONPWM_MODE			  2
#define SET_COM_NONPWM_MODE				  3
//Compare Output Mode, Fast PWM Mode (COM01:0)
#define NORMAL_COM_FASTPWM_MODE			0
#define CLEAR_COM_FASTPWM_MODE			2
#define SET_COM_FASTPWM_MODE			  3
//Compare Output Mode, Phase Correct PWM Mode (COM01:0)
#define NORMAL_COM_PWM_MODE				  0
#define CLEAR_COM_PWM_MODE				  2
#define SET_COM_PWM_MODE				    3

//Clock Select and Prescaler (CS02:0) 
#define CLK_DIV_BY_0					      1
#define CLK_DIV_BY_8					      2
#define CLK_DIV_BY_64               3
#define CLK_DIV_BY_256              4
#define CLK_DIV_BY_1024             5
#define ECS_ON_T0_FALLING_EDGE      6
#define ECS_ON_T0_RISING_EDGE       7


//===============================================================

/************************************************************************/
/*                            APIs                                      */
/************************************************************************/

//TIM0
void TIM0_INIT(u8 mode, u8 prescaler, u8 com_mode, u8 com_output_mode);
void TIM0_SET_COM_VAL(u8 com_value);
void TIM0_SETCALLBACK(void (*NotificationFunction)(void));
void TIM0_PWM_GENERATION(u8 duty_cycle);








#endif /* TIM_H_ */
