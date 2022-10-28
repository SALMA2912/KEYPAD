#include "STD_Types.h"

#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"

tstrKeypadInfo  KEYPAD_astrConfigSet[KEYPAD_MAX_NUM]=
{
	/* KEYPAD 0*/
	{
		/*au8SwitchMapping*/
		{ //2d array
			{'7','8','9','+'},
			{'4','5','6','-'},
			{'1','2','3','x'},
			{'.','0','/','='}
		},
		/*au8InputPinsCon*/
		{24,25,26,27},
		/*au8OutputPinsCon*/
		{28,29,30,31} ,
		{0b00001110, 0b00001101,0b00001011,0b00000111}, //mknsh ynf3 a3mlha ka switch cases 3ashn mot8yra 3la 7asab 3adad elinput pins
		/*u8InputPinNum*/
		KEYPAD0_INPUT_PIN_NUMS ,
		/*u8OutputPinNum*/
		KEYPAD0_OUTPUT_PIN_NUMS
	},
	/* KEYPAD 1*/
	{
		
		/*au8SwitchMapping*/
		{
			{'7','8','9'},
			{'4','5','6'},
			{'1','2','3'},
			{'.','0','/'},
			{'+','-','x'},
			{'=','C','%'}
		},
		/*au8InputPinsCon*/
		{16,17,18,19,20,21},
		/*au8OutputPinsCon*/
		{22,23,6} ,
		{0b00111110, 0b00111101,0b00111011,0b00110111,0b00101111,0b00011111 },
		/*u8InputPinNum*/
		KEYPAD1_INPUT_PIN_NUMS ,
		/*u8OutputPinNum*/
		KEYPAD1_OUTPUT_PIN_NUMS
	}

};





















