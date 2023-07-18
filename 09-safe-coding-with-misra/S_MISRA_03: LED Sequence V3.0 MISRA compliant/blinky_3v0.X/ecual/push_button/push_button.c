#include "push_button.h"
#include "../../mcal/gpio/gpio.h"

en_PB_State g_PB_API_Status = 0;

/**
 * @brief Initializes the direction of the PB pins as input pins.
 * This is done by using the GPIO_setPinDirection function from the GPIO driver
 * @param[in] pb_name Specifies the PB to be initialized.
 * This parameter can be on of the en_PB_Names enum:
 * - PB1
 * - PB2
 * - PB3
 * - PB4
 * @return PB_STATUS_SUCCESS
 * @return PB_STATUS_FAILED
 */
en_PB_State PB_init(en_PB_Names pb_name) {
    if (pb_name == PB1) {
        g_GPIO_API_STATUS = GPIO_setPinDirection(PB1_PORT_ID, PB1_PIN_ID, GPIO_PIN_INPUT);
    } else if (pb_name == PB2) {
        g_GPIO_API_STATUS = GPIO_setPinDirection(PB2_PORT_ID, PB2_PIN_ID, GPIO_PIN_INPUT);
    } else if (pb_name == PB3) {
        g_GPIO_API_STATUS = GPIO_setPinDirection(PB3_PORT_ID, PB3_PIN_ID, GPIO_PIN_INPUT);
    } else if (pb_name == PB4) {
        g_GPIO_API_STATUS = GPIO_setPinDirection(PB4_PORT_ID, PB4_PIN_ID, GPIO_PIN_INPUT);
    } else {
        g_PB_API_Status = PB_STATUS_FAILED;
    }
    
    if (g_GPIO_API_STATUS != GPIO_STATUS_SUCCESS) {
        g_PB_API_Status = PB_STATUS_FAILED;
    }
    return g_PB_API_Status;
}

/**
 * @brief Reads the current status of the push button and stores it in the supplied pointer.
 * This is done by using the GPIO_readPin function from the GPIO driver
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
en_PB_State PB_status(en_PB_Names pb_name, uint8 *p_pb_status) {
    if (pb_name == PB1) {
        g_GPIO_API_STATUS = GPIO_readPin(PB1_PORT_ID, PB1_PIN_ID, p_pb_status);
    } else if (pb_name == PB2) {
        g_GPIO_API_STATUS = GPIO_readPin(PB2_PORT_ID, PB2_PIN_ID, p_pb_status);
    } else if (pb_name == PB3) {
        g_GPIO_API_STATUS = GPIO_readPin(PB3_PORT_ID, PB3_PIN_ID, p_pb_status);
    } else if (pb_name == PB4) {
        g_GPIO_API_STATUS = GPIO_readPin(PB4_PORT_ID, PB4_PIN_ID, p_pb_status);
    } else {
        g_PB_API_Status = PB_STATUS_FAILED;
    }
    
    if (g_GPIO_API_STATUS != GPIO_STATUS_SUCCESS) {
        g_PB_API_Status = PB_STATUS_FAILED;
    }
    return g_PB_API_Status;
}