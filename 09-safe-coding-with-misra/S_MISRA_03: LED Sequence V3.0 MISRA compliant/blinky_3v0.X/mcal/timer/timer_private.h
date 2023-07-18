/* 
 * File:   timer_private.h
 * Author:  KHALED MUSTAFA
 *
 * Created on June 8, 2023, 9:16 AM
 */

#ifndef TIMER_PRIVATE_H
#define	TIMER_PRIVATE_H


#define TCCR0 *((volatile uint8 *)0x53) ///< Timer/Counter Control Register
#define TCNT0 *((volatile uint8 *)0x52) ///< Timer/Counter Register
#define TIMSK *((volatile uint8 *)0x59) ///< Timer/Counter Interrupt Mask Register
#define OCR0 *((volatile uint8 *)0x5C) ///< Output Compare Register
#define TIFR *((volatile uint8 *)0x58) ///< Timer/Counter Interrutp Flag Register

#define CS00    0 ///< Clock select.
#define CS01    1 ///< Clock select.
#define CS02    2 ///< Clock select.
#define WGM01   3 ///< Waveform generation mode.
#define COM00   4 ///< Compare match output mode.
#define COM01   5 ///< Compare match output mode.
#define WGM00   6 ///< Waveform generation mode.
#define FOC0    7 ///< Force output compare.



#define TOIE0   0 ///< Timer/Counter0 overflow interrupt enable.
#define OCIE0   1 ///< Timer/Counter0 output compare match interrupt enable.
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7


#define TOV0    0 ///< Timer/Counter0 overflow flag.
#define OCF0    1 ///< Output compare flag 0.
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5
#define TOV2    6
#define OCF2    7

#endif	/* TIMER_PRIVATE_H */
