/*
 * hcsr04.c
 *
 *  Created on: May 28, 2025
 *      Author: sandeep
 */
#include "hcsr04.h"
#include "delay.h"
#include "stdio.h"
// Pins
#define TRIG_PORT GPIOA
#define TRIG_PIN 6

#define ECHO_PORT GPIOA
#define ECHO_PIN 7

#define TRIG_HIGH()  (TRIG_PORT->BSRR = (1U << TRIG_PIN))
#define TRIG_LOW()   (TRIG_PORT->BSRR = (1U << (TRIG_PIN + 16)))

#define ECHO_READ()  ((ECHO_PORT->IDR >> ECHO_PIN) & 0x1)

void HC_SR04_Init(void) {
    // Enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configure PA6 as output (Trig)
    GPIOA->MODER &= ~(3U << (6 * 2));
    GPIOA->MODER |=  (1U << (6 * 2));  // Output mode
    GPIOA->OTYPER &= ~(1U << 6);       // Push-pull
    GPIOA->OSPEEDR |= (3U << (6 * 2)); // High speed
    GPIOA->PUPDR &= ~(3U << (6 * 2));  // No pull-up/down for trig pin

    // Configure PA7 as input (Echo) with internal pull-down
    GPIOA->MODER &= ~(3U << (7 * 2));  // Input mode
    GPIOA->PUPDR &= ~(3U << (7 * 2));  // Clear bits first
    GPIOA->PUPDR |=  (2U << (7 * 2));  // Enable pull-down

    // Set Trig low initially
    GPIOA->BSRR = (1U << (6 + 16));  // Reset PA6
}

uint32_t HC_SR04_ReadDistance(void) {
    uint32_t count = 0;
    uint32_t timeout = 60000; // 60ms timeout (~60,000 us)

    // Trigger pulse: 10 us high
    TRIG_HIGH();
    delay_us(10);
    TRIG_LOW();

    // Wait for echo to go HIGH (start)
    timeout = 60000;
    while (!ECHO_READ()) {
        if (--timeout == 0) return 0; // timeout error
        delay_us(1);
    }
    // Measure pulse width while echo is HIGH
    count = 0;
    timeout = 60000;
    while (ECHO_READ()) {
        if (++count >= timeout) return 0; // timeout error
        delay_us(1);
    }

    // Distance in cm = pulse duration(us) / 58
    return count / 58;
}



