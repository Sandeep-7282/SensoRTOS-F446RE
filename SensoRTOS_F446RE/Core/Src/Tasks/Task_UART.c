/*
 * Task_UART.c
 *
 *  Created on: May 25, 2025
 *      Author: Sandeep
 *
 *  Description:
 *  UART CLI Task for handling user commands via UART2.
 *  This task listens to user input, builds command strings,
 *  and dispatches them to the CLI handler function.
 */

#include "FreeRTOS.h"
#include "task.h"
#include "gpio.h"
#include "uart.h"
#include "uart_cli.h"
#include <string.h>
#include "output_control.h"

#define CLI_BUFFER_SIZE 64  // Max length of command input

// Optional forward declaration if not included via uart_cli.h
void handle_cli_command(char *cmd);

/*
 * vTask_UART:
 * FreeRTOS task responsible for CLI command reception and dispatch.
 * It reads characters over UART2, handles simple line editing,
 * and invokes the command handler on newline.
 */
void vTask_UART(void *pvParameters) {
    char cli_buffer[CLI_BUFFER_SIZE];  // Buffer to store the command string
    int idx = 0;                       // Index for buffer filling
    char c;

    UART2_SendString("\r\n>> ");  // Initial CLI prompt on boot

    while (1) {
        c = UART2_ReceiveChar();  // Blocking call - waits for character
        UART2_SendChar(c);        // Echo back for user feedback

        if (c == '\r' || c == '\n') {  // Enter pressed
            UART2_SendString("\r\n");

            if (idx > 0) {
                cli_buffer[idx] = '\0';  // Null-terminate input string
                handle_cli_command(cli_buffer);  // Parse and execute command
                idx = 0;  // Reset buffer index after command execution
                vTaskDelay(pdMS_TO_TICKS(500));  // Small delay to avoid bouncing
            }

            UART2_SendString(">> ");  // Show next prompt
        } else if (c == '\b' || c == 127) {  // Handle backspace/delete
            if (idx > 0) {
                idx--;  // Move buffer index back
                UART2_SendString("\b \b");  // Erase character visually on terminal
            }
        } else if (idx < CLI_BUFFER_SIZE - 1) {  // Accept only if buffer isn't full
            cli_buffer[idx++] = c;  // Store character in buffer
            UART2_SendChar(c);      // Echo valid characters again (optional)
        }
    }
}
