#ifndef GPIO_H_
#define GPIO_H_

#include "../../utilities/std_types.h"

/**
 * @enum en_GPIO_State
 * @brief Specifies the exit state of GPIO driver functions.
 */
typedef enum {
    GPIO_STATUS_SUCCESS, GPIO_STATUS_FAILED
}en_GPIO_State;

en_GPIO_State g_GPIO_API_STATUS;

/**
 * @enum en_GPIO_PinDirection
 * @brief Specifies the direction of a single pin.
 */
typedef enum {
    GPIO_PIN_INPUT, GPIO_PIN_OUTPUT
}en_GPIO_PinDirection;

/**
 * @enum en_GPIO_PortDirection
 * @brief Specifies the direction of the whole port.
 */
typedef enum {
    GPIO_PORT_INPUT, GPIO_PORT_OUTPUT = 0xFF
}en_GPIO_PortDirection;

/**
 * @enum en_GPIO_PinLevel
 * @brief Specifies the logical level of a single bit in the pin register.
 */
typedef enum {
    GPIO_PIN_LOW, GPIO_PIN_HIGH
}en_GPIO_PinLevel;

/**
 * @enum en_GPIO_PortLevel
 * @brief Specifies the logical level of the whole port register.
 */
typedef enum {
    GPIO_PORT_LOW, GPIO_PORT_HIGH = 0xFF
}en_GPIO_PortLevel;

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
en_GPIO_State GPIO_setPinDirection(uint8 port_id, uint8 pin_id, en_GPIO_PinDirection direction);

en_GPIO_State GPIO_setPortDirection(uint8 port_id, en_GPIO_PortDirection direction);

/**
 * @brief Sets the specified pin to a specific value.
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
en_GPIO_State GPIO_writePin(uint8 port_id, uint8 pin_id, en_GPIO_PinLevel pin_level);

/**
 * @brief Read the specified input port pin, and stores that state in the supplied variable.
 * @param[in] port_id Selects GPIO peripheral.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the pin to be written to.
 * This parameter can be one of PINx_ID.
 * @param[in,out] p_pin_status A pointer of type uint8 to where the value of the pin is stored.
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_readPin(uint8 port_id, uint8 pin_id, volatile uint8 *p_pin_status);

/**
 * @brief Flips the state of the specified output port pin.
 * @param[in] port_id Selects GPIO peripheral.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the pin to be written to.
 * This parameter can be one of PINx_ID.
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_togglePin(uint8 port_id, uint8 pin_id);

/**
 * @brief Sets the whole output port to be a specific logical value.
 * @param[in] port_id Selects GPIO peripheral.
 * This parameter can be one of PORTx_ID.
 * @param[in] port_level Specifies the value to be written to the PORTx register of the specified port number.
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_writePort(uint8 port_id, uint8 port_level);

/**
 * @brief Read the specified input port, and stores that state in the supplied variable.
 * @param[in] port_id Selects GPIO peripheral.
 * This parameter can be one of PORTx_ID.
 * @param[in] p_port_status A pointer of type uint8 to where the value of the pin is stored.
 * @return GPIO_SUCCESS
 * @return GPIO_FAILED
 */
en_GPIO_State GPIO_readPort(uint8 port_id, volatile uint8 *p_port_status);

#endif /* GPIO_H_ */