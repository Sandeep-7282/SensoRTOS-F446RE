/*
 * i2c.c
 *
 *  Created on: May 29, 2025
 *      Author: sandeep
 */

#include "stm32f4xx.h"

void I2C1_init(void) {
    // Enable clock for GPIOB and I2C1
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

    // Configure PB8 (SCL) and PB9 (SDA) as Alternate Function
    GPIOB->MODER &= ~(0xF << (8 * 2));
    GPIOB->MODER |=  (0xA << (8 * 2)); // Alternate Function

    GPIOB->AFR[1] |= (4 << ((8 - 8) * 4)); // AF4 for I2C1_SCL
    GPIOB->AFR[1] |= (4 << ((9 - 8) * 4)); // AF4 for I2C1_SDA

    GPIOB->OTYPER |= (1 << 8) | (1 << 9); // Open-drain
    GPIOB->OSPEEDR |= (0xF << (8 * 2));   // High speed
    GPIOB->PUPDR |= (0x5 << (8 * 2));     // Pull-up

    // Reset and configure I2C1
    I2C1->CR1 &= ~I2C_CR1_PE; // Disable I2C before config

    I2C1->CR2 = 42; // PCLK1 freq = 42 MHz
    I2C1->CCR = 210; // Standard mode 100kHz
    I2C1->TRISE = 43; // TRISE = freq + 1

    I2C1->CR1 |= I2C_CR1_PE; // Enable I2C
}

void I2C1_start(uint8_t address, uint8_t direction) {
    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB));

    I2C1->DR = (address << 1) | direction;
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    (void)I2C1->SR2;
}

void I2C1_write(uint8_t data) {
    while (!(I2C1->SR1 & I2C_SR1_TXE));
    I2C1->DR = data;
    while (!(I2C1->SR1 & I2C_SR1_BTF));
}

void I2C1_stop(void) {
    I2C1->CR1 |= I2C_CR1_STOP;
}

