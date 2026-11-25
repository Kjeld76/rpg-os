/**
 * RPG-OS - Shell im Kernel
 */

#include "shell.h"
#include "types.h"
#include "display.h"
#include "xp.h"
#include "level.h"
#include "inventory.h"
#include "quest.h"
#include "combat.h"

// Hilfsfunktion: String vergleichen
static int strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) { s1++; s2++; }
    return (int)*s1 - (int)*s2;
}

// Shell initialisieren
void shell_init() {
    display_clear();
    display_puts("RPG-OS Shell v0.1\n");
    display_puts("Befehle: help, xp, level, inventory, quest, combat, clear, exit\n\n");
    shell_show_prompt();
}

// Prompt anzeigen
void shell_show_prompt() {
    display_puts("\nRPG> ");
}

// Befehl ausführen
void shell_run_command(const char* cmd) {
    // "help"
    if (strcmp(cmd, "help") == 0) {
        display_puts("Verfügbare Befehle:\n");
        display_puts("  help      - Diese Hilfe anzeigen\n");
        display_puts("  xp        - XP-Status anzeigen\n");
        display_puts("  level     - Level anzeigen\n");
        display_puts("  inventory - Inventar anzeigen\n");
        display_puts("  quest     - Quests anzeigen\n");
        display_puts("  combat    - Kampf-Status anzeigen\n");
        display_puts("  clear     - Screen leeren\n");
        display_puts("  exit      - Shell verlassen\n");
    }
    // "xp"
    else if (strcmp(cmd, "xp") == 0) {
        display_puts("XP: ");
        display_put_decimal(xp_get_total());
        display_puts(" / ");
        display_put_decimal(xp_get_to_next());
        display_puts("\n");
    }
    // "level"
    else if (strcmp(cmd, "level") == 0) {
        display_puts("Level: ");
        display_put_decimal(level_get());
        display_puts("\n");
    }
    // "inventory"
    else if (strcmp(cmd, "inventory") == 0) {
        display_puts("Inventar (3 Items):\n");
        display_puts("  Schwert x1\n");
        display_puts("  Heiltrank x5\n");
        display_puts("  Goldmünzen x100\n");
    }
    // "quest"
    else if (strcmp(cmd, "quest") == 0) {
        display_puts("Aktive Quests:\n");
        display_puts("  1. Drachen besiegen (500 XP)\n");
        display_puts("  2. Altes Kloster erforschen (200 XP)\n");
    }
    // "combat"
    else if (strcmp(cmd, "combat") == 0) {
        display_puts("Kampf-Status:\n");
        display_puts("  Spieler HP: ");
        display_put_decimal(combat_get_player_hp());
        display_puts(" / ");
        display_put_decimal(combat_get_player_hp());
        display_puts("\n");
        display_puts("  Gegner HP: ");
        display_put_decimal(combat_get_enemy_hp());
        display_puts(" / ");
        display_put_decimal(combat_get_enemy_hp());
        display_puts("\n");
    }
    // "clear"
    else if (strcmp(cmd, "clear") == 0) {
        display_clear();
    }
    // "exit"
    else if (strcmp(cmd, "exit") == 0) {
        display_puts("Shell verlassen...\n");
    }
    else {
        display_puts("Unbekannter Befehl: ");
        display_puts(cmd);
        display_puts("\n");
    }
}
