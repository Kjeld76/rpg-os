// RPG-OS Level Header
#ifndef LEVEL_H
#define LEVEL_H

#include "types.h"

// Externe Level-Funktionen
void level_init();
void level_up();
uint32_t level_get();
void level_set(uint32_t level);

#endif // LEVEL_H
