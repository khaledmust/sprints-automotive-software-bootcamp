#include "timer.h"
#include "timer_private.h"
#include "../../utilities/interrupts.h"
#include "../../utilities/common_macros.h"

st_TIMERAPIStatus g_TIMER_API_STATUS;
en_TIMER_FlagStatus g_flagStatus;

/**
 * @brief Sets operation mode of the Timer 0.
 * This is done by configuring the WGM00 and WGM01 bits in the TCCR0 register.
 * @param[in] en_TIMER_OperationMode Operation mode of the timer @ref en_TIMER_OperationMode_t.
 * @return TIMER_STATUS_OPMode_FAILED
 * @return TIMER_STATUS_SUCCESS
 */
static st_TIMERAPIStatus TIMER_SetOpMode(en_TIMER_OperationMode_t en_TIMER_OperationMode) {
    switch (en_TIMER_OperationMode) {
        case TIMER_NORMAL_MODE:
            CLEAR_BIT(TCCR0, WGM00);
            CLEAR_BIT(TCCR0, WGM01);
            break;
        case TIMER_CTC_MODE:
            CLEAR_BIT(TCCR0, WGM00);
            SET_BIT(TCCR0, WGM01);
            break;
        case TIMER_FAST_PWM_MODE:
            SET_BIT(TCCR0, WGM00);
            SET_BIT(TCCR0, WGM01);
            break;
        case TIMER_PHASE_CORRECT_PWM_MODE:
            SET_BIT(TCCR0, WGM00);
            CLEAR_BIT(TCCR0, WGM01);
            break;
        default:
            g_TIMER_API_STATUS = TIMER_STATUS_OPMode_FAILED;
    }
    g_TIMER_API_STATUS = TIMER_STATUS_SUCCESS;
    return g_TIMER_API_STATUS;
}

/**
 * @brief Sets operation mode of the OC pin.
 * This is done by configuring the COM00 and COM01 bits in the TCCR0 register.
 * @param[in] en_TIMER_OperationMode Operation mode of the timer @ref en_TIMER_OperationMode_t.
 * @param[in] en_TIMER_OutputCompareModeOp OC pin operation @ref en_TIMER_OutputCompareModeOp_t.
 * @return TIMER_STATUS_OCPinOPs_FAILED
 * @return TIMER_STATUS_OPMode_FAILED
 * @return TIMER_STATUS_SUCCESS
 */
