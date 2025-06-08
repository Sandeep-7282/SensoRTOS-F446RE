/*
 * cli_info.c
 *
 *  Created on: Jun 8, 2025
 *      Author: sandeep
 */

#include "uart.h"
#include "info.h"
#include "stdio.h"

void DisplayHelp(void) {
    UART2_SendString("\r\n===== SensoRTOS Command Help =====\r\n");
    UART2_SendString("help         : Show this help message\r\n");
    UART2_SendString("reboot       : Reboot the system\r\n");
    UART2_SendString("oled dht11   : Redirect DHT11 output to OLED\r\n");
    UART2_SendString("uart dht11   : Redirect DHT11 output to UART\r\n");
    UART2_SendString("oled hcsr04  : Redirect HC-SR04 output to OLED\r\n");
    UART2_SendString("uart hcsr04  : Redirect HC-SR04 output to UART\r\n");
    UART2_SendString("oled pir     : Redirect PIR output to OLED\r\n");
    UART2_SendString("uart pir     : Redirect PIR output to UART\r\n");
    UART2_SendString("oled off     : Clear OLED and set all outputs to UART\r\n");
    UART2_SendString("===================================\r\n");
}


void DisplayProjectInfo(void) {
    UART2_SendString("\r\n=============================\r\n");
    UART2_SendString("      SensoRTOS Booting...\r\n");
    UART2_SendString("  Smart RTOS based Sensor System with CLI\r\n");
    UART2_SendString("=============================\r\n");

    UART2_SendString("Project     : SensoRTOS v1.0.0\r\n");
    UART2_SendString("Board       : STM32F446RE (Nucleo-64)\r\n");
    UART2_SendString("Clock       : 180 MHz System Clock\r\n");
    UART2_SendString("RTOS        : FreeRTOS (Preemptive)\r\n");
    UART2_SendString("Tasks       : LED, DHT11, HC-SR04, HCSR501, UART\r\n");
    UART2_SendString("Stack Size  : LED=128, DHT11=256, HCSR04=256, PIR=128, UART=128\r\n");
    UART2_SendString("Heap Size   : 15 KB (configTOTAL_HEAP_SIZE)\r\n");

    UART2_SendString("-----------------------------\r\n");
    UART2_SendString("Peripherals:\r\n");
    UART2_SendString(" > USART2   : PA2 (TX), PA3 (RX) @ 9600 baud rate\r\n");
    UART2_SendString(" > OLED     : I2C1 - PB8 (SCL), PB9 (SDA), Addr 0x3C\r\n");
    UART2_SendString(" > DHT11    : PB6 (Data pin)\r\n");
    UART2_SendString(" > HC-SR04  : PA6 (Trig), PA7 (Echo)\r\n");
    UART2_SendString(" > PIR      : PB13 (Input)\r\n");
    UART2_SendString(" > Buzzer   : PA9 (Output)\r\n");

    UART2_SendString("-----------------------------\r\n");
    UART2_SendString("Sensors Used:\r\n");
    UART2_SendString(" DHT11      : Temperature & Humidity Sensor\r\n");
    UART2_SendString(" HC-SR04    : Ultrasonic Distance Measuring Sensor\r\n");
    UART2_SendString(" HC-SR501   : Pyroelectric Infrared Motion Detection Sensor\r\n");

    UART2_SendString("-----------------------------\r\n");
    UART2_SendString("Author      : Sandeep\r\n");
    UART2_SendString("=============================\r\n");
}

