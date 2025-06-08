/*
 * Task_LED.c
 *
 *  Created on: May 24, 2025
 *      Author: sandeep
 */
#include "FreeRTOS.h"
#include "task.h"
#include "gpio.h"
#include "uart.h"

//Task Functions Declarations
void vTask_LED(void *argument);

void vTask_LED(void *argument) {
	UART2_SendString("Led Task Powered Up...\r\n");
    while (1) {
        LED_Toggle();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
