#ifndef TIMER_H
#define	TIMER_H

#include "../../utilities/std_types.h"

void (*fptr_TIMER0_CallBackFunction)(void); 

typedef enum {
    TIMER_NORMAL_MODE = 0,
    TIMER_CTC_MODE = 1,
    TIMER_FAST_PWM_MODE = 2,
    TIMER_PHASE_CORRECT_PWM_MODE = 3
}en_TIMER_OperationMode_t;

typedef enum {
    COMPARE_OUTPUT_MODE_OP_NORMAL = 0,
    COMPARE_OUTPUT_MODE_OP_TOGGLE = 1,
    COMPARE_OUTPUT_MODE_OP_CLEAR = 2,
    COMPARE_OUTPUT_MODE_OP_SET = 3
}en_TIMER_OutputCompareModeOp_t;

typedef enum {
    NO_CLK, CLK, CLK_8, CLK_64, CLK_256, CLK_1024
}en_TIMER_ClockSelect_t;

typedef enum {
    INTERRUPT_DISABLE = 0, INTERRUPT_ENABLE = 1
}en_TIMER_InterruptState_t;

typedef enum {
    FLAG_CLEAR = 0, FLAG_SET = 1
}en_TIMER_FlagStatus;

typedef enum {
    OC_Int = 0, OV_Int = 1
}en_TIMER_InterruptSelect_t;

typedef struct {
    en_TIMER_OperationMode_t en_TIMER_OperationMode;
    en_TIMER_ClockSelect_t en_TIMER_ClockSelect;
    en_TIMER_OutputCompareModeOp_t en_TIMER_OutputCompareModeOp;
    en_TIMER_InterruptState_t en_TIMER_InterruptState;
    en_TIMER_InterruptSelect_t en_TIMER_InterruptSelect;
    uint8 period;
    uint8 compare_value;
}st_TIMER_config_t;

typedef enum {
    TIMER_STATUS_SUCCESS = 700,
    TIMER_STATUS_OPMode_FAILED = 701,
    TIMER_STATUS_OCPinOPs_FAILED = 702,
    TIMER_STATUS_CLK_FAILED = 703,
}st_TIMERAPIStatus;

/**
 * @brief Initializes Timer 0 with the user configuration parameters.
 * @param[in] ptr_st_TIMER_config: Address of the user configuration structure.
 */
void TIMER_Init(st_TIMER_config_t *ptr_st_TIMER_config);

/**
 * @brief Stops the timer.
 */
void TIMER_DeInit();

/**
 * @brief Checks that status of the output compare flag.
 * @return FLAG_SET
 * @return FLAG_CLEAR
 */
en_TIMER_FlagStatus TIMER_GetOCFlagStatus(void);

/**
 * @brief Checks that status of the over flow flag.
 * @return FLAG_SET
 * @return FLAG_CLEAR
 */
en_TIMER_FlagStatus TIMER_GETOVFlagStatus(void);

/**
 * @brief Sets the address of the callback function of Timer 0.
 */
void TIMER_SetCallbackFunc(void(fptr_func)(void));

/* TODO I think I might make those two function as static function. */
void TIMER_LoadCompReg(uint8 compare_value);
void TIMER_LoadCountReg(uint8 period);
#endif	/* TIMER_H */