/*
 * gpio.c
 *
 *  Created on: May 21, 2025
 *      Author: sandeep
 */
#include "stm32f4xx.h"

void GPIO_Init(void) {
    // Enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // PA5: LED, PA9: Buzzer
    GPIOA->MODER &= ~(0x3 << (2 * 5));  // Clear mode for PA5
    GPIOA->MODER |=  (0x1 << (2 * 5));  // Set PA5 as output

    GPIOA->MODER &= ~(0x3 << (2 * 9));  // Clear mode for PA9
    GPIOA->MODER |=  (0x1 << (2 * 9));  // Set PA9 as output

    GPIOA->OTYPER &= ~(1 << 5); // PA5: push-pull
    GPIOA->OTYPER &= ~(1 << 9); // PA9: push-pull

    GPIOA->OSPEEDR |= (0x3 << (2 * 5)); // PA5: high speed
    GPIOA->OSPEEDR |= (0x3 << (2 * 9)); // PA9: high speed
}


void LED_Toggle(void) {
    GPIOA->ODR ^= (1 << 5);
}

void Buzzer_On(void) {
    GPIOA->ODR |= (1 << 9);  // Set PA9 high
}

void Buzzer_Off(void) {
    GPIOA->ODR &= ~(1 << 9); // Set PA9 low
}


