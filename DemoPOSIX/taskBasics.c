#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

#define mainDELAY_LOOP_COUNT            100000000U

void vTask1(void *pvParameters)
{
    (void)pvParameters;
    /* ulCount is declared volatile to ensure it is not optimized out. */
    volatile unsigned long ulCount;
    /* As per most tasks, this task is implemented in an infinite loop. */
    for (;;)
    {
        /* Print out the name of this task. */
        printf("Task 1 is running\n");
        /* Delay for a period. */
        for (ulCount = 0; ulCount < mainDELAY_LOOP_COUNT; ulCount++)
        {
            /*
             * This loop is just a very crude delay implementation. There is
             * nothing to do in here.
             */
        }
    }
}
void vTask2(void *pvParameters)
{
    (void)pvParameters;
    /* ulCount is declared volatile to ensure it is not optimized out. */
    volatile unsigned long ulCount;
    /* As per most tasks, this task is implemented in an infinite loop. */
    for (;;)
    {
        /* Print out the name of this task. */
        printf("Task 2 is running\n");
        /* Delay for a period. */
        for (ulCount = 0; ulCount < mainDELAY_LOOP_COUNT; ulCount++)
        {
            /*
             * This loop is just a very crude delay implementation. There is
             * nothing to do in here.
             */
        }
    }
}
int main(void)
{
    /*
     * Variables declared here may no longer exist after starting the FreeRTOS
     * scheduler. Do not attempt to access variables declared on the stack used
     * by main() from tasks.
     */
    /*
     * Create one of the two tasks. Note that a real application should check
     * the return value of the xTaskCreate() call to ensure the task was
     * created successfully.
     */
    xTaskCreate(vTask1,   /* Pointer to the function that implements the task.*/
                "Task 1", /* Text name for the task. */
                1000,     /* Stack depth in words. */
                NULL,     /* This example does not use the task parameter. */
                1,        /* This task will run at priority 1. */
                NULL);    /* This example does not use the task handle. */

    /* Create the other task in exactly the same way and at the same priority.*/
    xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, NULL);
    /* Start the scheduler so the tasks start executing. */
    vTaskStartScheduler();
    /*
     * If all is well main() will not reach here because the scheduler will now
     * be running the created tasks. If main() does reach here then there was
     * not enough heap memory to create either the idle or timer tasks
     */
    for(;;);
}