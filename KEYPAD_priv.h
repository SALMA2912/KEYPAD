

#ifndef KEYPAD_PRIV_H
#define KEYPAD_PRIV_H

typedef struct
{
	uint8 au8SwitchMapping[KEYPAD_MAX_INPUT_PIN_NUMS][KEYPAD_MAX_OUTPUT_PIN_NUMS];//dool macros fa 2abl ma ycompile hay7ot elrakam 2d array
	//m3arafa max numbr of inputs w outputs 3ashan y7gz elarray 3ala akbar rakam 3ashan lazm yb2a 3andaha 3adad elindices
	uint8 au8InputPinsCon [KEYPAD_MAX_INPUT_PIN_NUMS]; //input pin connections hana5od max 3adad elinputs ya3ny law 4*4 aw 6*3 ha5od el 6 w 4
	uint8 au8OutputPinsCon[KEYPAD_MAX_OUTPUT_PIN_NUMS];
	uint8 au8MaskValue[KEYPAD_MAX_INPUT_PIN_NUMS]; //elsequences ely hatrga3ly lma ha read
	uint8 u8InputPinNum;
	uint8 u8OutputPinNum;
	
}tstrKeypadInfo;

extern tstrKeypadInfo  KEYPAD_astrConfigSet[KEYPAD_MAX_NUM]; //3ashn nest5demha fy el .c

static uint8 KEYPAD_u8Check(uint8 u8KeypadNumCpy , uint8 u8SeqIndxCpy ,uint8 u8ReadValueCpy );
static void KEYPAD_voidReadInputs(uint8 u8KeypadNumCpy , uint8 *pu8ReadValueCpy);
static void KEYPAD_voidWriteSeq(uint8 u8KeypadNumCpy , uint8 u8SeqIndxCpy);



#endif 