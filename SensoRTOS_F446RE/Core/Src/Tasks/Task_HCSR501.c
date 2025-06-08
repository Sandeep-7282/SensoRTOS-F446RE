/*
 * Task_HCSR501.c
 *
 *  Created on: May 25, 2025
 *      Author: Sandeep
 *
 *  Description:
 *  FreeRTOS task for reading motion data from HC-SR501 PIR sensor.
 *  If motion is detected, the system notifies via UART or OLED,
 *  and activates the buzzer on PA9.
 */

#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "hcsr501.h"
#include "uart.h"
#include "gpio.h"
#include "stdio.h"
#include "ssd1306.h"

// Global output flag defined in shared logic file (output_control.c)
extern volatile uint8_t hcsr501_output;

// Output modes
#define OUTPUT_UART 0
#define OUTPUT_OLED 1

/*
 * vTask_HCSR501:
 * This task polls the PIR motion sensor connected to PB13.
 * On motion detection, it activates a buzzer (PA9) and displays
 * output either via UART or SSD1306 OLED based on user CLI selection.
 */
void vTask_HCSR501(void *pvParameters) {
    HCSR501_Init();  // Configure PB13 as input with pull-down for PIR sensor

    while (1) {
        // Read motion sensor value: HIGH = motion, LOW = no motion
        uint8_t motion_detected = (GPIOB->IDR & (1 << 13)) ? 1 : 0;

        if (motion_detected) {
            Buzzer_On();  // Trigger alert via buzzer (active-high on PA9)

            // Output notification to UART or OLED
            if (hcsr501_output == OUTPUT_UART) {
                UART2_SendString("Motion Detected!\r\n");
            } else if (hcsr501_output == OUTPUT_OLED) {
                ssd1306_display_sensor_data("PIR Sensor", "Motion Detected!");
            }
        } else {
            Buzzer_Off();  // Stop buzzer if no motion

            if (hcsr501_output == OUTPUT_UART) {
                UART2_SendString("No motion.\r\n");
            } else if (hcsr501_output == OUTPUT_OLED) {
                ssd1306_display_sensor_data("PIR Sensor", "No Motion");
            }
        }

        // Delay 1.5 seconds between polls to reduce processing load
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}
