#pragma once
#include <stdint.h>
// For authors refer to implementation file

void LCD_init(uint8_t addr, uint8_t dataPin, uint8_t clockPin, uint8_t cols, uint8_t rows);
void LCD_setCursor(uint8_t col, uint8_t row);
void LCD_home(void);
void LCD_clearScreen(void);
void LCD_writeChar(char c);
void LCD_writeStr(char* str);
void LCD_writeCustomChar(uint8_t c);

void LCD_createCustomChar(uint8_t location, uint8_t charmap[]);
