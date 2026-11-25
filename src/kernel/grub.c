/**
 * RPG-OS - GRUB-Multiboot Setup
 */

#include "multiboot.h"

// Multiboot-Header
#define MULTIBOOT_HEADER_MAGIC 0x1BADB002
#define MULTIBOOT_HEADER_FLAGS (MULTIBOOT_HEADER_PAGE_ALIGN | MULTIBOOT_HEADER_VIDEO_MODE)

multiboot_header_t multiboot_header __attribute__((section(".multiboot"))) = {
    .magic = MULTIBOOT_HEADER_MAGIC,
    .flags = MULTIBOOT_HEADER_FLAGS,
    .checksum = -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS),
    .header_addr = (uint32_t)&multiboot_header,
    .load_addr = 0x100000,
    .load_end_addr = 0x200000,
    .bss_end_addr = 0x210000,
    .entry_addr = 0x100000  // _start Adresse (im Start-Code definiert)
};
