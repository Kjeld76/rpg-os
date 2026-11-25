/**
 * RPG-OS - Combat System im Kernel
 */

#include "types.h"

typedef struct {
    uint32_t hp;
    uint32_t max_hp;
    uint32_t attack;
    uint32_t defense;
} entity_t;

static entity_t player = {100, 100, 10, 5};
static entity_t enemy = {50, 50, 8, 3};

// Kampf initialisieren
void combat_init() {
    player.hp = player.max_hp;
    enemy.hp = enemy.max_hp;
}

// Spieler-Schaden berechnen
uint32_t combat_player_attack() {
    uint32_t damage = player.attack;
    enemy.hp -= damage;
    return damage;
}

// Gegner-Schaden berechnen
uint32_t combat_enemy_attack() {
    uint32_t damage = enemy.attack - player.defense;
    if (damage < 1) damage = 1;
    player.hp -= damage;
    return damage;
}

// Spieler-HP abrufen
uint32_t combat_get_player_hp() {
    return player.hp;
}

// Gegner-HP abrufen
uint32_t combat_get_enemy_hp() {
    return enemy.hp;
}

// Spieler-Status
int combat_player_alive() {
    return player.hp > 0;
}

// Gegner-Status
int combat_enemy_alive() {
    return enemy.hp > 0;
}

// Spieler-Status zurücksetzen
void combat_set_player_stats(uint32_t hp, uint32_t max_hp, uint32_t attack, uint32_t defense) {
    player.hp = hp;
    player.max_hp = max_hp;
    player.attack = attack;
    player.defense = defense;
}

// Gegner-Status zurücksetzen
void combat_set_enemy_stats(uint32_t hp, uint32_t max_hp, uint32_t attack, uint32_t defense) {
    enemy.hp = hp;
    enemy.max_hp = max_hp;
    enemy.attack = attack;
    enemy.defense = defense;
}
