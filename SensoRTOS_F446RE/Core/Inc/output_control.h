

#ifndef INC_OUTPUT_CONTROL_H_
#define INC_OUTPUT_CONTROL_H_

typedef enum {
    OUTPUT_UART = 0,
    OUTPUT_OLED
} OutputTarget;

extern volatile OutputTarget dht11_output;
extern volatile OutputTarget hcsr04_output;
extern volatile OutputTarget hcsr501_output;

#endif /* INC_OUTPUT_CONTROL_H_ */
