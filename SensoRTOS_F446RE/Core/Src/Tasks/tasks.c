/*
 * tasks.c
 *
 *  Created on: May 22, 2025
 *      Author: Sandeep
 *
 *  Description:
 *  This file handles task creation for the SensoRTOS project.
 *  It declares task handles and initializes all FreeRTOS tasks with proper priorities.
 */

#include "stdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx.h"
#include "uart.h"
#include "gpio.h"
#include "Task_LED.h"
#include "Task_DHT11.h"
#include "Task_UART.h"
#include "Task_HCSR04.h"
#include "Task_HCSR501.h"

/* ========== Global Task Handles ========== */
// These can be used to interact with specific tasks (e.g., suspend/resume)
TaskHandle_t ledTaskHandle = NULL;
TaskHandle_t dhtTaskHandle = NULL;
TaskHandle_t uartTaskHandle = NULL;
TaskHandle_t pirTaskHandle = NULL;

/* ========== Task Startup Function ========== */
/*
 * StartDefaultTasks:
 * Called from main.c to create all application tasks.
 * Each task is assigned a priority to ensure timing and responsiveness.
 */
void StartDefaultTasks(void) {
    UART2_SendString("Setting Up Tasks...\r\n");

    // Task: LED Blink
    // Priority: 0 (lowest)
    // Purpose: Basic blinking to show system is alive
    xTaskCreate(vTask_LED, "LED", 128, NULL, 0, &ledTaskHandle);

    // Task: DHT11 Sensor Reading
    // Priority: 1 (low)
    // Purpose: Periodically read temperature and humidity
    xTaskCreate(vTask_DHT11, "DHT11", 256, NULL, 1, &dhtTaskHandle);

    // Task: HC-SR04 Ultrasonic Distance Sensor
    // Priority: 1 (low)
    // Purpose: Periodically measure distance
    xTaskCreate(vTask_HCSR04, "HC_SR04", 256, NULL, 1, NULL);

    // Task: HC-SR501 PIR Motion Sensor
    // Priority: 2 (medium)
    // Purpose: Monitor motion and control buzzer
    xTaskCreate(vTask_HCSR501, "PIR", 128, NULL, 2, &pirTaskHandle);

    // Task: UART CLI Handler
    // Priority: 3 (highest)
    // Purpose: Handle UART commands and output control (OLED/Terminal)
    xTaskCreate(vTask_UART, "UART", 128, NULL, 3, &uartTaskHandle);
}
