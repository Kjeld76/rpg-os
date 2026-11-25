#!/usr/bin/env python3
"""
RPG-OS Kernel Build-System
Verwaltet den Build-Prozess für den Kernel
"""

import os
import sys
import subprocess
from pathlib import Path

# Konfiguration
KERNEL_SRC = Path(__file__).parent / "src" / "kernel"
BUILD_DIR = Path(__file__).parent / "build" / "kernel"
QEMU_TARGET = "x86_64-softmmu"

def ensure_dirs():
    """Stellt sicher, dass alle Verzeichnisse existieren"""
    BUILD_DIR.mkdir(parents=True, exist_ok=True)
    (BUILD_DIR / "objects").mkdir(exist_ok=True)

def check_toolchain():
    """Prüft die benötigten Tools"""
    tools = ["make", "nasm", "gcc", "qemu-system-x86_64"]
    missing = []
    
    for tool in tools:
        try:
            subprocess.run([tool, "--version"], capture_output=True, check=True)
            print(f"✓ {tool} gefunden")
        except (subprocess.CalledProcessError, FileNotFoundError):
            missing.append(tool)
            print(f"✗ {tool} NICHT gefunden")
    
    if missing:
        print(f"\nFehlende Tools: {', '.join(missing)}")
        print("Installiere mit: sudo apt install nasm gcc qemu-system-x86")
        return False
    return True

def compile_boot():
    """Compiliert den Boot-Code"""
    print("Compiliere Boot-Code...")
    boot_file = KERNEL_SRC / "boot.asm"
    if not boot_file.exists():
        print(f"Boot-Datei nicht gefunden: {boot_file}")
        return False
    return True  # Vorläufig

def compile_kernel():
    """Compiliert den Kernel"""
    print("Compiliere Kernel...")
    kernel_c = KERNEL_SRC / "kernel.c"
    if not kernel_c.exists():
        print(f"Kernel-Datei nicht gefunden: {kernel_c}")
        return False
    return True  # Vorläufig

def link_kernel():
    """Linkt den Kernel"""
    print("Linke Kernel...")
    return True

def create_iso():
    """Erstellt ISO-Image"""
    print("Erstelle ISO-Image...")
    return True

def run_qemu():
    """Startet QEMU"""
    print("Starte QEMU...")
    iso_file = BUILD_DIR / "rpg-os.iso"
    if not iso_file.exists():
        print("ISO-Datei nicht gefunden. Führe make iso aus.")
        return False
    return True

def clean():
    """Räumt auf"""
    print("Räume auf...")
    import shutil
    if BUILD_DIR.exists():
        shutil.rmtree(BUILD_DIR)
    print("Fertig.")
    return True

def main():
    """Hauptfunktion"""
    print("="*50)
    print("  RPG-OS Kernel Build-System")
    print("="*50)
    print()

    if len(sys.argv) < 2:
        print("Verwendung: python3 build_kernel.py [boot|kernel|link|iso|run|clean]")
        return

    action = sys.argv[1]
    
    if action == "check":
        check_toolchain()
    elif action == "clean":
        clean()
    elif action == "boot":
        ensure_dirs()
        compile_boot()
    elif action == "kernel":
        ensure_dirs()
        compile_kernel()
    elif action == "link":
        link_kernel()
    elif action == "iso":
        ensure_dirs()
        create_iso()
    elif action == "run":
        ensure_dirs()
        run_qemu()
    else:
        print(f"Unbekannter Befehl: {action}")

if __name__ == "__main__":
    main()
