/*
 * exi.c
 *
 * Created: 2023-05-17 1:36:31 PM
 *  Author: khale
 */ 
#include "../../utilities/std_types.h"
#include "../../utilities/registers.h"
#include "../../utilities/common_macros.h"
#include "../../utilities/interrupts.h"
#include "exi.h"

#define GLOBAL_INTERRUPT_ENABLE sei()
#define GLOBAL_INTERRUPT_DISABLE cli()



static void (*EXI_INT0_FuncPtr) (void) = NULL;
static void (*EXI_INT1_FuncPtr) (void) = NULL;
static void (*EXI_INT2_FuncPtr) (void) = NULL;

void EXI_enable(en_EXI_ExternalInterruptSrc interruptSource) {
	GLOBAL_INTERRUPT_ENABLE;
	switch (interruptSource) {
		case EXI_INT0:
		SET_BIT(GICR, INT0);
		break;
		case EXI_INT1:
		SET_BIT(GICR, INT1);
		break;
		case EXI_INT2:
		SET_BIT(GICR, INT2);
		break;
		default:
		break;
	}
}

void EXI_disable(en_EXI_ExternalInterruptSrc interruptSource) {
	GLOBAL_INTERRUPT_DISABLE;
	switch (interruptSource) {
		case EXI_INT0:
		CLEAR_BIT(GICR, INT0);
		break;
		case EXI_INT1:
		CLEAR_BIT(GICR, INT1);
		break;
		case EXI_INT2:
		CLEAR_BIT(GICR, INT2);
		break;
		default:
		break;
	}
}

void EXI_triggerEdge(en_EXI_ExternalInterruptSrc interruptSource, en_EXI_SenseControl triggerType) {
	switch (interruptSource) {
		case EXI_INT0:
		switch (triggerType) {
			case LOW_LVL:
			CLEAR_BIT(MCUCR, ISC00);
			CLEAR_BIT(MCUCR, ISC01);
			break;
			case ANY_CHANGE:
			SET_BIT(MCUCR, ISC00);
			CLEAR_BIT(MCUCR, ISC01);
			break;
			case FALLING_EDGE:
			CLEAR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
			default:
			break;
		}
		break;
		case EXI_INT1:
		switch (triggerType) {
			case LOW_LVL:
			CLEAR_BIT(MCUCR, ISC10);
			CLEAR_BIT(MCUCR, ISC11);
			break;
			case ANY_CHANGE:
			SET_BIT(MCUCR, ISC10);
			CLEAR_BIT(MCUCR, ISC11);
			break;
			case FALLING_EDGE:
			CLEAR_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
			default:
			break;
		}
		break;
		case EXI_INT2:
		switch (triggerType) {
			case FALLING_EDGE:
			CLEAR_BIT(MCUCSR, ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCSR, ISC2);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

void EXI_setCallBack(en_EXI_ExternalInterruptSrc interruptSource, void(*EXI_localFuncPtr)(void)) {
	switch (interruptSource) {
		case EXI_INT0:
			EXI_INT0_FuncPtr = EXI_localFuncPtr;
			break;
		case EXI_INT1:
			EXI_INT1_FuncPtr = EXI_localFuncPtr;
			break;
		case EXI_INT2:
			EXI_INT2_FuncPtr = EXI_localFuncPtr;
			break;
		default:
			break;
	}
}

ISR(EXT_INT0_vect) {
	if (EXI_INT0_FuncPtr != NULL) {
		EXI_INT0_FuncPtr();
	}
}

ISR(EXT_INT1_vect) {
	if (EXI_INT1_FuncPtr != NULL) {
		EXI_INT1_FuncPtr();
	}
}

ISR(EXT_INT2_vect) {
	if (EXI_INT2_FuncPtr != NULL) {
		EXI_INT2_FuncPtr();
	}
}