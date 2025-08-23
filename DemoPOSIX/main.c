#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

// Task 1 - prints every 1 second
void vTask1(void *pvParameters)
{
    (void) pvParameters;
    for (;;)
    {
        printf("Task 1 is running\n");
        vTaskDelay(pdMS_TO_TICKS(1000)); // delay 1 sec
    }
}

// Task 2 - prints every 2 seconds
void vTask2(void *pvParameters)
{
    (void) pvParameters;
    for (;;)
    {
        printf("Task 2 is running\n");
        vTaskDelay(pdMS_TO_TICKS(2000)); // delay 2 sec
    }
}

int main(void)
{
    // Create tasks
    xTaskCreate(vTask1, "Task1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTask2, "Task2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Start scheduler
    vTaskStartScheduler();

    // Should never reach here
    for (;;);
}
