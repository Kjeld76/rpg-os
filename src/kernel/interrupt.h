// RPG-OS Interrupt Header
#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "types.h"

// Externe Funktionen
void init_interrupts();
void enable_interrupts();
void disable_interrupts();
void pic_send_eoi(uint8_t irq);

// Interrupt-Handler
void timer_handler();
void keyboard_handler();

#endif // INTERRUPT_H
