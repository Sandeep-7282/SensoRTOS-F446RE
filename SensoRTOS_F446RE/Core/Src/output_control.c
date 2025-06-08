/*
 * output_control.c
 *
 *  Created on: May 20, 2025
 *      Author: sandeep
 */
#include "output_control.h"

volatile OutputTarget dht11_output = OUTPUT_UART;
volatile OutputTarget hcsr04_output = OUTPUT_UART;
volatile OutputTarget hcsr501_output   = OUTPUT_UART;

