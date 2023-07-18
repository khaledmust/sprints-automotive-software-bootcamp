/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h> /* To copy the string to the structure member. */

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"
#include "semphr.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )

TaskHandle_t PB_1_TASK_TaskHandler      = NULL;
TaskHandle_t PB_2_TASK_TaskHandler      = NULL;
TaskHandle_t Consumer_TASK_TaskHandler  = NULL;
TaskHandle_t Periodic_TASK_TaskHandler  = NULL;

QueueHandle_t xQueue = NULL;

pinState_t g_PB_1_previousState = PIN_IS_HIGH;
pinState_t g_PB_1_currentState  = PIN_IS_HIGH;
pinState_t g_PB_2_previousState = PIN_IS_HIGH;
pinState_t g_PB_2_currentState  = PIN_IS_HIGH;

/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/

const uint8_t Msg_1[ 15 ] = "PB 1 Pressed.\n";
const uint8_t Msg_2[ 15 ] = "PB 2 Pressed.\n";
const uint8_t Msg_3[ 15 ] = "Periodic str.\n";

typedef enum {
  FLAG_DOWN, FLAG_UP
} en_PB_flagState;

void PB_1_Task (void *pvParameters) {
  for ( ;; ) {
    g_PB_1_currentState = GPIO_read(PORT_0, PIN0);
    /* If push button is pressed, take the semaphore if avialable. */
    if (g_PB_1_previousState == PIN_IS_LOW && g_PB_1_currentState == PIN_IS_HIGH) {
      g_PB_1_previousState = PIN_IS_HIGH;
      xQueueSend(xQueue, (void *)&Msg_1, ( TickType_t ) 10);
    } else if (g_PB_1_previousState == PIN_IS_HIGH && g_PB_1_currentState == PIN_IS_LOW) {
      g_PB_1_previousState = PIN_IS_LOW;
      xQueueSend(xQueue, (void *)&Msg_1, ( TickType_t ) 10);
    } else {
      /* Do nothing. */
    }
  }
}

void PB_2_Task (void *pvParameters) {
  for ( ;; ) {
    g_PB_2_currentState = GPIO_read(PORT_0, PIN1);
    /* If push button is pressed, take the semaphore if avialable. */
    if (g_PB_2_previousState == PIN_IS_LOW && g_PB_2_currentState == PIN_IS_HIGH) {
      g_PB_2_previousState = PIN_IS_HIGH;
      xQueueSend(xQueue, (void *)&Msg_2, ( TickType_t ) 10);
    } else if (g_PB_2_previousState == PIN_IS_HIGH && g_PB_2_currentState == PIN_IS_LOW) {
      g_PB_2_previousState = PIN_IS_LOW;
      xQueueSend(xQueue, (void *)&Msg_2, ( TickType_t ) 10);
    } else {
      /* Do nothing. */
    }
  }
}

void Consumer_Task (void *pvParameters) {
  uint8_t xRxedStructure[ 15 ];
  for ( ;; ) {
      if( xQueue != NULL ) {
        if( xQueueReceive( xQueue, &( xRxedStructure ), ( TickType_t ) 10 ) == pdPASS ) {
          /* xRxedStructure now contains a copy of xMessage. */
          /* Write on the terminal */
          while ( vSerialPutString( (const signed char *) xRxedStructure, 15) == pdFALSE );
        }
      }
  }
}

void Periodic_Task (void *pvParameters) {
  for ( ;; ) {
    xQueueSend(xQueue, (void *)&Msg_3, ( TickType_t ) 10);
    vTaskDelay(100);
  }
}
/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{ 
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();

  /* Initialize UART */
  xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);
    
  /* Create a queue capable of containing 10 pointers to AMessage structures. */
  xQueue = xQueueCreate( 10, 15 * sizeof( uint8_t ) );
	
  /* Create Tasks */
	xTaskCreate(
	PB_1_Task,
	"PB 1 task notifier",
	configMINIMAL_STACK_SIZE,
	NULL,
	1,
	&PB_1_TASK_TaskHandler);

  xTaskCreate(
	PB_2_Task,
	"PB 2 task notifier",
	configMINIMAL_STACK_SIZE,
	NULL,
	1,
	&PB_2_TASK_TaskHandler);
  
  xTaskCreate(
	Consumer_Task,
	"Consumer task",
	configMINIMAL_STACK_SIZE,
	NULL,
	1,
	&Consumer_TASK_TaskHandler);
  
  xTaskCreate(
	Periodic_Task,
	"Peridic task",
	configMINIMAL_STACK_SIZE,
	NULL,
	1,
	&Periodic_TASK_TaskHandler);

	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/
