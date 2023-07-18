#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_
#include "../../utilities/registers.h"
#include "../../mcal/interrupt/exi.h"

/**
 * @defgroup PB_PORT_PIN_CONFIGURATION
 * @{
 */
#define PB1_PORT_ID    PORTD_ID ///< The port ID where the PB1 is connected to.
#define PB1_PIN_ID     PIN2_ID ///< The pin number where the PB1 is connected to.

#define PB2_PORT_ID   PORTD_ID ///< The port ID where the PB2 is connected to.
#define PB2_PIN_ID    PIN3_ID ///< The pin number where the PB2 is connected to.

#define PB3_PORT_ID     PORTD_ID ///< The port ID where the PB3 is connected to.
#define PB3_PIN_ID      PIN4_ID ///< The pin number where the PB3 is connected to.

#define PB4_PORT_ID     PORTD_ID ///< The port ID where the PB4 is connected to.
#define PB4_PIN_ID      PIN5_ID ///< The pin number where the PB4 is connected to.
/**@}*/

/**
 * @enum en_PB_Names
 * @brief Specifies the names of the connected push buttons.
 */
typedef enum {
    PB1, PB2, PB3, PB4
}en_PB_Names;

/**
 * @enum en_PB_State
 * @brief Specifies the exit state of LED driver functions.
 */
typedef enum {
    PB_STATUS_SUCCESS, PB_STATUS_FAILED
}en_PB_State;

/**
 * @brief Initializes the direction of the PB pins as input pins.
 * @param[in] pb_name Specifies the PB to be initialized.
 * This parameter can be on of the en_PB_Names enum:
 * - PB1
 * - PB2
 * - PB3
 * - PB4
 * @return PB_STATUS_SUCCESS
 * @return PB_STATUS_FAILED
 */
en_PB_State PB_init(en_PB_Names pb_name);

/**
 *
 * @param[in] pb_name Specifies the PB to be initialized.
 * This parameter can be on of the en_PB_Names enum:
 * - PB1
 * - PB2
 * - PB3
 * - PB4
 * @param[out] p_pb_status A pointer to the variable where the state of the push button is stored.
 * @return PB_STATUS_SUCCESS
 * @return PB_STATUS_FAILED
 */
en_PB_State PB_status(en_PB_Names pb_name, uint8 *p_pb_status);

#endif /* PUSH_BUTTON_H_ */