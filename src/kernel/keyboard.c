/**
 * RPG-OS - Keyboard Driver (PS/2)
 */

#include "keyboard.h"

// Tasten-Zustand
static uint8_t keyboard_buffer[256];
static uint8_t buffer_head = 0;
static uint8_t buffer_tail = 0;

// Zeichen aus Tastatur lesen
char keyboard_read_char() {
    if (buffer_head == buffer_tail) {
        return 0;  // Kein Zeichen verfügbar
    }
    
    uint8_t scancode = keyboard_buffer[buffer_tail];
    buffer_tail = (buffer_tail + 1) % 256;
    
    // Einfache Scan Code zu ASCII Konvertierung
    switch (scancode) {
        case 0x02: return '1';
        case 0x03: return '2';
        case 0x39: return ' ';
        default: return 0;
    }
}

// Tastatur initialisieren
void keyboard_init() {
    buffer_head = 0;
    buffer_tail = 0;
}

// Tastatur-Status abfragen
int keyboard_has_input() {
    return (buffer_head != buffer_tail);
}
