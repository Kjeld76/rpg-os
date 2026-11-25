// RPG-OS Multiboot Header
#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include "types.h"

// Multiboot-Konstanten
#define MULTIBOOT_HEADER_MAGIC 0x1BADB002
#define MULTIBOOT_HEADER_PAGE_ALIGN 0x00000001
#define MULTIBOOT_HEADER_VIDEO_MODE 0x00000002
#define MULTIBOOT_HEADER_USE_LOAD_ADDR 0x00010000

// Multiboot-Header
typedef struct {
    uint32_t magic;
    uint32_t flags;
    uint32_t checksum;
    uint32_t header_addr;
    uint32_t load_addr;
    uint32_t load_end_addr;
    uint32_t bss_end_addr;
    uint32_t entry_addr;
} __attribute__((packed)) multiboot_header_t;

// Multiboot-Info-Struktur
typedef struct {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    uint32_t syms[4];
    uint32_t mmap_length;
    uint32_t mmap_addr;
    uint32_t drives_length;
    uint32_t drives_addr;
    uint32_t config_table;
    uint32_t boot_loader_name;
    uint32_t apm_table;
    uint32_t vbe_control_info;
    uint32_t vbe_mode_info;
    uint16_t vbe_mode;
    uint16_t vbe_interface_seg;
    uint16_t vbe_interface_off;
    uint16_t vbe_interface_len;
} __attribute__((packed)) multiboot_info_t;

// Multiboot-Modul
typedef struct {
    uint32_t mod_start;
    uint32_t mod_end;
    uint32_t cmdline;
    uint32_t reserved;
} __attribute__((packed)) multiboot_module_t;

#endif // MULTIBOOT_H
