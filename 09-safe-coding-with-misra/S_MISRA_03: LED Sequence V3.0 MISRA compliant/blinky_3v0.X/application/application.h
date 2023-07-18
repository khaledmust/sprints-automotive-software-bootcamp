/* 
 * File:   application.h
 * Author: KHALED MUSTAFA
 *
 * Created on June 29, 2023, 9:48 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "../mcal/timer/timer.h"
#include "../services/timer_services.h"
#include "../mcal/gpio/gpio.h"
#include "../utilities/registers.h"
#include "../ecual/push_button/push_button.h"
#include "../ecual/led/led.h"
#include "../mcal/interrupt/exi.h"

void APP_Init(void);
void APP_Start(void);

#endif	/* APPLICATION_H */

