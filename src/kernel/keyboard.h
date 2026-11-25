// RPG-OS Keyboard Header
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "types.h"

// PS/2 Controller Ports
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

// Hilfsfunktionen
void keyboard_init();
void keyboard_handler();
char keyboard_read_char();
int keyboard_has_input();

#endif // KEYBOARD_H
