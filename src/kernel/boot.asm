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
