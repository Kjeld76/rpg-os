// RPG-OS Display Header
#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

// Externe Funktionen
void display_init();
void display_putc(char c);
void display_puts(const char* str);
void display_clear();
void display_gotoxy(uint8_t x, uint8_t y);
void display_put_decimal(uint32_t num);

#endif // DISPLAY_H
