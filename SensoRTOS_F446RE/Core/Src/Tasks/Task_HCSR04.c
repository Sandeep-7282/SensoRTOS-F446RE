/*
 * Task_HCSR04.c
 *
 *  Created on: May 26, 2025
 *      Author: Sandeep
 *
 *  Description:
 *  FreeRTOS task to interface with the HC-SR04 ultrasonic distance sensor.
 *  Reads distance periodically and outputs it either via UART or OLED
 *  display based on user-selected output mode.
 */

#include "FreeRTOS.h"
#include "task.h"
#include "hcsr04.h"
#include "uart.h"
#include "ssd1306.h"
#include "stdio.h"

// Output selection flag for this task (defined globally in shared control file)
extern volatile uint8_t hcsr04_output;

// Output mode macros
#define OUTPUT_UART 0
#define OUTPUT_OLED 1

/*
 * vTask_HCSR04:
 * Periodically reads distance from the HC-SR04 sensor.
 * If a valid distance is returned, it displays the result
 * on either UART or SSD1306 OLED display, depending on the user's choice.
 */
void vTask_HCSR04(void *params) {
    char msg[64];       // Buffer for UART message
    char line1[32];     // OLED Line 1 text
    char line2[32];     // OLED Line 2 text
    uint32_t distance;  // Distance measurement in cm

    // Initialize the ultrasonic sensor (trig on PA6, echo on PA7)
    HC_SR04_Init();
    UART2_SendString("HC-SR04 Task Started\r\n");

    while (1) {
        // Read distance from HC-SR04 (blocking or delay-based internally)
        distance = HC_SR04_ReadDistance();

        // If distance > 0, we assume the reading is valid
        if (distance > 0) {
            if (hcsr04_output == OUTPUT_UART) {
                // Format and send distance to UART terminal
                snprintf(msg, sizeof(msg), "Distance: %lu cm\r\n", distance);
                UART2_SendString(msg);
            } else if (hcsr04_output == OUTPUT_OLED) {
                // Format and display distance on OLED screen
                snprintf(line1, sizeof(line1), "HC-SR04:");
                snprintf(line2, sizeof(line2), "%lu cm", distance);
                ssd1306_display_sensor_data(line1, line2);
            }
        } else {
            // Handle invalid or failed reading
            if (hcsr04_output == OUTPUT_UART) {
                UART2_SendString("Distance read error!\r\n");
            } else if (hcsr04_output == OUTPUT_OLED) {
                ssd1306_display_sensor_data("HC-SR04 Error", "Read Failed");
            }
        }

        // Delay task for 2 seconds to control update frequency
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
