#include "gpio.h"
#include "../../utilities/common_macros.h"
#include "../../utilities/registers.h"

/**
 * @brief Sets the direction of the specified pin.
 * @param[in] port_id Specifies the GPIO port to be configured.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the GPIO pin to be configured.
 * This parameter can be one of PINx_ID.
 * @param[in] direction Specifies the operating direction for the selected pin.
 * This parameter can be on of the en_GPIO_PinDirection enum values:
 * - GPIO_PIN_INPUT
 * - GPIO_PIN_OUTPUT
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_setPinDirection(uint8 port_id, uint8 pin_id, en_GPIO_PinDirection direction) {
    /* Check the validity of input port id and pin id. */
    if ((port_id < 0) || (port_id > MAX_PORT_ID) || (pin_id < 0) || (pin_id > MAX_PIN_ID)) {
        g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
    } else {
        switch (port_id) {
            case PORTA_ID:
                if (direction == GPIO_PIN_OUTPUT) {
                    SET_BIT(DDRA, pin_id);
                } else if (direction == GPIO_PIN_INPUT) {
                    CLEAR_BIT(DDRA, pin_id);
                }
                break;
            case PORTB_ID:
                if (direction == GPIO_PIN_OUTPUT) {
                    SET_BIT(DDRB, pin_id);
                } else if (direction == GPIO_PIN_INPUT) {
                    CLEAR_BIT(DDRB, pin_id);
                }
                break;
            case PORTC_ID:
                if (direction == GPIO_PIN_OUTPUT) {
                    SET_BIT(DDRC, pin_id);
                } else if (direction == GPIO_PIN_INPUT) {
                    CLEAR_BIT(DDRC, pin_id);
                }
                break;
            case PORTD_ID:
                if (direction == GPIO_PIN_OUTPUT) {
                    SET_BIT(DDRD, pin_id);
                } else if (direction == GPIO_PIN_INPUT) {
                    CLEAR_BIT(DDRD, pin_id);
                }
                break;
            default:
                g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
        }
        g_GPIO_API_STATUS = GPIO_STATUS_SUCCESS;
    }
    return g_GPIO_API_STATUS;
}

/**
 * @brief Sets up the direction of the whole specified port.
 * This is done by writing to the DDRx register of the specified port number.
 * @param port_id Specifies the GPIO port to be configured.
 * This parameter can be one of PORTx_ID.
 * @param direction Specifies the operating direction for the selected pin.
 * This parameter can be on of the en_GPIO_PinDirection enum values:
 * - GPIO_PORT_INPUT
 * - GPIO_PORT_OUTPUT
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_setPortDirection(uint8 port_id, en_GPIO_PortDirection direction) {
    /* Check the validity of input port id and pin id. */
    if ((port_id < 0) || (port_id > MAX_PORT_ID)) {
        g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
    } else {
        switch (port_id) {
            case PORTA_ID:
                if (direction == GPIO_PORT_OUTPUT) {
                    DDRA = GPIO_PORT_HIGH;
                } else if (direction == GPIO_PORT_INPUT) {
                    DDRA = GPIO_PORT_LOW;
                }
                break;
            case PORTB_ID:
                if (direction == GPIO_PORT_OUTPUT) {
                    DDRB = GPIO_PORT_HIGH;
                } else if (direction == GPIO_PORT_INPUT) {
                    DDRB = GPIO_PORT_LOW;
                }
                break;
            case PORTC_ID:
                if (direction == GPIO_PORT_OUTPUT) {
                    DDRC = GPIO_PORT_HIGH;
                } else if (direction == GPIO_PORT_INPUT) {
                    DDRC = GPIO_PORT_LOW;
                }
                break;
            case PORTD_ID:
                if (direction == GPIO_PORT_OUTPUT) {
                    DDRD = GPIO_PORT_HIGH;
                } else if (direction == GPIO_PORT_INPUT) {
                    DDRD = GPIO_PORT_LOW;
                }
                break;
            default:
                g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
        }
        g_GPIO_API_STATUS = GPIO_STATUS_SUCCESS;
    }
    return g_GPIO_API_STATUS;
}

/**
 * @brief Sets the specified pin to a specific value.
 * This is done by writing to the PORTx register of the specified port number.
 * @param[in] port_id Selects GPIO peripheral.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the pin to be written to.
 * This parameter can be one of PINx_ID.
 * @param[in] pin_level Specifies the logical level to written to the selected pin.
 * This parameter can be on of the en_GPIO_PinLevel enum:
 * - GPIO_PIN_LOW
 * - GPIO_PIN_HIGH
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_writePin(uint8 port_id, uint8 pin_id, en_GPIO_PinLevel pin_level) {
    /* Check the validity of input port id and pin id. */
    if ((port_id < 0) || (port_id > MAX_PORT_ID) || (pin_id < 0) || (pin_id > MAX_PIN_ID)) {
        g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
    } else {
        switch (port_id) {
            case PORTA_ID:
                if (pin_level == GPIO_PIN_HIGH) {
                    SET_BIT(PORTA, pin_id);
                } else if (pin_level == GPIO_PIN_LOW) {
                    CLEAR_BIT(PORTA, pin_id);
                }
                break;
            case PORTB_ID:
                if (pin_level == GPIO_PIN_HIGH) {
                    SET_BIT(PORTB, pin_id);
                } else if (pin_level == GPIO_PIN_LOW) {
                    CLEAR_BIT(PORTB, pin_id);
                }
                break;
            case PORTC_ID:
                if (pin_level == GPIO_PIN_HIGH) {
                    SET_BIT(PORTC, pin_id);
                } else if (pin_level == GPIO_PIN_LOW) {
                    CLEAR_BIT(PORTC, pin_id);
                }
                break;
            case PORTD_ID:
                if (pin_level == GPIO_PIN_HIGH) {
                    SET_BIT(PORTD, pin_id);
                } else if (pin_level == GPIO_PIN_LOW) {
                    CLEAR_BIT(PORTD, pin_id);
                }
                break;
            default:
                g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
        }
        g_GPIO_API_STATUS = GPIO_STATUS_SUCCESS;
    }
    return g_GPIO_API_STATUS;
}

