// RPG-OS Quest Header
#ifndef QUEST_H
#define QUEST_H

#include "types.h"

#define MAX_QUESTS 16
#define MAX_QUEST_NAME_LEN 64

typedef struct {
    char name[MAX_QUEST_NAME_LEN];
    uint32_t xp_reward;
    uint8_t active;
    uint8_t completed;
} quest_t;

// Externe Quest-Funktionen
void quest_init();
void quest_create(const char* name, uint32_t xp_reward);
void quest_activate(const char* name);
void quest_complete(const char* name);
quest_t* quest_find(const char* name);

#endif // QUEST_H
