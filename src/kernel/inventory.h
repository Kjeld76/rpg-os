// RPG-OS Inventory Header
#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"

#define MAX_ITEMS 32
#define MAX_NAME_LEN 32

typedef struct {
    char name[MAX_NAME_LEN];
    uint32_t count;
    uint8_t valid;
} inventory_item_t;

// Externe Inventar-Funktionen
void inventory_init();
void inventory_add_item(const char* name, uint32_t count);
void inventory_remove_item(const char* name, uint32_t count);
uint32_t inventory_get_item_count(const char* name);

#endif // INVENTORY_H
