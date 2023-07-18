/*
 * interrupts.h
 *
 * Created: 2023-05-27 5:44:07 AM
 *  Author: KHALED MUSTAFA
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/**
* @brief Enables global interrupts, by setting I-bit in status register.
*/
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/**
* @brief Disables global interrupts, by clearing I-bit in status register.
*/
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

/**
 * @defgroup vectorTable Vector table
 * @{
 */
#define EXT_INT0_vect __vector_1 //<External Interrupt Request 0.
#define EXT_INT1_vect __vector_2 //<External Interrupt Request 1.
#define EXT_INT2_vect __vector_3 //<External Interrupt Request 2.

#define TIM2_COMP_vect  __vector_4 ///<Timer/Counter 2 Compare Match
#define TIM2_OVF_vect   __vector_5 ///<Timer/Counter 2 Overflow
#define TIM1_CAPT_vect  __vector_6 ///<Timer/Counter 1 Capture Event
#define TIM1_COMPA_vect __vector_7 ///<Timer/Counter 1 Compare Match A
#define TIM1_COMPB_vect __vector_8 ///<Timer/Counter 1 Compare Match B
#define TIM1_OVF_vect   __vector_9 ///<Timer/Counter 1 Overflow
#define TIM0_COMP_vect  __vector_10 ///<Timer/Counter 0 Compare Match
#define TIM0_OVF_vect   __vector_11 ///<Timer/Counter 0 Overflow

#define SPI_STC_vect    __vector_12	///<Serial Transfer Complete Interrupt
#define USART_RXC_vect  __vector_13 ///<USART RX Complete Interrupt
#define USART_UDRE_vect __vector_14 ///<USART Data Register Empty Interrupt
#define USART_TXC_vect  __vector_15 ///<USART TX Complete Interrupt
#define ADC_vect        __vector_16 ///<ADC Conversion Complete Interrupt
#define EE_RDY_vect     __vector_17 ///<EEPROM Ready Interrupt
#define ANA_COMP_vect   __vector_18 ///<Analog Comparator Interrupt
#define TWI_vect        __vector_19	///<Two-Wire Serial Interface Interrupt
#define SPM_RDY_vect    __vector_20	///<Store Program Memory Ready Interrupt
/**@}*/


#endif /* INTERRUPTS_H_ */