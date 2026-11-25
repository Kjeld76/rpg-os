/**
 * RPG-OS - Quest System im Kernel
 */

#include "quest.h"

static quest_t quests[MAX_QUESTS];
static uint32_t quest_count = 0;

// Hilfsfunktionen
static int strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) { s1++; s2++; }
    return (int)*s1 - (int)*s2;
}

static void strncpy(char* dst, const char* src, size_t n) {
    for (size_t i = 0; i < n && src[i]; i++) {
        dst[i] = src[i];
    }
    if (n > 0) dst[n - 1] = '\0';
}

// Quests initialisieren
void quest_init() {
    for (int i = 0; i < MAX_QUESTS; i++) {
        quests[i].active = 0;
        quests[i].completed = 0;
    }
    quest_count = 0;
}

// Neue Quest erstellen
void quest_create(const char* name, uint32_t xp_reward) {
    if (quest_count < MAX_QUESTS) {
        strncpy(quests[quest_count].name, name, MAX_QUEST_NAME_LEN - 1);
        quests[quest_count].name[MAX_QUEST_NAME_LEN - 1] = '\0';
        quests[quest_count].xp_reward = xp_reward;
        quests[quest_count].active = 1;
        quests[quest_count].completed = 0;
        quest_count++;
    }
}

// Quest aktivieren
void quest_activate(const char* name) {
    quest_t* q = quest_find(name);
    if (q) {
        q->active = 1;
    }
}

// Quest abschließen
void quest_complete(const char* name) {
    quest_t* q = quest_find(name);
    if (q) {
        q->completed = 1;
        q->active = 0;
        // XP hinzufügen (durch xp_add aus xp.c)
        // TODO: xp_add(q->xp_reward);
    }
}

// Quest finden
quest_t* quest_find(const char* name) {
    for (int i = 0; i < quest_count; i++) {
        if (strcmp(quests[i].name, name) == 0) {
            return &quests[i];
        }
    }
    return (quest_t*)0;
}
