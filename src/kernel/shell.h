// RPG-OS Shell Header
#ifndef SHELL_H
#define SHELL_H

#include "types.h"

// Externe Shell-Funktionen
void shell_init();
void shell_run_command(const char* cmd);
void shell_show_prompt();

#endif // SHELL_H
