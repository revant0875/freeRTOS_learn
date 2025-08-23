#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

/* Task that prints the system tick count */
void vTickTask(void *pvParameters)
{
    (void) pvParameters;
    while (1)
    {
        TickType_t ticks = xTaskGetTickCount();
        printf("Tick Count: %lu\n", (unsigned long)ticks);

        /* Delay 1000ms */
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int main(void)
{
    /* Create the tick printing task */
    xTaskCreate(vTickTask, "TickTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    /* Will not reach here unless there is insufficient heap */
    for (;;);
}
