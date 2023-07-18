#include "application.h"
#include "../utilities/std_types.h"

#define RESET 0
#define PB_THRESHOLD 200
#define MAX_LED_SEQUENCE 7
#define MAX_BLINK_SEQUENCE 7

uint8 g_ledSequence = 0;
uint8 g_blinkSequence = 0;

uint8 pb1_status = 0;
uint8 pb2_status = 0;

st_TIMER_config_t myTIMERConfig = {
    TIMER_NORMAL_MODE,
    CLK_64,
    0, 0, 0,
    0, 250
};

typedef struct {
    uint16 onTime;
    uint16 offTime;
}st_APP_BlinkPeriod_t;

struct {
    st_APP_BlinkPeriod_t sequence1;
    st_APP_BlinkPeriod_t sequence2;
    st_APP_BlinkPeriod_t sequence3;
    st_APP_BlinkPeriod_t sequence4;
    st_APP_BlinkPeriod_t sequence5;
    
} st_APP_BlinkSequence = {
    .sequence1 = {.onTime = 100, .offTime = 900},
    .sequence2 = {.onTime = 200, .offTime = 800},
    .sequence3 = {.onTime = 300, .offTime = 700},
    .sequence4 = {.onTime = 400, .offTime = 500},
    .sequence5 = {.onTime = 800, .offTime = 200}
};

typedef enum {
    ledSequence0 = 0, ledSequence1, ledSequence2, ledSequence3, ledSequence4,
            ledSequence5, ledSequence6, ledSequence7, ledSequence8
}en_ledSequence;

typedef enum {
    blinkSequence1 = 1, blinkSequence2, blinkSequence3, blinkSequence4, 
            blinkSequence5
}en_blinkSequence;

struct st_currentBlinkSequnce_t {
    st_APP_BlinkPeriod_t currentBlink;
}g_st_currentBlinkSequence;

st_LED_config_t led1 = {
    PORTC_ID, PIN0_ID
};

st_LED_config_t led2 = {
    PORTC_ID, PIN1_ID
};

st_LED_config_t led3 = {
    PORTC_ID, PIN3_ID
};

st_LED_config_t led4 = {
    PORTC_ID, PIN7_ID
};


void APP_PB1CallbackFunc(void) {
    g_ledSequence++;
    if (g_ledSequence > MAX_LED_SEQUENCE) {
        g_ledSequence = RESET;
    }
    millis(PB_THRESHOLD);
}

void APP_PB2CallbackFunc(void) {
    g_blinkSequence++;
    if (g_blinkSequence > MAX_BLINK_SEQUENCE) {
        g_blinkSequence = RESET;
    }
    millis(PB_THRESHOLD);
}

void APP_Init(void) {
    LED_init(&led1);
    LED_init(&led2);
    LED_init(&led3);
    LED_init(&led4);
    
    PB_init(PB1);
    PB_init(PB2);
    
    TIMER_Init(&myTIMERConfig);
    
    EXI_triggerEdge(EXI_INT0, LOW_LVL);
    EXI_triggerEdge(EXI_INT1, LOW_LVL);
    
    EXI_setCallBack(EXI_INT0, APP_PB1CallbackFunc);
    EXI_setCallBack(EXI_INT1, APP_PB2CallbackFunc);
    
    EXI_enable(EXI_INT0);
    EXI_enable(EXI_INT1);
}


void APP_Start(void) {
    
    if (g_blinkSequence == blinkSequence1) {
        g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence1;
    } else if (g_blinkSequence == blinkSequence2) {
        g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence2;
    } else if (g_blinkSequence == blinkSequence3) {
        g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence3;
    } else if (g_blinkSequence == blinkSequence4) {
        g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence4;
    } else if (g_blinkSequence == blinkSequence5) {
        g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence5;
    } else {
        g_blinkSequence = RESET;
    }
    
    if (g_ledSequence == ledSequence0) {
        LED_off(&led1);
        LED_off(&led2);
        LED_off(&led3);
        LED_off(&led4);
    } else if (g_ledSequence == ledSequence1) {
        LED_on(&led1);
        millis(g_st_currentBlinkSequence.currentBlink.onTime);
        LED_off(&led1);
        LED_off(&led2);
        LED_off(&led3);
        LED_off(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.offTime);
    } else if (g_ledSequence == ledSequence2) {
        LED_on(&led1);
        LED_on(&led2);
        millis(g_st_currentBlinkSequence.currentBlink.onTime);
        LED_off(&led1);
        LED_off(&led2);
        LED_off(&led3);
        LED_off(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.offTime);
    } else if (g_ledSequence == ledSequence3) {
        LED_on(&led1);
        LED_on(&led2);
        LED_on(&led3);
        millis(g_st_currentBlinkSequence.currentBlink.onTime);
        LED_off(&led1);
        LED_off(&led2);
        LED_off(&led3);
        LED_off(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.offTime);
    } else if (g_ledSequence == ledSequence4) {
        LED_on(&led1);
        LED_on(&led2);
        LED_on(&led3);
        LED_on(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.onTime);
        LED_off(&led1);
        LED_off(&led2);
        LED_off(&led3);
        LED_off(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.offTime);
    } else if (g_ledSequence == ledSequence5) {
        LED_on(&led2);
        LED_on(&led3);
        LED_on(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.onTime);
        LED_off(&led1);
        LED_off(&led2);
        LED_off(&led3);
        LED_off(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.offTime);
    } else if (g_ledSequence == ledSequence6) {
       LED_on(&led3);
        LED_on(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.onTime);
        LED_off(&led1);
        LED_off(&led2);
        LED_off(&led3);
        LED_off(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.offTime);
    } else if (g_ledSequence == ledSequence7) {
        LED_on(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.onTime);
        LED_off(&led1);
        LED_off(&led2);
        LED_off(&led3);
        LED_off(&led4);
        millis(g_st_currentBlinkSequence.currentBlink.offTime);
    } else if (g_ledSequence == ledSequence8) {
        LED_off(&led1);
        LED_off(&led2);
        LED_off(&led3);
        LED_off(&led4);
    } else {
        g_ledSequence = RESET;
    }
}
