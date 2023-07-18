
#ifndef MOVING_CAR_SYSTEM_REGISTERS_H
#define MOVING_CAR_SYSTEM_REGISTERS_H

#include "std_types.h"

/**
 * @defgroup AVR-Port-Reg Port ID registers
 * IDs of AVR port registers.
 * @{
 */
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
#define MAX_PORT_ID 4
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
#define MAX_PIN_ID 8
/**@}*/

/**
* @brief Contains information about the result of the most recently executed arithmetic instruction.
* Bit 7 I: Global Interrupt Enable
* Bit 6 T: Bit Copy Storage
* Bit 5 H: Half Carry Flag
* Bit 4 S: Sign Bit
* Bit 3 V: Overflow Flag
* Bit 2 N: Negative Flag
* Bit 1 Z: Zero Flag
* Bit 0 C: Carry Flag
*/
#define SREG *((uint8 *)0x5F)

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

/**
* @brief MCUSR - MCU Control Register
* Controls the triggering mechanism of INT1 and INT0.
* Interrupt 1 sense control
* | ISC11 Bit 3 | ISC10 Bit 2 | Description                       |
* |-------------|-------------|-----------------------------------|
* | 0           | 0           | INT1 triggered on low level.      |
* | 0           | 1           | Any logic change triggers.        |
* | 1           | 0           | Falling edge generates interrupt. |
* | 1           | 1           | Rising edge generates interrupt.  |
* Interrupt 0 sense control.
* | ISC01 Bit 3 | ISC00 Bit 2 | Description                       |
* |-------------|-------------|-----------------------------------|
* | 0           | 0           | INT0 triggered on low level.      |
* | 0           | 1           | Any logic change triggers.        |
* | 1           | 0           | Falling edge generates interrupt. |
* | 1           | 1           | Rising edge generates interrupt.  |
*/
#define MCUCR *((volatile uint8 *)0x55)

/**
* @brief MCUCSR MCU Control and Status Register
* Controls the triggering mechanism of INT2.
* This is done through ISC2 Bit 6.
* 0 - Falling edge activates the interrupt.
* 1 - Rising edge activates the interrupt.
*/
#define MCUCSR *((volatile uint8 *)0x54)

/**
* @brief GICR - General Interrupt Control Register
* Bit 7 - INT1: External Interrupt Request 1 enable.
* Bit 6 - INT0: External Interrupt Request 0 enable.
* Bit 5 - INT2: External Interrupt Request 2 enable.
*/
#define GICR *((volatile uint8 *)0x5B)

/**
* @brief GIFR - General Interrupt Flag Register
* Bit 7 - INTF1: External Interrupt Flag 1.
* Bit 6 - INTF0: External Interrupt Flag 0.
* Bit 5 - INTF2: External Interrupt Flag 2.
*/
#define GIFR *((uint8 *)0x5A)


typedef enum {
    CS00 = 0, CS01, CS02, WGM01, COM00, COM01, WGM00, FOC0
}TCCR0_BITS;

typedef  enum {
    TOV0 = 0, OCF0
}TIFR_BITS;

typedef enum {
    TOIE0 = 0, OCIE0
}TIMSK_BITS;

/**
 * @defgroup SPI-Registers SPI registers.
 * @{
 */
#define SPCR *((volatile uint8 *)0x2D) ///< SPI control register.
#define SPSR *((volatile uint8 *)0x2E) ///< SPI status register.
#define SPDR *((volatile uint8 *)0x2F) ///< SPI data register.
/**@}*/

/**
 * @defgroup SPCR SPI control register bits.
 * @{
 */
#define SPR0 0 ///< SPI clock rate select.
#define SPR1 1 ///< SPI clock rate select.
#define CPHA 2 ///< SPI clock phase.
#define CPOL 3 ///< SPI clock polarity.
#define MSTR 4 ///< Master/Slave select.
#define DORD 5 ///< Data order.
#define SPE 6 ///< SPI enable.
#define SPIE 7 ///< SPI interrupt enable.
/**@}*/

/**
 * @defgroup SPSR SPI status register
 * @{
 */
#define SPI2X 0 ///< Double SPI speed.
#define WCOL 6 ///< Write collision flag.
#define SPIF 7 ///< SPI interrupt flag.
/**@}*/

#define UDR *((volatile uint8 *)0x2C) ///<
#define UCSRA *((volatile uint8 *)0x2B) ///<
#define UCSRB *((volatile uint8 *)0x2A) ///<
#define UCSRC *((volatile uint8 *)0x40) ///<
#define UBRRH *((volatile uint8 *)0x40) ///<
#define UBRRL *((volatile uint8 *)0x29) ///<

/**
 * @defgroup UCSRA USART contorl and status register A
 * @{
 */
#define MPCM 0 ///< (R/W) Multi-processor communication mode. (All incoming frames received by the RX that don't contain address information will be ignored).
#define U2X 1 ///< (R/W) Double transmission speed.
#define PE 2 ///< (R) Parity error.
#define DOR 3 ///< (R) Data over run error.
#define FE 4 ///< (R) Frame error.
#define UDRE 5 ///< (R) USART data registry error.
#define TXC 6 ///< (R) USART transmit complete flag.
#define RXC 7 ///< (R) USART receive complete flag.
/**@}*/

/**
 * @defgroup UCSRB USART control and status register B
 * @{
 */
#define TXB8 0 ///< (R/W) The ninth bit to be transmitted.
#define RXB8 1 ///< (R) The ninth bit to be received.
#define UCSZ2 2 ///< (R/W) Character size.
#define TXEN 3 ///< (R/W) Transmitter enable.
#define RXEN 4 ///< (R/W) Receiver enable.
#define UDRIE 5 ///< (R/W) Empty interrupt enable.
#define TXCIE 6 ///< (R/W) TX complete interrupt enable.
#define RXCIE 7 ///< (R/W) RX complete interrupt enable.
/**@}*/

/**
 * @defgroup UCSRC USART control and status register C
 * @{
 */
#define UCPOL 0 ///< (R/W) Clock polarity.
#define UCSZ0 1 ///< (R/W) Character size.
#define UCSZ1 2 ///< (R/W) Character size.
#define USBS 3 ///< (R/W) Stop bit size.
#define UPM0 4 ///< (R/W) Parity mode.
#define UPM1 5 ///< (R/W) Parity mode.
#define UMSEL 6 ///< (R/W) USART mode select.
#define URSEL 7 ///< (R/W) USART register select.
/**@}*/

/**
 * @defgroup GICR General interrupt control registers
 * @{
 */
#define INT2 5 ///< (R/W) External interrupt 2.
#define INT0 6 ///< (R/W) External interrupt 0.
#define INT1 7 ///< (R/W) External interrupt 1.
/**@}*/

#define ISC00 0 ///< (R/W) Interrupt sense control bit 0.
#define ISC01 1 ///< (R/W) Interrupt sense control bit 1.
#define ISC10 2 ///< (R/W) Interrupt sense control bit 2.
#define ISC11 3 ///< (R/W) Interrupt sense control bit 3.

#define ISC2 6 ///< (R/W) Interrupt sense control 2.

#endif //MOVING_CAR_SYSTEM_REGISTERS_H
