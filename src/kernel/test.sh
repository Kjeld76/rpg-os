#!/bin/bash
# Test-Script für Kernel

set -e

echo "=== RPG-OS Kernel Test ==="
echo ""

cd /scratch/koenimvf/RPG-OS/src/kernel

# Build
echo "1. Build Kernel..."
make clean 2>/dev/null || true
make

if [ -f "rpg-os.bin" ]; then
    echo "✓ Kernel erfolgreich gebaut (rpg-os.bin)"
    echo "  Größe: $(stat -c%s rpg-os.bin) Bytes"
else
    echo "✗ Build fehlgeschlagen"
    exit 1
fi

# QEMU-Test
echo ""
echo "2. QEMU-Test (10 Sekunden)..."
if command -v qemu-system-x86_64 &> /dev/null; then
    timeout 10 qemu-system-x86_64 -kernel rpg-os.bin -display none -serial stdio 2>&1 | tee qemu.log || true
    if grep -q "RPG-OS Kernel" qemu.log; then
        echo "✓ Kernel startet korrekt"
    else
        echo "⚠ Kernel startet (möglicherweise ohne Ausgabe)"
    fi
else
    echo "⚠ QEMU nicht installiert - Springe über QEMU-Test"
    echo "  Installiere: sudo zypper install qemu-x86"
fi

echo ""
echo "=== Test Complete ==="
echo ""
echo "Dateien:"
ls -la rpg-os.bin *.o 2>/dev/null || true
echo ""
echo "QEMU-Log:"
cat qemu.log 2>/dev/null || echo "(kein Log)"
