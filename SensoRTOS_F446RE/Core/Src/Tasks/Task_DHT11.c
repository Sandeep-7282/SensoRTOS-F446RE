/*
 * Task_DHT11.c
 *
 *  Created on: May 27, 2025
 *      Author: Sandeep
 *
 *  Description:
 *  FreeRTOS task to interface with the DHT11 temperature and humidity sensor.
 *  Reads sensor data periodically and outputs via UART or OLED display
 *  depending on the global output mode selection.
 */

#include "FreeRTOS.h"
#include "task.h"
#include "dht11.h"
#include "uart.h"
#include "ssd1306.h"
#include "stdio.h"
#include "string.h"

// Global output mode control variable (defined in shared output_control module)
extern volatile uint8_t dht11_output;

// Output mode macros for clarity
#define OUTPUT_UART 0
#define OUTPUT_OLED 1

// Global volatile variables to hold latest temperature and humidity readings
volatile uint8_t dht_temp = 0;
volatile uint8_t dht_hum = 0;

/*
 * vTask_DHT11:
 * Task continuously reads data from the DHT11 sensor.
 * On successful read, updates global variables and outputs
 * data either on UART terminal or OLED display.
 */
void vTask_DHT11(void *params) {
    DHT11_Data sensor_data;   // Struct to hold raw DHT11 readings and validity
    char msg[64];            // Buffer for UART output string
    char line1[32], line2[32];  // Strings for OLED display lines

    DHT11_Init();  // Initialize DHT11 sensor GPIO and settings
    UART2_SendString("DHT11 Task Started\r\n");

    while (1) {
        // Attempt to read data from DHT11 sensor
        if (DHT11_Read(&sensor_data) && sensor_data.valid) {
            // Update global temperature and humidity with latest readings
            dht_temp = sensor_data.temperature;
            dht_hum  = sensor_data.humidity;

            // Output based on selected mode
            if (dht11_output == OUTPUT_UART) {
                // Format temperature and humidity for UART terminal
                snprintf(msg, sizeof(msg), "Temperature: %d°C, Humidity: %d%%\r\n",
                         dht_temp, dht_hum);
                UART2_SendString(msg);
            } else if (dht11_output == OUTPUT_OLED) {
                // Prepare display lines for OLED screen
                snprintf(line1, sizeof(line1), "Temp: %d C", dht_temp);
                snprintf(line2, sizeof(line2), "Hum:  %d %%", dht_hum);
                ssd1306_display_sensor_data(line1, line2);
            }
        } else {
            // Handle failed sensor read with error messages
            if (dht11_output == OUTPUT_UART) {
                UART2_SendString("DHT11 Read Failed!\r\n");
            } else if (dht11_output == OUTPUT_OLED) {
                ssd1306_display_sensor_data("DHT11 Error", "Read Failed");
            }
        }

        // Delay 1 second before next read to comply with sensor timing specs
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
