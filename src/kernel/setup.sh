#!/bin/bash
# RPG-OS Kernel Initialisierung

set -e

echo "=== RPG-OS Kernel Setup ==="

# Verzeichnisse erstellen
mkdir -p build/kernel/objects
mkdir -p build/kernel/iso

# Boot-Code (ASM)
cat > boot.asm << 'EOF'
; RPG-OS Boot-Loader
; Multiboot-kompatibel

MBALIGN  equ  1<<0
MBMEM    equ  1<<1
MBFLAGS  equ  MBALIGN | MBMEM

MAGIC    equ  0x1BADB002
CHECKSUM equ  -(MAGIC + MBFLAGS)

section .text
global _start
extern kernel_main
bits 32

_start:
    ; Multiboot Header
    dd MAGIC
    dd MBFLAGS
    dd CHECKSUM
    
    ; Stack initialisieren
    mov esp, _stack + 4096
    
    ; Kernel main aufrufen
    call kernel_main
    
    ; Halted
    cli
    hlt

section .bss
align 4
_stack:
    resb 4096
EOF

# Kernel-Code (C)
cat > kernel.c << 'EOF'
// RPG-OS Kernel
#include <stdint.h>
#include <stddef.h>

// Screen-Adresse
#define SCREEN ((uint8_t*)0xB8000)

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

void puts(const char* str) {
    uint8_t* screen = SCREEN;
    while (*str) {
        *screen++ = *str++;
        *screen++ = 0x07;
    }
}

void clear_screen() {
    memset(SCREEN, 0, 80 * 25 * 2);
}

// Haupt-Funktion (wird von Boot-Code aufgerufen)
void kernel_main(void) {
    clear_screen();
    puts("RPG-OS Kernel gestartet!\n");
    puts("Level: 1 | XP: 0/100\n");
    
    while (1) {
        __asm__ ("hlt");
    }
}
EOF

# Linker-Script
cat > linker.ld << 'EOF'
/* RPG-OS Linker Script */
OUTPUT_FORMAT(elf32-i386)
ENTRY(_start)

SECTIONS
{
    . = 0x100000;
    
    .text : {
        *(.multiboot)
        *(.text)
    }
    
    .data : {
        *(.data)
    }
    
    .bss : {
        *(COMMON)
        *(.bss)
    }
}
EOF

# Makefile für Kernel
cat > Makefile << 'MAKEFILE'
# RPG-OS Kernel Makefile

CC = gcc
CFLAGS = -m32 -ffreestanding -fno-stack-protector -fno-builtin -Wall
AS = nasm
ASFLAGS = -f elf32
LD = ld
LDFLAGS = -m elf_i386

SRC = $(wildcard *.c *.asm)
OBJ = $(patsubst %.c,%.o,$(filter %.c,$(SRC))) $(patsubst %.asm,%.o,$(filter %.asm,$(SRC)))

all: rpg-os.iso

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

rpg-os.bin: $(OBJ) linker.ld
	$(LD) $(LDFLAGS) -T linker.ld -o $@ $(OBJ)

rpg-os.iso: rpg-os.bin
	mkdir -p iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set root=(cd0)' >> iso/boot/grub/grub.cfg
	echo 'multiboot /boot/rpg-os.bin' >> iso/boot/grub/grub.cfg
	grub-mkrescue -o $@ iso 2>/dev/null || echo "grub-mkrescue not found"

qemu: rpg-os.iso
	qemu-system-x86_64 -cdrom $<

clean:
	rm -rf iso rpg-os.bin rpg-os.iso *.o

.PHONY: all clean qemu
MAKEFILE

echo ""
echo "=== Kernel Setup Complete ==="
echo ""
echo "Dateien erstellt:"
echo "  boot.asm   - Boot-Loader (ASM)"
echo "  kernel.c   - Kernel (C)"
echo "  linker.ld  - Linker-Script"
echo "  Makefile   - Build-System"
echo ""
echo "Bauen:"
echo "  make"
