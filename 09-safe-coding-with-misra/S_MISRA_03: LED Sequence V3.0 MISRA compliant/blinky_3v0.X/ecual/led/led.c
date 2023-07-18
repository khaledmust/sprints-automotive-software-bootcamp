#include "led.h"
#include "../../mcal/gpio/gpio.h"

en_LED_State g_LED_API_Status = 0;

/**
 * @brief Initializes the direction of the LED pins as output pins.
 * This is done by using the GPIO_setPinDirection function from the GPIO driver.
 * @param[in] led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_init(st_LED_config_t *ptr_st_LED_config) {
    g_GPIO_API_STATUS = GPIO_setPinDirection(ptr_st_LED_config->led_port, ptr_st_LED_config->led_pin, GPIO_PIN_OUTPUT);
    if (g_GPIO_API_STATUS != GPIO_STATUS_SUCCESS) {
        g_LED_API_Status = LED_STATUS_FAILED;
    } else {
        g_LED_API_Status = LED_STATUS_SUCCESS;
    }
    return g_LED_API_Status;
}

/**
 * @brief Turns on the specified LED.
 * This is done by using the GPIO_writePin function from the GPIO driver.
 * @param led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_on(st_LED_config_t *ptr_st_LED_config) {
    g_GPIO_API_STATUS = GPIO_writePin(ptr_st_LED_config->led_port, ptr_st_LED_config->led_pin, GPIO_PIN_HIGH);
    if (g_GPIO_API_STATUS != GPIO_STATUS_SUCCESS) {
        g_LED_API_Status = LED_STATUS_FAILED;
    } else {
        g_LED_API_Status = LED_STATUS_SUCCESS;
    }
    return g_LED_API_Status;
}

/**
 * @brief Turns off the specified LED.
 * This is done by using the GPIO_writePin function from the GPIO driver.
 * @param led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_off(st_LED_config_t *ptr_st_LED_config) {
    g_GPIO_API_STATUS = GPIO_writePin(ptr_st_LED_config->led_port, ptr_st_LED_config->led_pin, GPIO_PIN_LOW);
    if (g_GPIO_API_STATUS != GPIO_STATUS_SUCCESS) {
        g_LED_API_Status = LED_STATUS_FAILED;
    } else {
        g_LED_API_Status = LED_STATUS_SUCCESS;
    }
    return g_LED_API_Status;
}