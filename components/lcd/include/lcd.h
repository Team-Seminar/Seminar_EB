#include <stdint.h>
#ifndef LCD_H
#define LCD_H

void lcd_init(void);
void lcd_clear(void);
void lcd_print(char *str);
void lcd_set(int col, int row);
void lcd_write_byte(uint8_t data);
void lcd_write_4bit(uint8_t data);
void lcd_send(uint8_t data, uint8_t mode);

#endif

