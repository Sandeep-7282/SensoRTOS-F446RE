
#ifndef INC_DRIVERS_SSD1306_H_
#define INC_DRIVERS_SSD1306_H_
#include "stdint.h"

void ssd1306_init(void);
void ssd1306_clear(void);
void ssd1306_send_command(uint8_t cmd);
void ssd1306_send_data(uint8_t data);
void ssd1306_set_cursor(uint8_t x, uint8_t page);
void ssd1306_draw_char(uint8_t x, uint8_t page, char c);
void ssd1306_draw_string(uint8_t x, uint8_t page, const char *str);
void ssd1306_display_sensor_data(const char *line1, const char *line2);

#endif /* INC_DRIVERS_SSD1306_H_ */
