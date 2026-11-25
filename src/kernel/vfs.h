// RPG-OS VFS Header
#ifndef VFS_H
#define VFS_H

#include "types.h"

// Externe VFS-Funktionen
uint32_t vfs_get_total_xp();
uint32_t vfs_get_current_level();
void vfs_add_xp(uint32_t amount);
void vfs_update_level();
void vfs_init();

#endif // VFS_H
