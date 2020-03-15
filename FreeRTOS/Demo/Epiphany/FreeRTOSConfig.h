#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H


#define configCALL_STACK_SIZE   0x50

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION        1
#define configUSE_IDLE_HOOK         0
#define configUSE_TICK_HOOK         0
#define configMAX_PRIORITIES        ( 4 )
#define configCPU_CLOCK_HZ          ( ( unsigned long ) 700000000 )
#define configTICK_RATE_HZ          ( ( TickType_t ) 1000 )
#define configMINIMAL_STACK_SIZE    ( ( unsigned short ) 0x200 )  // expressed in words. 512 * word (uint_32) = 2-48 bytes
#define configUSE_16_BIT_TICKS      1
#define configTOTAL_HEAP_SIZE       ( (size_t ) ( 10450 ) )
#define configUSE_CO_ROUTINES 		0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskDelayUntil             1
#define INCLUDE_vTaskPrioritySet		    0
#define INCLUDE_uxTaskPriorityGet		    0
#define INCLUDE_vTaskDelete				    0
#define INCLUDE_vTaskSuspend			    1
#define INCLUDE_vTaskDelay                  1

#endif /* FREERTOS_CONFIG_H */
