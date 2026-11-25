// RPG-OS Syscall Header
#ifndef SYSCALL_H
#define SYSCALL_H

#include "types.h"

// System Call Numbers
#define SYS_READ  0
#define SYS_WRITE 1
#define SYS_OPEN  2
#define SYS_CLOSE 3
#define SYS_GET_XP 4
#define SYS_GET_LEVEL 5

// Externe Funktionen
void syscall_handler(uint32_t syscall_num, uint32_t arg1, uint32_t arg2, uint32_t arg3);

#endif // SYSCALL_H
