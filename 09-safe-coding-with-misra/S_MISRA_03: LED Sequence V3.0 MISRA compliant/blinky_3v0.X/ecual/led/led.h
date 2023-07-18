#ifndef LED_H_
#define LED_H_
#include "../../utilities/registers.h"

/**
 * @enum en_LED_State
 * @brief Specifies the exit state of LED driver functions.
 */
typedef enum {
    LED_STATUS_SUCCESS, LED_STATUS_FAILED
}en_LED_State;

typedef struct {
    uint8 led_port;
    uint8 led_pin;
}st_LED_config_t;

/**
 * @brief Initializes the direction of the LED pins as output pins.
 * @param[in] led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_init(st_LED_config_t *ptr_st_LED_config);

/**
 * @brief Turns on the specified LED.
 * @param led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_on(st_LED_config_t *ptr_st_LED_config);

/**
 * @brief Turns off the specified LED.
 * @param led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_off(st_LED_config_t *ptr_st_LED_config);

#endif /* LED_H_ */