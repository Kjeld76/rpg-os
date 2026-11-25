# RPG-OS Kernel Makefile

CC = gcc
CFLAGS = -m32 -ffreestanding -fno-stack-protector -fno-builtin -Wall -nostdinc -fno-pic
LD = ld
LDFLAGS = -m elf_i386

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

# Exclude mkiso.c from kernel build
SRC_KERNEL = $(filter-out mkiso.c,$(SRC))
OBJ_KERNEL = $(patsubst %.c,%.o,$(SRC_KERNEL))

all: rpg-os.bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

rpg-os.bin: $(OBJ_KERNEL) linker.ld
	$(LD) $(LDFLAGS) -T linker.ld -o $@ $(OBJ_KERNEL)

qemu: rpg-os.bin
	qemu-system-x86_64 -kernel $<

iso: rpg-os.bin
	python3 mkiso.py rpg-os.iso rpg-os.bin
	echo "ISO erstellt: rpg-os.iso"
	echo "Test mit: qemu-system-x86_64 -cdrom rpg-os.iso"

clean:
	rm -f *.o rpg-os.bin rpg-os.iso test.iso

.PHONY: all clean qemu iso
