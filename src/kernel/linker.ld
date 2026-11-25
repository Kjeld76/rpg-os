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
