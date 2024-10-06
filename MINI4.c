/*
 * MINI4.c
 *
 *  Created on: Oct 15, 2021
 *      Author: kiko
 */
#include"MINI4.h"


#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h>

int main(void)
{
	uint16 distance = 0;

	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distane=");
	while(1)
	{
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0,9);
		LCD_intgerToString(distance);
		LCD_displayString("cm");
	}
}