static st_TIMERAPIStatus TIMER_OCPinOps(en_TIMER_OperationMode_t en_TIMER_OperationMode,
        en_TIMER_OutputCompareModeOp_t en_TIMER_OutputCompareModeOp) {
    switch (en_TIMER_OperationMode) {
        case TIMER_CTC_MODE:
            switch (en_TIMER_OutputCompareModeOp) {
                case COMPARE_OUTPUT_MODE_OP_NORMAL:
                    CLEAR_BIT(TCCR0, COM00);
                    CLEAR_BIT(TCCR0, COM01);
                    break;
                case COMPARE_OUTPUT_MODE_OP_TOGGLE:
                    SET_BIT(TCCR0, COM00);
                    CLEAR_BIT(TCCR0, COM01);
                    break;
                case COMPARE_OUTPUT_MODE_OP_CLEAR:
                    CLEAR_BIT(TCCR0, COM00);
                    SET_BIT(TCCR0, COM01);
                    break;
                case COMPARE_OUTPUT_MODE_OP_SET:
                    SET_BIT(TCCR0, COM00);
                    SET_BIT(TCCR0, COM01);
                    break;
                default:
                    g_TIMER_API_STATUS = TIMER_STATUS_OCPinOPs_FAILED;
                    break;
            }
            break;
        case TIMER_FAST_PWM_MODE:
            switch (en_TIMER_OutputCompareModeOp) {
                case COMPARE_OUTPUT_MODE_OP_NORMAL:
                    CLEAR_BIT(TCCR0, COM00);
                    CLEAR_BIT(TCCR0, COM01);
                    break;
                case COMPARE_OUTPUT_MODE_OP_CLEAR:
                    CLEAR_BIT(TCCR0, COM00);
                    SET_BIT(TCCR0, COM01);
                    break;
                case COMPARE_OUTPUT_MODE_OP_SET:
                    SET_BIT(TCCR0, COM00);
                    SET_BIT(TCCR0, COM01);
                    break;
                default:
                    g_TIMER_API_STATUS = TIMER_STATUS_OCPinOPs_FAILED;
                    break;
            }
            break;
        case TIMER_PHASE_CORRECT_PWM_MODE:
            switch (en_TIMER_OutputCompareModeOp) {
                case COMPARE_OUTPUT_MODE_OP_NORMAL:
                    CLEAR_BIT(TCCR0, COM00);
                    CLEAR_BIT(TCCR0, COM01);
                    break;
                case COMPARE_OUTPUT_MODE_OP_CLEAR:
                    CLEAR_BIT(TCCR0, COM00);
                    SET_BIT(TCCR0, COM01);
                    break;
                case COMPARE_OUTPUT_MODE_OP_SET:
                    SET_BIT(TCCR0, COM00);
                    SET_BIT(TCCR0, COM01);
                    break;
                default:
                    g_TIMER_API_STATUS = TIMER_STATUS_OCPinOPs_FAILED;
                    break;
            }
            break;
        default:
            g_TIMER_API_STATUS = TIMER_STATUS_OPMode_FAILED;
            break;
    }
    g_TIMER_API_STATUS = TIMER_STATUS_SUCCESS;
    return g_TIMER_API_STATUS;
}

/**
 * @brief Sets clock source and prescaler value of the internal clock source.
 * @param[in] en_TIMER_ClockSelect Clock source and prescaler value of the inernal
 * clock source @ref en_TIMER_ClockSelect_t
 * @return TIMER_STATUS_CLK_FAILED
 * @return TIMER_STATUS_SUCCESS
 */
static st_TIMERAPIStatus TIMER_SetClkPresclr(en_TIMER_ClockSelect_t en_TIMER_ClockSelect) {
    switch (en_TIMER_ClockSelect) {
        case NO_CLK:
            CLEAR_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case CLK:
            SET_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case CLK_8:
            CLEAR_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case CLK_64:
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case CLK_256:
            CLEAR_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);
            break;
        case CLK_1024:
            SET_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);
            break;
        default:
            g_TIMER_API_STATUS = TIMER_STATUS_CLK_FAILED;
    }
    g_TIMER_API_STATUS = TIMER_STATUS_SUCCESS;
    return g_TIMER_API_STATUS;
}

/**
 * @brief Loads the timer register with the specified value.
 * @param[in] period The number of ticks required to start the timer from.
 */
void TIMER_LoadCountReg(uint8 period) {
    TCNT0 = period;
}

/**
 * @brief Loads the timer compare register with the specified value.
 * @param[in] compare_value The number of ticks required to compare it with
 * the timer register (TCNT0).
 */
void TIMER_LoadCompReg(uint8 compare_value) {
    OCR0 = compare_value;
}

/**
 * @brief Enables/disables the output compare interrupt, it also enables global interrupt.
 * @param[in] en_TIMER_InterruptState The state of output compare interrupt. 
 */
static void TIMER_OCIntCtrl(en_TIMER_InterruptState_t en_TIMER_InterruptState) {
    if (en_TIMER_InterruptState == INTERRUPT_ENABLE) {
        SET_BIT(TIMSK, OCIE0);
        sei();
    } else if (en_TIMER_InterruptState == INTERRUPT_DISABLE) {
        CLEAR_BIT(TIMSK, OCIE0);
        cli();
    }
}

/**
 * @brief Enables/disables the overflow interrupt, it also enables global interrupt.
 * @param[in] en_TIMER_InterruptState The state of output compare interrupt. 
 */
