/**
 * RPG-OS - Level System im Kernel
 */

#include "types.h"

// Level-Status
static uint32_t current_level = 1;

// Level erhöhen
void level_up() {
    current_level++;
}

// Level abrufen
uint32_t level_get() {
    return current_level;
}

// Level setzen
void level_set(uint32_t level) {
    if (level > 0) {
        current_level = level;
    }
}

// Level initialisieren
void level_init() {
    current_level = 1;
}
