#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* Basic settings */
/**
 * with the below 2 macros set to 0 app can have no heap but you will not be 
 * able to use the  xTaskCreate api 
 *  @note need to do more research about this
 */
/*
#define configSUPPORT_DYNAMIC_ALLOCATION 0 //0 - do not want to use dynamic allocation (No heap)
#define configSUPPORT_STATIC_ALLOCATION 0 //
*/
// macros are written in caps and prefix in lower which indicates where
// macros is defined
#define configUSE_PREEMPTION            1
#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0
#define configCPU_CLOCK_HZ              ( ( unsigned long ) 1000000 )
#define configTICK_RATE_HZ              ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES            5
#define configMINIMAL_STACK_SIZE        ( ( unsigned short ) 200 )
#define configTOTAL_HEAP_SIZE           ( ( size_t ) ( 75 * 1024 ) )
#define configMAX_TASK_NAME_LEN         16
#define configUSE_TRACE_FACILITY        0
#define configUSE_16_BIT_TICKS          0
#define configIDLE_SHOULD_YIELD         1

/* API inclusion options */
#define INCLUDE_vTaskPrioritySet        1
#define INCLUDE_uxTaskPriorityGet       1
#define INCLUDE_vTaskDelete             1
#define INCLUDE_vTaskSuspend            1
#define INCLUDE_vTaskDelayUntil         1
#define INCLUDE_vTaskDelay              1

#endif /* FREERTOS_CONFIG_H */