static void TIMER_OVIntCtrl(en_TIMER_InterruptState_t en_TIMER_InterruptState) {
    if (en_TIMER_InterruptState == INTERRUPT_ENABLE) {
        SET_BIT(TIMSK, TOIE0);
        sei();
    } else if (en_TIMER_InterruptState == INTERRUPT_DISABLE) {
        CLEAR_BIT(TIMSK, TOIE0);
        cli();
    }
}
/**
 * @brief Checks that status of the output compare flag.
 * @return FLAG_SET
 * @return FLAG_CLEAR
 */
en_TIMER_FlagStatus TIMER_GetOCFlagStatus(void) {
//    volatile uint8 OCFlagStatus = (BIT_IS_SET(TIFR, OCF0));
    if (BIT_IS_SET(TIFR, OCF0)) {
        SET_BIT(TIFR, OCF0);
        return FLAG_SET;
    }
    return FLAG_CLEAR;
}

/**
 * @brief Checks that status of the over flow flag.
 * @return FLAG_SET
 * @return FLAG_CLEAR
 */
en_TIMER_FlagStatus TIMER_GETOVFlagStatus(void) {
    boolean OVFlagStatus = BIT_IS_SET(TIFR, TOV0);
    if (OVFlagStatus == TRUE) {
        SET_BIT(TIFR, TOV0);
        return FLAG_SET;
    }
    return FLAG_CLEAR;
}

/**
 * @brief Initializes Timer 0 with the user configuration parameters.
 * This is done by calling the static helper function defined in this driver.
 * @param[in] ptr_st_TIMER_config: Address of the user configuration structure.
 */
st_TIMERAPIStatus TIMER_Init(st_TIMER_config_t *ptr_st_TIMER_config) {
    boolean TimerInitStatus = 0;
    
    TimerInitStatus = TIMER_SetOpMode(ptr_st_TIMER_config->en_TIMER_OperationMode);
    if (TimerInitStatus == FALSE) {
        g_TIMER_API_STATUS = TIMER_STATUS_INIT_FAILED;
    }
    
    TimerInitStatus = TIMER_OCPinOps(ptr_st_TIMER_config->en_TIMER_OperationMode, ptr_st_TIMER_config->en_TIMER_OutputCompareModeOp);
    if (TimerInitStatus == FALSE) {
        g_TIMER_API_STATUS = TIMER_STATUS_INIT_FAILED;
    }
    
    if (ptr_st_TIMER_config->en_TIMER_InterruptSelect == OV_Int) {
        TIMER_OVIntCtrl(ptr_st_TIMER_config->en_TIMER_InterruptState);
    } else if (ptr_st_TIMER_config->en_TIMER_InterruptSelect == OC_Int) {
        TIMER_OCIntCtrl(ptr_st_TIMER_config->en_TIMER_InterruptState);
    }
    
    TIMER_LoadCountReg(ptr_st_TIMER_config->period);
    TIMER_LoadCompReg(ptr_st_TIMER_config->compare_value);
    
    TimerInitStatus = TIMER_SetClkPresclr(ptr_st_TIMER_config->en_TIMER_ClockSelect);
    if (TimerInitStatus == FALSE) {
        g_TIMER_API_STATUS = TIMER_STATUS_INIT_FAILED;
    }
    return g_TIMER_API_STATUS;
}

/**
 * @brief Stops the timer.
 * This is done by selecting the "NO_CLK" as the clock source of the timer.
 */
void TIMER_DeInit(void) {
    /* Disenagage the clock from the timer to disable it. */
    TIMER_SetClkPresclr(NO_CLK);
}

/**
 * @brief Sets the address of the callback function of Timer 0.
 */
void TIMER_SetCallbackFunc(void(*fptr_func)(void)) {
    fptr_TIMER0_CallBackFunction = fptr_func;
}

ISR(TIM0_COMP_vect) {
    if (fptr_TIMER0_CallBackFunction != NULL) {
        fptr_TIMER0_CallBackFunction();
    }
}