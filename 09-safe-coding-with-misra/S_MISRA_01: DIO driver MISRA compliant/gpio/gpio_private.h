/* 
 * File:   gpio_private.h
 * Author: khaled
 *
 * Created on June 5, 2023, 10:48 PM
 */

#ifndef GPIO_PRIVATE_H
#define	GPIO_PRIVATE_H

#define MAX_PORT_ID 3
#define MIN_PORT_ID 0

#define MAX_PIN_ID 7
#define MIN_PIN_ID 0

/**
 * @defgroup AVR-Port-Reg Port ID registers
 * IDs of AVR port registers.
 * @{
 */
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
/**@}*/

/**
 * @defgroup AVR-Pins-Reg Pin ID registers
 * IDs of AVR pin registers.
 * @{
 */
#define PINA_ID 0
#define PINB_ID 1
#define PINC_ID 2
#define PIND_ID 3
/**@}*/

/**
 * @defgroup AVR-Pins Pin numbers.
 * NUmber of pins in every register of the AVR.
 * @{
 */
#define PIN0_ID 0
#define PIN1_ID 1
#define PIN2_ID 2
#define PIN3_ID 3
#define PIN4_ID 4
#define PIN5_ID 5
#define PIN6_ID 6
#define PIN7_ID 7
/**@}*/

/**
 * @defgroup AVR-Ports Port addresses
 * De-referenced addresses of ports.
 * @{
 */
#define PORTA *((volatile uint8 *)0x3B)
#define PORTB *((volatile uint8 *)0x38)
#define PORTC *((volatile uint8 *)0x35)
#define PORTD *((volatile uint8 *)0x32)
/**@}*/

/**
 * @defgroup AVR-Pins Pin addresses
 * De-referenced addresses of pins.
 * @{
 */
#define PINA *((volatile uint8 *)0x39)
#define PINB *((volatile uint8 *)0x36)
#define PINC *((volatile uint8 *)0x33)
#define PIND *((volatile uint8 *)0x30)
/**@}*/

/**
 * @defgroup AVR-DDR DDR addresses
 * De-referenced addresses of DDR.
 * @{
 */
#define DDRA *((volatile uint8 *)0x3A)
#define DDRB *((volatile uint8 *)0x37)
#define DDRC *((volatile uint8 *)0x34)
#define DDRD *((volatile uint8 *)0x31)
/**@}*/

#endif	/* GPIO_PRIVATE_H */

