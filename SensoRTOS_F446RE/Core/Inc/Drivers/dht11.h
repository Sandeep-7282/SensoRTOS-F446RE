
#ifndef INC_DRIVERS_DHT11_H_
#define INC_DRIVERS_DHT11_H_
#include "stdint.h"

// Define structure to hold DHT11 sensor data
typedef struct {
    uint8_t temperature;
    uint8_t humidity;
    uint8_t checksum;
    uint8_t valid;   // 1 = valid reading, 0 = invalid
} DHT11_Data;

void DHT11_Init(void);
uint8_t DHT11_Read(DHT11_Data *data);

#endif /* INC_DRIVERS_DHT11_H_ */
