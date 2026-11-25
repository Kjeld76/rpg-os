// RPG-OS Combat Header
#ifndef COMBAT_H
#define COMBAT_H

#include "types.h"

// Externe Combat-Funktionen
void combat_init();
uint32_t combat_player_attack();
uint32_t combat_enemy_attack();
uint32_t combat_get_player_hp();
uint32_t combat_get_enemy_hp();
int combat_player_alive();
int combat_enemy_alive();
void combat_set_player_stats(uint32_t hp, uint32_t max_hp, uint32_t attack, uint32_t defense);
void combat_set_enemy_stats(uint32_t hp, uint32_t max_hp, uint32_t attack, uint32_t defense);

#endif // COMBAT_H
