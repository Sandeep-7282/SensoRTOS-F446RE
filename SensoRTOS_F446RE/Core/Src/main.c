/*
 * main.c
 *
 *  Created on: May 18, 2025
 *      Author: Sandeep
 *
 *  Description:
 *  Entry point for the SensoRTOS project.
 *  Initializes UART, GPIO, TIM1 for RTOS tick, and launches all FreeRTOS tasks.
 */

#include "stm32f4xx.h"
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "uart.h"
#include "tasks.h"
#include "gpio.h"
#include "info.h"

// Static memory for the FreeRTOS software timer task (if used)
static StaticTask_t xTimerTaskTCBBuffer;
static StackType_t xTimerStack[configTIMER_TASK_STACK_DEPTH];

/*
 * FreeRTOS hook to provide memory for timer task when using static allocation.
 */
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
                                    StackType_t **ppxTimerTaskStackBuffer,
                                    uint32_t *pulTimerTaskStackSize)
{
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCBBuffer;
    *ppxTimerTaskStackBuffer = xTimerStack;
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

/*
 * FreeRTOS hook function called if any task overflows its stack.
 * Useful for debugging memory issues in FreeRTOS tasks.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    UART2_SendString("Stack overflow in task: ");
    UART2_SendString(pcTaskName);
    UART2_SendString("\r\n");

    while (1); // Halt the system for debugging
}

/*
 * TIM1 Configuration for FreeRTOS system tick
 * - Uses TIM1 instead of SysTick to generate the 1ms RTOS tick.
 * - TIM1 is on APB2 and runs at 180 MHz (assuming default STM32F4 config).
 */
void TIM1_Init_For_RTOS_Tick(void) {
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; // Enable TIM1 clock

    /*
     * TIM1 Clock = 180 MHz
     * Prescaler = 18000 - 1 → TIM1 counter clock = 10 kHz (0.1 ms)
     * ARR = 10 - 1 → Interrupt every 10 counts → 1 ms
     */
    TIM1->PSC = 18000 - 1;   // Scale down to 10 kHz
    TIM1->ARR = 10 - 1;      // Generate interrupt every 1 ms

    TIM1->DIER |= TIM_DIER_UIE;   // Enable update interrupt
    TIM1->CR1 |= TIM_CR1_CEN;     // Start TIM1

    NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);  // Enable TIM1 update interrupt in NVIC
}

/*
 * Main entry function
 */
int main(void) {
    UART2_Init();           // Initialize UART2 for CLI and debugging
    GPIO_Init();            // Initialize general-purpose I/Os (LED, Buzzer, etc.)
    TIM1_Init_For_RTOS_Tick();  // Use TIM1 for 1ms RTOS tick

    DisplayProjectInfo();   // Show boot message & project info
    DisplayHelp();          // Show available commands on CLI

    __enable_irq();         // Globally enable interrupts

    StartDefaultTasks();    // Create and start all application tasks

    vTaskStartScheduler();  // Start the FreeRTOS scheduler (never returns)

    // Should never reach here unless scheduler fails
    while (1) {
    }
}
