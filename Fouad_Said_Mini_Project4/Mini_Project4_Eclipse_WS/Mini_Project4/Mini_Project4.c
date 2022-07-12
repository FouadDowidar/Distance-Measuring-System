 /******************************************************************************
 *
 * Module: Distance Measuring System
 *
 * File Name: Mini_Project4.c
 *
 * Description: Application layer for Distance Measuring System Project
 *
 * Author: Fouad Dowidar
 *
 *******************************************************************************/

#include "lcd.h"
#include "ultrasonic.h"
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	/* variable used to store value returned from ultrasonic */
	uint16 readDistance = 0;

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Description :
	 * Initialize the LCD driver.
	 */
	LCD_init();

	/* Description :
	 * Initialize the Ultrasonic driver.
	 */
	Ultrasonic_init();

	LCD_displayString("Distance=    cm");

	while(1)
	{
		readDistance = Ultrasonic_readDistance();

		/*Move the cursor to a specified row and column index on the screen*/
		LCD_moveCursor(0,10);

		/* Display the readDistance value every time at same position */
		if(readDistance >= 100)
		{

			/*Display the required decimal value on the screen*/
			LCD_intgerToString(readDistance);

		}
		else
		{

			/*Display the required decimal value on the screen*/
			LCD_intgerToString(readDistance);

			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');

		}
	}
}
