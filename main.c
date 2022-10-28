/*
 * main.c
 *
 *  Created on: 2 Sep 2022
 *      Author: HP
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
void main (void)
{
	uint8 i = 0   ;
	DIO_voidInit();
	LCD_voidInit();
	KEYPAD_voidInit();

	while (1)
	{
		i = KEYPAD_u8GetPressedKey(0);
		if(i != 0xFF)
		{
			LCD_enuWriteData(0 , i) ;
		}
	}
}


