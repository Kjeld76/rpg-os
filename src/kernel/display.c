/**
 * RPG-OS - Display Driver (VGA Text Mode)
 */

#include "types.h"
#include "display.h"

// VGA Text Mode Speicher
static volatile uint8_t* vga = (volatile uint8_t*)SCREEN_BASE;

// Cursor-Position
static uint8_t cursor_x = 0;
static uint8_t cursor_y = 0;

// Hilfsfunktionen
static void update_cursor() {
    uint16_t position = cursor_y * SCREEN_WIDTH + cursor_x;
    
    // Cursor Position setzen (CRT Control Registers)
    __asm__ volatile (
        "movw $0x3D4, %%dx\n\t"
        "movb $0x0F, %%al\n\t"
        "outb %%al, (%%dx)\n\t"
        "movb %0, %%al\n\t"
        "outb %%al, (%%dx)\n\t"
        "movb $0x0E, %%al\n\t"
        "outb %%al, (%%dx)\n\t"
        "movb %1, %%al\n\t"
        "outb %%al, (%%dx)"
        : 
        : "r"((uint8_t)(position & 0xFF)), "r"((uint8_t)(position >> 8))
        : "ax", "dx"
    );
}

static void scroll() {
    if (cursor_y >= SCREEN_HEIGHT) {
        // Screen nach oben scrollen
        for (int y = 1; y < SCREEN_HEIGHT; y++) {
            for (int x = 0; x < SCREEN_WIDTH; x++) {
                vga[(y - 1) * SCREEN_WIDTH * 2 + x * 2] = 
                    vga[y * SCREEN_WIDTH * 2 + x * 2];
                vga[(y - 1) * SCREEN_WIDTH * 2 + x * 2 + 1] = 
                    vga[y * SCREEN_WIDTH * 2 + x * 2 + 1];
            }
        }
        
        // Letzte Zeile leeren
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            vga[(SCREEN_HEIGHT - 1) * SCREEN_WIDTH * 2 + x * 2] = ' ';
            vga[(SCREEN_HEIGHT - 1) * SCREEN_WIDTH * 2 + x * 2 + 1] = 0x07;
        }
        
        cursor_y = SCREEN_HEIGHT - 1;
    }
}

// Zeichen ausgeben
void display_putc(char c) {
    switch (c) {
        case '\n':
            cursor_x = 0;
            cursor_y++;
            break;
        case '\r':
            cursor_x = 0;
            break;
        case '\t':
            cursor_x = (cursor_x + 8) & ~7;
            break;
        case '\b':
            if (cursor_x > 0) {
                cursor_x--;
                vga[cursor_y * SCREEN_WIDTH * 2 + cursor_x * 2] = ' ';
            }
            break;
        default:
            vga[cursor_y * SCREEN_WIDTH * 2 + cursor_x * 2] = c;
            vga[cursor_y * SCREEN_WIDTH * 2 + cursor_x * 2 + 1] = 0x07;
            cursor_x++;
            break;
    }
    
    if (cursor_x >= SCREEN_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }
    
    scroll();
    update_cursor();
}

// String ausgeben
void display_puts(const char* str) {
    while (*str) {
        display_putc(*str++);
    }
}

// Screen leeren
void display_clear() {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            vga[y * SCREEN_WIDTH * 2 + x * 2] = ' ';
            vga[y * SCREEN_WIDTH * 2 + x * 2 + 1] = 0x07;
        }
    }
    cursor_x = 0;
    cursor_y = 0;
    update_cursor();
}

// Cursor positionieren
void display_gotoxy(uint8_t x, uint8_t y) {
    cursor_x = x;
    cursor_y = y;
    update_cursor();
}

// Dezimalzahl ausgeben
void display_put_decimal(uint32_t num) {
    if (num == 0) {
        display_putc('0');
        return;
    }
    
    char buf[16];
    int i = 0;
    while (num > 0) {
        buf[i++] = '0' + (num % 10);
        num /= 10;
    }
    
    while (i > 0) {
        display_putc(buf[--i]);
    }
}

// Initialisierung
void display_init() {
    display_clear();
}
