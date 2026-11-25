# RPG-OS Releases

## v1.0.0-alpha (25.11.2026)

### Download
- **rpg-os-v1.0.0-alpha.iso** (16 MB) - Komplettes ISO-Image für QEMU/VM

### Features
- D&D 5e Zauber-Befehle (fireball, heal, teleport, etc.)
- Forgotten Realms Pfade (/Faerun/, /Waterdeep/)
- 22.9 KB Kernel mit VFS, USB, GRUB-Multiboot
- 16 MB ISO-Image bereit für QEMU/VM

### Installation
1. ISO herunterladen
2. Mit QEMU testen: `qemu-system-x86_64 -cdrom rpg-os-v1.0.0-alpha.iso`
3. Oder in VirtualBox/VMware verwenden

### Shell-Beispiel
```
Faerun> fireball
Faerun> identify Schwert
Faerun> teleport Waterdeep
```

---

## Future Releases

### v1.0.0-beta
- USB-Maus-Unterstützung
- Network-Stack
- Dateisystem-Integration

### v1.0.0
- stabile Version
- vollständige Dokumentation

---

**Hinweis:** ISO-Images sind auch im GitHub Releases-Bereich verfügbar:
https://github.com/Kjeld76/rpg-os/releases