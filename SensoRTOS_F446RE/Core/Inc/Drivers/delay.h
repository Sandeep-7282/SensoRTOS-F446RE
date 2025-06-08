
#ifndef INC_DRIVERS_DELAY_H_
#define INC_DRIVERS_DELAY_H_
#include "stdint.h"

void DWT_Init(void);
void delay_us(uint32_t us);

#endif /* INC_DRIVERS_DELAY_H_ */
