// RPG-OS Kernel mit VFS und Drivers
#include "types.h"
#include "vfs.h"

// Externe Funktionen
extern void keyboard_init();
extern void keyboard_handler();
extern char keyboard_read_char();
extern int keyboard_has_input();

extern void display_init();
extern void display_putc(char c);
extern void display_puts(const char* str);
extern void display_clear();
extern void display_put_decimal(uint32_t num);

extern void init_interrupts();
extern void enable_interrupts();
extern void log_init();

extern void xp_init();
extern void level_init();
extern void inventory_init();
extern void quest_init();
extern void combat_init();
extern void spell_init();

// Screen-Adresse
#define SCREEN ((uint8_t*)SCREEN_BASE)

// Hilfsfunktionen
void memset(void* ptr, uint8_t value, size_t len) {
    uint8_t* p = (uint8_t*)ptr;
    for (size_t i = 0; i < len; i++) {
        p[i] = value;
    }
}

void memcpy(void* dst, const void* src, size_t len) {
    uint8_t* d = (uint8_t*)dst;
    const uint8_t* s = (const uint8_t*)src;
    for (size_t i = 0; i < len; i++) {
        d[i] = s[i];
    }
}

int strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) { s1++; s2++; }
    return (int)*s1 - (int)*s2;
}

void strcpy(char* dst, const char* src) {
    while (*src) { *dst++ = *src++; }
    *dst = '\0';
}

int snprintf(char* buf, size_t size, const char* fmt, ...) {
    const char* str = fmt;
    size_t i = 0;
    while (*str && i < size - 1) {
        buf[i++] = *str++;
    }
    buf[i] = '\0';
    return i;
}

void puts(const char* str) {
    display_puts(str);
}

// VFS-Code
#define BLOCK_SIZE 512
#define MAX_FILES 64
#define MAX_PATH_LEN 64

typedef enum {
    FILE_TYPE_DIR = 0,
    FILE_TYPE_REG = 1,
    FILE_TYPE_XP = 2,
} file_type_t;

typedef struct {
    char name[MAX_PATH_LEN];
    file_type_t type;
    uint32_t size;
    uint8_t data[BLOCK_SIZE];
    uint8_t valid;
} vfs_file_t;

static vfs_file_t vfs_files[MAX_FILES];
static uint32_t vfs_count = 0;
static uint32_t vfs_total_xp = 0;
static uint32_t vfs_current_level = 1;

vfs_file_t* vfs_find(const char* path) {
    for (int i = 0; i < vfs_count; i++) {
        if (vfs_files[i].valid && strcmp(vfs_files[i].name, path) == 0) {
            return &vfs_files[i];
        }
    }
    return (vfs_file_t*)0;
}

void vfs_add_xp(uint32_t amount) {
    vfs_total_xp += amount;
    vfs_file_t* file = vfs_find("xp/current");
    if (file) {
        snprintf((char*)file->data, BLOCK_SIZE, "%u", vfs_total_xp);
    }
}

void vfs_update_level() {
    vfs_current_level++;
    vfs_file_t* file = vfs_find("levels/current");
    if (file) {
        snprintf((char*)file->data, BLOCK_SIZE, "Level %u", vfs_current_level);
    }
}

void vfs_init() {
    memset(vfs_files, 0, sizeof(vfs_files));
    vfs_count = 0;
    
    strcpy(vfs_files[0].name, "levels");
    vfs_files[0].type = FILE_TYPE_DIR;
    vfs_files[0].valid = 1;
    
    strcpy(vfs_files[1].name, "inventory");
    vfs_files[1].type = FILE_TYPE_DIR;
    vfs_files[1].valid = 1;
    
    strcpy(vfs_files[2].name, "quests");
    vfs_files[2].type = FILE_TYPE_DIR;
    vfs_files[2].valid = 1;
    
    strcpy(vfs_files[3].name, "xp");
    vfs_files[3].type = FILE_TYPE_DIR;
    vfs_files[3].valid = 1;
    
    strcpy(vfs_files[4].name, "xp/current");
    vfs_files[4].type = FILE_TYPE_XP;
    vfs_files[4].valid = 1;
    snprintf((char*)vfs_files[4].data, BLOCK_SIZE, "0");
    
    strcpy(vfs_files[5].name, "levels/current");
    vfs_files[5].type = FILE_TYPE_XP;
    vfs_files[5].valid = 1;
    snprintf((char*)vfs_files[5].data, BLOCK_SIZE, "Level 1");
    
    vfs_count = 6;
}

uint32_t vfs_get_total_xp() {
    return vfs_total_xp;
}

uint32_t vfs_get_current_level() {
    return vfs_current_level;
}

void vfs_list() {
    display_puts("=== VFS Directory ===\n");
    for (int i = 0; i < vfs_count; i++) {
        if (vfs_files[i].valid) {
            const char* type_str = "[REG]";
            if (vfs_files[i].type == FILE_TYPE_DIR) type_str = "[DIR]";
            display_putc(' ');
            display_putc(' ');
            display_puts(type_str);
            display_putc(' ');
            display_puts(vfs_files[i].name);
            display_putc('\n');
        }
    }
    char buf[64];
    snprintf(buf, sizeof(buf), "Total XP: %u\n", vfs_total_xp);
    display_puts(buf);
    snprintf(buf, sizeof(buf), "Current Level: %u\n", vfs_current_level);
    display_puts(buf);
}

// System-Start
void kernel_main() {
    display_clear();
    display_puts("RPG-OS Kernel gestartet!\n\n");
    
    // Initialisierung
    display_init();
    keyboard_init();
    init_interrupts();
    log_init();
    enable_interrupts();
    
    // RPG-Systeme initialisieren
    xp_init();
    level_init();
    inventory_init();
    quest_init();
    combat_init();
    
    // VFS initialisieren
    vfs_init();
    vfs_add_xp(100);
    vfs_update_level();
    
    // VFS anzeigen
    vfs_list();
    
    // D&D Shell starten
    spell_init();
    
    // Endlosschleife mit Shell
    display_puts("\nDruecke Taste zum Testen (ESC zum Beenden)\n");
    
    while (1) {
        if (keyboard_has_input()) {
            char c = keyboard_read_char();
            if (c == 0x1B) {  // ESC
                display_puts("\nShutdown...\n");
                __asm__ ("hlt");
                break;
            }
            display_putc(c);
        }
        __asm__ ("hlt");
    }
}
