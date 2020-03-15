#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"

void addTask (void* pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    volatile unsigned long long *count = (void *)0x7020;
    volatile unsigned long long *debug = (void *)0x7010;

    while(1) {
        *count = *count + 10;
        *debug += 1;
        vTaskDelayUntil( &xLastWakeTime, 15 );
    }
}

void addTask2 (void* pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    volatile unsigned long long *count = (void *)0x7080;
    volatile unsigned long long *debug = (void *)0x7010;

    while(1) {
        *count = *count + 3;
        *debug += 1;
        vTaskDelayUntil( &xLastWakeTime, 15 );
    }
}

int main(void)
{
    volatile unsigned long long *count = (void *)0x7020;
    volatile unsigned long long *count2 = (void *)0x7080;
    volatile unsigned long long *debug = (void *)0x7010;

    *debug = 0;
    *count2 = 0;
    *count = 0;

    xTaskCreate( addTask, ( signed char * ) "add", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, ( xTaskHandle * ) NULL );
    xTaskCreate( addTask2, ( signed char * ) "add", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, ( xTaskHandle * ) NULL );

    vTaskStartScheduler();

    *debug = 1;
    return EXIT_SUCCESS;
} 
