#!/usr/bin/env python3
"""
RPG-OS - ISO-Image Builder (Python)
"""

import os
import struct

ISO_SIZE = 16 * 1024 * 1024  # 16 MB
BLOCK_SIZE = 2048

def create_iso(output_file, kernel_path):
    """Erstellt ein ISO-Image mit dem Kernel"""
    
    # ISO leeren (16 MB)
    iso = bytearray(ISO_SIZE)
    
    # ISO-Header erstellen
    header = bytearray(2048)
    
    # PVD (Primary Volume Descriptor)
    header[0] = 0x01  # Type
    header[1:6] = b"CD001"  # ID
    header[6] = 0x01  # Version
    
    # System-ID (32 Bytes)
    system_id = b"RPG-OS    "
    header[8:40] = system_id.ljust(32, b'\x00')
    
    # Volume-ID (32 Bytes)
    volume_id = b"RPG_OS_01 "
    header[40:72] = volume_id.ljust(32, b'\x00')
    
    # Gesamtgröße in Blöcken (16 MB / 2048 = 8192)
    blocks = ISO_SIZE // BLOCK_SIZE
    header[84:88] = struct.pack('<I', blocks)  # Little Endian
    header[88:92] = struct.pack('>I', blocks)  # Big Endian
    
    # Header an Position 32768 schreiben
    iso[32768:32768+len(header)] = header
    
    # Kernel-Image einfügen (an Position 64 KB)
    if os.path.exists(kernel_path):
        with open(kernel_path, 'rb') as f:
            kernel_data = f.read()
            offset = 64 * 1024
            iso[offset:offset+len(kernel_data)] = kernel_data
        print(f"Kernel eingeschlossen: {kernel_path} ({len(kernel_data)} Bytes)")
    
    # ISO speichern
    with open(output_file, 'wb') as f:
        f.write(iso)
    
    print(f"ISO-Image erstellt: {output_file}")
    return 0

if __name__ == "__main__":
    import sys
    
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <output.iso> <kernel.bin>")
        sys.exit(1)
    
    create_iso(sys.argv[1], sys.argv[2])
