/*
 * dht11.c
 *
 *  Created on: May 27, 2025
 *      Author: sandeep
 */
#include "stm32f4xx.h"
#include "dht11.h"
#include "delay.h"

// DHT11 connected to PB6
#define DHT11_PORT      GPIOB
#define DHT11_PIN       6

#define DHT11_INPUT()   do { \
    DHT11_PORT->MODER &= ~(3U << (DHT11_PIN * 2)); \
    DHT11_PORT->PUPDR &= ~(3U << (DHT11_PIN * 2)); \
    DHT11_PORT->PUPDR |=  (1U << (DHT11_PIN * 2)); /* Pull-up */ \
} while (0)

#define DHT11_OUTPUT()  do { \
    DHT11_PORT->MODER &= ~(3U << (DHT11_PIN * 2)); \
    DHT11_PORT->MODER |=  (1U << (DHT11_PIN * 2)); /* Output mode */ \
    DHT11_PORT->OTYPER &= ~(1U << DHT11_PIN);      /* Push-pull */ \
    DHT11_PORT->OSPEEDR |= (3U << (DHT11_PIN * 2));\
} while (0)

#define DHT11_WRITE_LOW()    (DHT11_PORT->BSRR = (1U << (DHT11_PIN + 16)))
#define DHT11_WRITE_HIGH()   (DHT11_PORT->BSRR = (1U << DHT11_PIN))
#define DHT11_READ()         ((DHT11_PORT->IDR >> DHT11_PIN) & 0x1)

// ---------------------- DHT11 Protocol -------------------------

void DHT11_Init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; // Enable GPIOB clock
    DWT_Init(); // Enable DWT cycle counter
    DHT11_OUTPUT();
    DHT11_WRITE_HIGH();
}

static uint8_t DHT11_CheckResponse(void) {
    uint8_t response = 0;
    delay_us(40);
    if (!DHT11_READ()) {
        delay_us(80);
        if (DHT11_READ()) response = 1;
        delay_us(50);
    }
    return response;
}

static uint8_t DHT11_ReadByte(void) {
    uint8_t i, byte = 0;
    for (i = 0; i < 8; i++) {
        while (!DHT11_READ());      // Wait for HIGH
        delay_us(40);               // Wait ~40us
        if (DHT11_READ()) {
            byte |= (1 << (7 - i));
            while (DHT11_READ());  // Wait for LOW
        }
    }
    return byte;
}

uint8_t DHT11_Read(DHT11_Data *data) {
    uint8_t hum_int, hum_dec, temp_int, temp_dec, chk;

    DHT11_OUTPUT();
    DHT11_WRITE_LOW();
    delay_us(18000); // Start signal (>18ms)
    DHT11_WRITE_HIGH();
    delay_us(30);
    DHT11_INPUT();

    if (DHT11_CheckResponse()) {
        hum_int = DHT11_ReadByte();
        hum_dec = DHT11_ReadByte();
        temp_int = DHT11_ReadByte();
        temp_dec = DHT11_ReadByte();
        chk = DHT11_ReadByte();

        data->temperature = temp_int;
        data->humidity = hum_int;
        data->checksum = chk;
        data->valid = ((hum_int + hum_dec + temp_int + temp_dec) == chk) ? 1 : 0;
        return 1;
    }
    data->valid = 0;
    return 0;
}


