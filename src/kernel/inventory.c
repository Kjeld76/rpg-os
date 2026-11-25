/**
 * RPG-OS - Inventory System im Kernel
 */

#include "inventory.h"

static inventory_item_t inventory[MAX_ITEMS];
static uint32_t inventory_count = 0;

// Hilfsfunktion: String vergleichen
static int strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) { s1++; s2++; }
    return (int)*s1 - (int)*s2;
}

// Hilfsfunktion: String kopieren
static void strncpy(char* dst, const char* src, size_t n) {
    for (size_t i = 0; i < n && src[i]; i++) {
        dst[i] = src[i];
    }
    if (n > 0) dst[n - 1] = '\0';
}

// Inventar initialisieren
void inventory_init() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        inventory[i].valid = 0;
        inventory[i].count = 0;
    }
    inventory_count = 0;
}

// Item hinzufügen
void inventory_add_item(const char* name, uint32_t count) {
    // Suchen ob Item schon existiert
    for (int i = 0; i < inventory_count; i++) {
        if (inventory[i].valid && strcmp(inventory[i].name, name) == 0) {
            inventory[i].count += count;
            return;
        }
    }
    
    // Neues Item anlegen
    if (inventory_count < MAX_ITEMS) {
        strncpy(inventory[inventory_count].name, name, MAX_NAME_LEN - 1);
        inventory[inventory_count].name[MAX_NAME_LEN - 1] = '\0';
        inventory[inventory_count].count = count;
        inventory[inventory_count].valid = 1;
        inventory_count++;
    }
}

// Item entfernen
void inventory_remove_item(const char* name, uint32_t count) {
    for (int i = 0; i < inventory_count; i++) {
        if (inventory[i].valid && strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].count >= count) {
                inventory[i].count -= count;
            } else {
                inventory[i].count = 0;
            }
            return;
        }
    }
}

// Item-Anzahl abrufen
uint32_t inventory_get_item_count(const char* name) {
    for (int i = 0; i < inventory_count; i++) {
        if (inventory[i].valid && strcmp(inventory[i].name, name) == 0) {
            return inventory[i].count;
        }
    }
    return 0;
}
