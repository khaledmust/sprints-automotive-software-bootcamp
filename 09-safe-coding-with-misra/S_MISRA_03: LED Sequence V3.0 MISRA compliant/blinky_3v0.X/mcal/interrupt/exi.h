/*
 * exi.h
 *
 * Created: 2023-05-17 1:37:02 PM
 *  Author: khale
 */ 


#ifndef EXI_H_
#define EXI_H_


typedef enum {
	EXI_INT0 = 0, EXI_INT1, EXI_INT2
}en_EXI_ExternalInterruptSrc;

typedef enum {
	LOW_LVL = 0, ANY_CHANGE, FALLING_EDGE, RISING_EDGE
}en_EXI_SenseControl;

void EXI_enable(en_EXI_ExternalInterruptSrc interruptSource);
void EXI_disable(en_EXI_ExternalInterruptSrc interruptSource);
void EXI_triggerEdge(en_EXI_ExternalInterruptSrc interruptSource, en_EXI_SenseControl triggerType);
void EXI_setCallBack(en_EXI_ExternalInterruptSrc interruptSource, void(*EXI_localFuncPtr)(void));

#endif /* EXI_H_ */