/**
 * RPG-OS - XP System im Kernel
 */

#include "types.h"

// XP-Status
static uint32_t total_xp = 0;
static uint32_t current_level = 1;
static uint32_t xp_to_next_level = 100;

// XP hinzufügen
void xp_add(uint32_t amount) {
    total_xp += amount;
    
    // Level-Up Check
    if (total_xp >= xp_to_next_level) {
        current_level++;
        xp_to_next_level = current_level * 100;
    }
}

// XP abrufen
uint32_t xp_get_total() {
    return total_xp;
}

// Level abrufen
uint32_t xp_get_level() {
    return current_level;
}

// XP zu nächsten Level
uint32_t xp_get_to_next() {
    return xp_to_next_level;
}

// XP zurücksetzen
void xp_reset() {
    total_xp = 0;
    current_level = 1;
    xp_to_next_level = 100;
}

// XP initialisieren
void xp_init() {
    xp_reset();
}
