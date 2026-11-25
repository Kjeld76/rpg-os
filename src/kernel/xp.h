// RPG-OS XP Header
#ifndef XP_H
#define XP_H

#include "types.h"

// Externe XP-Funktionen
void xp_init();
void xp_add(uint32_t amount);
uint32_t xp_get_total();
uint32_t xp_get_level();
uint32_t xp_get_to_next();
void xp_reset();

#endif // XP_H
