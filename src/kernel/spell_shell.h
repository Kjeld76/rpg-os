// RPG-OS - D&D 5e Shell Header
#ifndef SPELL_SHELL_H
#define SPELL_SHELL_H

#include "types.h"

// Zauber-Befehle (D&D 5e)
void spell_init();
void spell_run_command(const char* cmd);
void spell_show_prompt();

// Forgotten Realms Pfade
#define FAERUN_PATH "/Faerun/"
#define WATERDEEP_PATH "/Faerun/Waterdeep/"
#define NEVERWINTER_PATH "/Faerun/Neverwinter/"
#define CALIMSHAN_PATH "/Faerun/Calimshan/"
#define ARCTUS_PATH "/Arctus/"

#endif // SPELL_SHELL_H
