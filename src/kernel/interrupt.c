/**
 * RPG-OS - Interrupt Handler
 */

#include "types.h"
#include "display.h"

// Interrupt-Nummern
#define IRQ_TIMER      0
#define IRQ_KEYBOARD   1
#define IRQ_CASCADE    2
#define IRQ_SERIAL2    3
#define IRQ_SERIAL1    4
#define IRQ_PARALLEL2  5
#define IRQ_FLOPPY     6
#define IRQ_PARALLEL1  7
#define IRQ_RTC        8
#define IRQ_AUX        12
#define IRQ_FPU        13
#define IRQ_PRIMARY    14
#define IRQ_SECONDARY  15

// Interrupt-Flag
static volatile int interrupts_enabled = 1;

// Interrupt-Handler Tabelle
typedef void (*irq_handler_t)();
irq_handler_t irq_handlers[16] = {0};

// IRQ maske (initial: alle IRQs deaktiviert)
static uint8_t irq_mask = 0xFF;

// PIC-Kontroll-Ports
#define PIC1_CMD     0x20
#define PIC1_DATA    0x21
#define PIC2_CMD     0xA0
#define PIC2_DATA    0xA1
#define PIC_EOI      0x20

// Initialisierung
void init_pic() {
    // ICW1 - Start Initialization
    outb(PIC1_CMD, 0x11);
    outb(PIC2_CMD, 0x11);
    
    // ICW2 - Vector Offsets
    outb(PIC1_DATA, 0x20);  // IRQ0-7 -> INT 0x20-0x27
    outb(PIC2_DATA, 0x28);  // IRQ8-15 -> INT 0x28-0x2F
    
    // ICW3 - Cascade
    outb(PIC1_DATA, 0x04);
    outb(PIC2_DATA, 0x02);
    
    // ICW4 - Environment
    outb(PIC1_DATA, 0x01);
    outb(PIC2_DATA, 0x01);
    
    // Maskieren (initial: alle deaktiviert)
    outb(PIC1_DATA, irq_mask);
    outb(PIC2_DATA, irq_mask);
}

// EOI (End of Interrupt)
void pic_send_eoi(uint8_t irq) {
    if (irq >= 8) {
        outb(PIC2_CMD, PIC_EOI);
    }
    outb(PIC1_CMD, PIC_EOI);
}

// Timer-Interrupt-Handler
void timer_handler() {
    // Hier könnte XP-System aktualisiert werden
    // Für now: nur EOI senden
    pic_send_eoi(IRQ_TIMER);
}

// Keyboard-Interrupt-Handler
void keyboard_handler() {
    // Tastatur-Code einlesen
    uint8_t scancode = inb(KEYBOARD_DATA_PORT);
    
    // EOI senden
    pic_send_eoi(IRQ_KEYBOARD);
}

// Interrupts aktivieren
void enable_interrupts() {
    interrupts_enabled = 1;
    __asm__ ("sti");
}

// Interrupts deaktivieren
void disable_interrupts() {
    interrupts_enabled = 0;
    __asm__ ("cli");
}

// Initialisierung
void init_interrupts() {
    init_pic();
    
    // Handler registrieren
    irq_handlers[IRQ_TIMER] = timer_handler;
    irq_handlers[IRQ_KEYBOARD] = keyboard_handler;
    
    // Timer und Keyboard aktivieren
    irq_mask = 0xFC;  // Nur Timer (0) und Keyboard (1) aktiv
    outb(PIC1_DATA, irq_mask);
}
