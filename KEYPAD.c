#include "STD_Types.h"
#include <avr/delay.h>

#include "DIO_int.h"
#include "KEYPAD_int.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"


void KEYPAD_voidInit(void)
{
	uint8 u8KeypadCntrLoc ;
	uint8 u8InputCntrLoc ;
	uint8 u8OutputCntrLoc ;
	for(u8KeypadCntrLoc = 0 ; u8KeypadCntrLoc< KEYPAD_MAX_NUM ; u8KeypadCntrLoc++)
	{
		/*active Pullup Inputs elrows kolo bones*/
		
		for(u8InputCntrLoc = 0 ; u8InputCntrLoc< KEYPAD_astrConfigSet[u8KeypadCntrLoc].u8InputPinNum ;u8InputCntrLoc++)
		{
			
			DIO_enuActivatePullUp(KEYPAD_astrConfigSet[u8KeypadCntrLoc].au8InputPinsCon[u8InputCntrLoc],1);
			
		}
	
		/*Add No seq Output */
		for(u8OutputCntrLoc = 0; u8OutputCntrLoc< KEYPAD_astrConfigSet[u8KeypadCntrLoc].u8OutputPinNum ;u8OutputCntrLoc++ )
		{
			DIO_enuWritePin(KEYPAD_astrConfigSet[u8KeypadCntrLoc].au8OutputPinsCon[u8OutputCntrLoc],1);
		}
	}
}

uint8 KEYPAD_u8GetPressedKey(uint8 u8KeypadNumCpy)
{
	uint8 u8OutputCntrLoc ;
	uint8 u8ReadValueLoc ;
	uint8 u8ResultLoc = 0xFF ;
	for(u8OutputCntrLoc = 0; u8OutputCntrLoc< KEYPAD_astrConfigSet[u8KeypadNumCpy].u8OutputPinNum ;u8OutputCntrLoc++ )
	{
	    KEYPAD_voidWriteSeq(u8KeypadNumCpy,u8OutputCntrLoc);
		_delay_ms(50);
		KEYPAD_voidReadInputs(u8KeypadNumCpy,&u8ReadValueLoc); //howa hay7otaha fy pointer
        _delay_ms(50);
		u8ResultLoc = KEYPAD_u8Check(u8KeypadNumCpy ,u8OutputCntrLoc,u8ReadValueLoc );
		
		if(u8ResultLoc != 0xFF) //ya3ny elrows kolaha ones ya3ny wala wa7ed metdas 3aleh
		{
			break ;
		}
 
		else
		{
			
		}
		
	
	}
	return u8ResultLoc;

}

static void KEYPAD_voidWriteSeq(uint8 u8KeypadNumCpy , uint8 u8SeqIndxCpy)
{
	uint8 u8OutputNumLoc ;
	
	for(u8OutputNumLoc = 0 ;u8OutputNumLoc<KEYPAD_astrConfigSet[u8KeypadNumCpy].u8OutputPinNum;u8OutputNumLoc++)
	{ //howa haydeny elindexof elpin ely awz 3aleeha zero fa law gena 3andha n7itha blow
		if(u8SeqIndxCpy ==u8OutputNumLoc)
		{
			DIO_enuWritePin(KEYPAD_astrConfigSet[u8KeypadNumCpy].au8OutputPinsCon[u8OutputNumLoc],0);
		}
		else
		{
			DIO_enuWritePin(KEYPAD_astrConfigSet[u8KeypadNumCpy].au8OutputPinsCon[u8OutputNumLoc],1);	
		}
		
	}
	
}


static void KEYPAD_voidReadInputs(uint8 u8KeypadNumCpy , uint8 *pu8ReadValueCpy)
{
  uint8 u8InputCntrLoc ;
  uint8 u8TempLoc ;
  *pu8ReadValueCpy = 0;
  for (u8InputCntrLoc = 0 ;u8InputCntrLoc< KEYPAD_astrConfigSet[u8KeypadNumCpy].u8InputPinNum ; u8InputCntrLoc++)
  {
	  
	DIO_enuReadPin(KEYPAD_astrConfigSet[u8KeypadNumCpy].au8InputPinsCon[u8InputCntrLoc],&u8TempLoc);  
   *pu8ReadValueCpy |= u8TempLoc << u8InputCntrLoc;
  }
  
}


static uint8 KEYPAD_u8Check(uint8 u8KeypadNumCpy , uint8 u8SeqIndxCpy ,uint8 u8ReadValueCpy )
{
	uint8 u8MaskCntrLoc;
	uint8 u8ReturnValueLoc = 0xFF ;
	for(u8MaskCntrLoc = 0 ;u8MaskCntrLoc<KEYPAD_astrConfigSet[u8KeypadNumCpy].u8InputPinNum;u8MaskCntrLoc++)
	{
		if (u8ReadValueCpy == KEYPAD_astrConfigSet[u8KeypadNumCpy].au8MaskValue[u8MaskCntrLoc]) //3ashn y3ady 3ala kol values elarray yshoof hya anhy
		{
			u8ReturnValueLoc = KEYPAD_astrConfigSet[u8KeypadNumCpy].au8SwitchMapping[u8MaskCntrLoc][u8SeqIndxCpy];
		
			break ;
		}
		else
		{
			
		}
	}
	return u8ReturnValueLoc ;
	
}



