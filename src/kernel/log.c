/**
 * RPG-OS - Logging System
 */

#include "types.h"
#include "display.h"

// Log-Puffer
#define LOG_BUFFER_SIZE 1024
static char log_buffer[LOG_BUFFER_SIZE];
static uint32_t log_pos = 0;

// Log-Flag
static int logging_enabled = 1;

// Hilfsfunktion: String kopieren
static void strcopy(char* dst, const char* src) {
    while (*src) { *dst++ = *src++; }
    *dst = '\0';
}

// Hilfsfunktion: Stringlänge
static size_t strlen(const char* str) {
    size_t len = 0;
    while (*str++) len++;
    return len;
}

// Log-Nachricht schreiben
void log_write(const char* msg) {
    if (!logging_enabled) return;
    
    // Nachricht in Log-Puffer schreiben
    strcopy(&log_buffer[log_pos], msg);
    log_pos += strlen(msg);
    
    // Nachricht auch auf Screen ausgeben
    display_puts(msg);
}

// Log-Nachricht mit Format
void log_printf(const char* fmt, ...) {
    if (!logging_enabled) return;
    
    // Einfache Implementierung ohne variadische Argumente
    display_puts(fmt);
}

// Log leeren
void log_clear() {
    log_pos = 0;
    for (int i = 0; i < LOG_BUFFER_SIZE; i++) {
        log_buffer[i] = 0;
    }
}

// Log-Status
int log_is_enabled() {
    return logging_enabled;
}

void log_enable() {
    logging_enabled = 1;
}

void log_disable() {
    logging_enabled = 0;
}

// Initialisierung
void log_init() {
    log_clear();
    log_write("Log-System initialisiert\n");
}
