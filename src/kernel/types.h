// RPG-OS Kernel Type Definitions
#ifndef TYPES_H
#define TYPES_H

// Grundlegende Typen
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int64_t;

typedef unsigned long size_t;
typedef long ssize_t;

typedef unsigned long uintptr_t;
typedef long intptr_t;

#define true 1
#define false 0

// Screen-Adresse (VGA Text Mode)
#define SCREEN_BASE 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// PS/2 Controller Ports
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define PIC1_CMD     0x20
#define PIC1_DATA    0x21
#define PIC2_CMD     0xA0
#define PIC2_DATA    0xA1
#define PIC_EOI      0x20

// Hilfsfunktionen: Port-Eingabe/Ausgabe
static inline uint8_t inb(uint16_t port) {
    uint8_t value;
    __asm__ volatile ("inb %1, %0" : "=a"(value) : "dN"(port));
    return value;
}

static inline void outb(uint16_t port, uint8_t value) {
    __asm__ volatile ("outb %0, %1" : : "a"(value), "dN"(port));
}

// 32-bit Port-Eingabe/Ausgabe
static inline uint32_t inl(uint16_t port) {
    uint32_t value;
    __asm__ volatile ("inl %1, %0" : "=a"(value) : "dN"(port));
    return value;
}

static inline void outl(uint16_t port, uint32_t value) {
    __asm__ volatile ("outl %0, %1" : : "a"(value), "dN"(port));
}

#endif // TYPES_H