/**
 * @brief Read the specified input port pin, and stores that state in the supplied variable.
 * This is done by reading the value of PINx register of the specified port number.
 * @param[in] port_id Selects GPIO peripheral.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the pin to be written to.
 * This parameter can be one of PINx_ID.
 * @param[in,out] p_pin_status A pointer of type uint8 to where the value of the pin is stored.
 * The value is 1 if the pin is set and 0 if the pin is clear.
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_readPin(uint8 port_id, uint8 pin_id, volatile uint8 *p_pin_status) {
    /* Check the validity of input port id and pin id. */
    if ((port_id < 0) || (port_id > MAX_PORT_ID) || (pin_id < 0) || (pin_id > MAX_PIN_ID)) {
        g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
    } else {
        switch (port_id) {
            case PORTA_ID:
                if (BIT_IS_SET(PINA, pin_id)) {
                    *p_pin_status = GPIO_PIN_HIGH;
                } else if (BIT_IS_CLEAR(PINA, pin_id)) {
                    *p_pin_status = GPIO_PIN_LOW;
                }
                break;
            case PORTB_ID:
                if (BIT_IS_SET(PINB, pin_id)) {
                    *p_pin_status = GPIO_PIN_HIGH;
                } else if (BIT_IS_CLEAR(PINB, pin_id)) {
                    *p_pin_status = GPIO_PIN_LOW;
                }
                break;
            case PORTC_ID:
                if (BIT_IS_SET(PINC, pin_id)) {
                    *p_pin_status = GPIO_PIN_HIGH;
                } else if (BIT_IS_CLEAR(PINC, pin_id)) {
                    *p_pin_status = GPIO_PIN_LOW;
                }
                break;
            case PORTD_ID:
                if (BIT_IS_SET(PIND, pin_id)) {
                    *p_pin_status = GPIO_PIN_HIGH;
                } else if (BIT_IS_CLEAR(PIND, pin_id)) {
                    *p_pin_status = GPIO_PIN_LOW;
                }
                break;
            default:
                g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
        }
        g_GPIO_API_STATUS = GPIO_STATUS_SUCCESS;
    }
    return g_GPIO_API_STATUS;
}

/**
 * @brief Flips the state of the specified output port pin.
 * This is done by toggle the logical state of the PORTx of the specified port number.
 * @param[in] port_id Selects GPIO peripheral.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the pin to be written to.
 * This parameter can be one of PINx_ID.
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_togglePin(uint8 port_id, uint8 pin_id) {
    /* Check the validity of input port id and pin id. */
    if ((port_id < 0) || (port_id > MAX_PORT_ID) || (pin_id < 0) || (pin_id > MAX_PIN_ID)) {
        g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
    } else {
        switch (port_id) {
            case PORTA_ID:
                TOGGLE_BIT(PORTA, pin_id);
                break;
            case PORTB_ID:
                TOGGLE_BIT(PORTB, pin_id);
                break;
            case PORTC_ID:
                TOGGLE_BIT(PORTC, pin_id);
                break;
            case PORTD_ID:
                TOGGLE_BIT(PORTD, pin_id);
                break;
            default:
                g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
        }
        g_GPIO_API_STATUS = GPIO_STATUS_SUCCESS;
    }
    return g_GPIO_API_STATUS;
}

/**
 * @brief Sets the whole output port to be a specific logical value.
 * This is done be writing the whole 8-bit value to PORTx of the specified port number.
 * @param[in] port_id Selects GPIO peripheral.
 * This parameter can be one of PORTx_ID.
 * @param[in] port_value Specifies the value to be written to the PORTx register of the specified port number.
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_writePort(uint8 port_id, uint8 port_value) {
    /* Check the validity of input port id and pin id. */
    if ((port_id < 0) || (port_id > MAX_PORT_ID)) {
        g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
    } else {
        switch (port_id) {
            case PORTA_ID:
                PORTA = port_value;
                break;
            case PORTB_ID:
                PORTB = port_value;
                break;
            case PORTC_ID:
                PORTC = port_value;
                break;
            case PORTD_ID:
                PORTD = port_value;
                break;
            default:
                g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
        }
        g_GPIO_API_STATUS = GPIO_STATUS_SUCCESS;
    }
    return g_GPIO_API_STATUS;
}

/**
 * @brief Read the specified input port, and stores that state in the supplied variable.
 * This is done be reading the value of the PINx register of the specified port number.
 * @param[in] port_id Selects GPIO peripheral.
 * This parameter can be one of PORTx_ID.
 * @param[in] p_port_status A pointer of type uint8 to where the value of the pin is stored.
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_readPort(uint8 port_id, volatile uint8 *p_port_status) {
    /* Check the validity of input port id and pin id. */
    if ((port_id < 0) || (port_id > MAX_PORT_ID)) {
        g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
    } else {
        switch (port_id) {
            case PORTA_ID:
                *p_port_status = PINA;
                break;
            case PORTB_ID:
                *p_port_status = PINB;
                break;
            case PORTC_ID:
                *p_port_status = PINC;
                break;
            case PORTD_ID:
                *p_port_status = PIND;
                break;
            default:
                g_GPIO_API_STATUS = GPIO_STATUS_FAILED;
        }
        g_GPIO_API_STATUS = GPIO_STATUS_SUCCESS;
    }
    return g_GPIO_API_STATUS;
}