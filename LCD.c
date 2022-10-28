
#include "STD_Types.h"
#include "BIT_MAth.h"
#include <avr/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"

void LCD_voidInit(void)
{
	uint8 u8CntrLoc ;
	uint8 u8CmdLoc  ;
	for(u8CntrLoc = 0 ; u8CntrLoc < LCD_MAX_NUM ; u8CntrLoc++)
	{
		if (LCD_astrConfig[u8CntrLoc].strLcdPinOutCfg.u8LcdMode== LCD_8BIT_MODE)
		{
				_delay_ms(30);
				u8CmdLoc = 0b00110000|
				LCD_astrConfig[u8CntrLoc].strLcdOptionCfg.u8LineMode << 3|
				LCD_astrConfig[u8CntrLoc].strLcdOptionCfg.u8CharFont << 2;
				LCD_enuWriteCmd (u8CntrLoc , u8CmdLoc);
				_delay_ms(1);
				u8CmdLoc = 0b00001000|
				LCD_astrConfig[u8CntrLoc].strLcdOptionCfg.u8DisplayState << 2|
				LCD_astrConfig[u8CntrLoc].strLcdOptionCfg.u8CursorState << 1|
				LCD_astrConfig[u8CntrLoc].strLcdOptionCfg.u8BlinkState << 0;
				LCD_enuWriteCmd (u8CntrLoc , u8CmdLoc);
				_delay_ms(1);
				LCD_enuWriteCmd (u8CntrLoc , 0x01);
				_delay_ms(2);
				u8CmdLoc = 0b00000100|
				LCD_astrConfig[u8CntrLoc].strLcdOptionCfg.u8IncreMode << 1|
				LCD_astrConfig[u8CntrLoc].strLcdOptionCfg.u8WindowMode << 0;
				LCD_enuWriteCmd (u8CntrLoc , u8CmdLoc);
				_delay_ms(1);
				
				
				
				
				
		}
		else
		{
			
		}
		
	}
}
tenuErrorStatus LCD_enuWriteCmd(uint8 u8LcdIndxCpy , uint8 u8LcdCmdCpy)
{
 tenuErrorStatus enuReturStateLoc = E_OK ;
 if(u8LcdIndxCpy < LCD_MAX_NUM)
 {
	//write DIO rs
	DIO_enuWritePin(LCD_astrConfig[u8LcdIndxCpy].strLcdPinOutCfg.au8ControlPins[0] , 0) ;
   // help cmd	
   LCD_voidHelp(u8LcdIndxCpy, u8LcdCmdCpy);
   
   
 }
 else
 {
	 enuReturStateLoc = E_NOK_PARAM_OUT_OF_RANGE ;
 }
	return enuReturStateLoc ;
}
tenuErrorStatus LCD_enuWriteData(uint8 u8LcdIndxCpy , uint8 u8LcdDataCpy)
{
tenuErrorStatus enuReturStateLoc = E_OK ;
 if(u8LcdIndxCpy < LCD_MAX_NUM)
 {
	//write DIO rs
	DIO_enuWritePin(LCD_astrConfig[u8LcdIndxCpy].strLcdPinOutCfg.au8ControlPins[0] , 1) ;
   // help cmd	
   LCD_voidHelp(u8LcdIndxCpy, u8LcdDataCpy);
   
   
 }
 else
 {
	 enuReturStateLoc = E_NOK_PARAM_OUT_OF_RANGE ;
 }
	return enuReturStateLoc ;
	
}

static void LCD_voidHelp(uint8 u8LcdIndxCpy, uint8 u8LcdCmdDataCpy)
{
	uint8 u8CntrLoc ;
	/* rw low*/
	DIO_enuWritePin(LCD_astrConfig[u8LcdIndxCpy].strLcdPinOutCfg.au8ControlPins[1] , 0) ;
    /* EN latch high */
	DIO_enuWritePin(LCD_astrConfig[u8LcdIndxCpy].strLcdPinOutCfg.au8ControlPins[2] , 1) ;
    if (LCD_astrConfig[u8LcdIndxCpy].strLcdPinOutCfg.u8LcdMode== LCD_8BIT_MODE)
	{
		for(u8CntrLoc = 0 ; u8CntrLoc < 8 ; u8CntrLoc++)
		{
			DIO_enuWritePin(LCD_astrConfig[u8LcdIndxCpy].strLcdPinOutCfg.au8DataPins[u8CntrLoc],GET_BIT(u8LcdCmdDataCpy,u8CntrLoc));
		}
	
	}
	else
	{
		for(u8CntrLoc = 4 ; u8CntrLoc < 8; u8CntrLoc++)
		{
			DIO_enuWritePin(LCD_astrConfig[u8LcdIndxCpy].strLcdPinOutCfg.au8DataPins[u8CntrLoc],GET_BIT(u8LcdCmdDataCpy,u8CntrLoc));
			u8LcdCmdDataCpy = u8LcdCmdDataCpy<<4 ;
			DIO_enuWritePin(LCD_astrConfig[u8LcdIndxCpy].strLcdPinOutCfg.au8DataPins[u8CntrLoc],GET_BIT(u8LcdCmdDataCpy,u8CntrLoc));
			
		}
	

		
	}
	
	/* EN latch low */
	DIO_enuWritePin(LCD_astrConfig[u8LcdIndxCpy].strLcdPinOutCfg.au8ControlPins[2] , 0) ;
    _delay_ms(2);
}
  
   
   
   
   
   
   
   
   
   
   
   
