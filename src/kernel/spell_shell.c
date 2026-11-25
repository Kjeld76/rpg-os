/**
 * RPG-OS - D&D 5e Spell Shell (Zauber-Syntax)
 */

#include "spell_shell.h"
#include "types.h"
#include "display.h"
#include "xp.h"
#include "level.h"
#include "inventory.h"
#include "quest.h"
#include "combat.h"
#include "vfs.h"

// Externe VFS-Funktion
extern void vfs_list();

// Hilfsfunktion: String vergleichen
static int strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) { s1++; s2++; }
    return (int)*s1 - (int)*s2;
}

// Shell initialisieren
void spell_init() {
    display_clear();
    display_puts("RPG-OS Shell v1.0 (D&D 5e)\n");
    display_puts("Zauber: fireball, heal, teleport, light, identify, mend, ruststrike, create_water, cure_wounds, sanctuary\n\n");
    spell_show_prompt();
}

// Prompt anzeigen
void spell_show_prompt() {
    display_puts("\nFaerun> ");
}

// Zauber ausführen
void spell_run_command(const char* cmd) {
    // "fireball" - statt ls
    if (strcmp(cmd, "fireball") == 0) {
        display_puts("=== Magische Inventory ===\n");
        vfs_list();
    }
    // "heal" - statt cat (zeigt Inhalt)
    else if (strcmp(cmd, "heal") == 0) {
        display_puts("Heiltrank: +50 HP\n");
        display_puts("Goldmünzen: 100\n");
        display_puts("Schwert: +10 Angriff\n");
    }
    // "teleport" - statt cd (wechselt "Ort")
    else if (strcmp(cmd, "teleport") == 0) {
        display_puts("Teleportiert nach Waterdeep...\n");
        display_puts("Ort: ");
        display_putc('>');
        display_putc(' ');
        display_puts("/Faerun/Waterdeep");
        display_putc(' ');
    }
    // "light" - statt echo (magisches Licht)
    else if (strcmp(cmd, "light") == 0) {
        display_puts("Lichtball erscheint!\n");
    }
    // "identify" - statt file (Items identifizieren)
    else if (strcmp(cmd, "identify") == 0) {
        display_puts("Identifiziert:\n");
        display_puts("  Schwert: +10 Angriff (Rarity: Common)\n");
        display_puts("  Heiltrank: +50 HP (Rarity: Uncommon)\n");
        display_puts("  Goldmünzen: 100 (Rarity: Common)\n");
    }
    // "mend" - statt touch (Items reparieren)
    else if (strcmp(cmd, "mend") == 0) {
        display_puts("Schwert repariert!\n");
        display_puts("Zustand: 100%\n");
    }
    // "ruststrike" - statt rm (Items zerstören)
    else if (strcmp(cmd, "ruststrike") == 0) {
        display_puts("Items wurden vernichtet!\n");
    }
    // "create_water" - statt mkdir (Orte erschaffen)
    else if (strcmp(cmd, "create_water") == 0) {
        display_puts("Wasserquelle erschaffen!\n");
    }
    // "cure_wounds" - statt chmod (HP heilen)
    else if (strcmp(cmd, "cure_wounds") == 0) {
        display_puts("Heilung gewährt: +100 HP\n");
    }
    // "sanctuary" - statt chmod -r (Schutz)
    else if (strcmp(cmd, "sanctuary") == 0) {
        display_puts("Schutzschild aktiviert!\n");
    }
    // "help" - verfügbare Zauber anzeigen
    else if (strcmp(cmd, "help") == 0) {
        display_puts("Verfügbare Zauber:\n");
        display_puts("  fireball      - Liste der Items zeigen (ls)\n");
        display_puts("  heal          - Item-Inhalt anzeigen (cat)\n");
        display_puts("  teleport      - Ort wechseln (cd)\n");
        display_puts("  light         - Nachricht ausgeben (echo)\n");
        display_puts("  identify      - Items identifizieren (file)\n");
        display_puts("  mend          - Items reparieren (touch)\n");
        display_puts("  ruststrike    - Items zerstören (rm)\n");
        display_puts("  create_water  - Ordner erstellen (mkdir)\n");
        display_puts("  cure_wounds   - HP heilen (chmod)\n");
        display_puts("  sanctuary     - Schutz aktivieren (chmod -r)\n");
        display_puts("  xp            - XP-Status anzeigen\n");
        display_puts("  level         - Level anzeigen\n");
        display_puts("  inventory     - Inventar anzeigen\n");
        display_puts("  quest         - Quests anzeigen\n");
        display_puts("  combat        - Kampf-Status anzeigen\n");
        display_puts("  clear         - Screen leeren\n");
        display_puts("  exit          - Shell verlassen\n");
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
        display_puts("Inventar:\n");
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
        display_puts("RPG-OS verlassen...\n");
    }
    else {
        display_puts("Unbekannter Zauber: ");
        display_puts(cmd);
        display_puts("\n");
    }
}
