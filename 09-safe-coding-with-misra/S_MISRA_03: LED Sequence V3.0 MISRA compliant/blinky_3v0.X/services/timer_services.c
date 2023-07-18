#include "timer_services.h"
#include "../mcal/timer/timer.h"

uint16 g_TickCounter = 0;

void millis(uint16 delay_ms) {
    for (g_TickCounter = 0; g_TickCounter < delay_ms; g_TickCounter++) {
        while (TIMER_GetOCFlagStatus() != FLAG_SET) {            
        }
    }
}

