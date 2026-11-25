// RPG-OS Log Header
#ifndef LOG_H
#define LOG_H

#include "types.h"

// Externe Funktionen
void log_init();
void log_write(const char* msg);
void log_printf(const char* fmt, ...);
void log_clear();
int log_is_enabled();
void log_enable();
void log_disable();

#endif // LOG_H
