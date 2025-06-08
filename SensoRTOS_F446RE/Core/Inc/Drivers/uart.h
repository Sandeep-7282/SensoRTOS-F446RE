
#ifndef INC_DRIVERS_UART_H_
#define INC_DRIVERS_UART_H_

void UART2_Init(void);
void UART2_SendChar(char c);
void UART2_SendString(const char *str);
char UART2_ReceiveChar(void);

#endif /* INC_DRIVERS_UART_H_ */
