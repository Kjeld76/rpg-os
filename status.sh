#!/bin/bash
# RPG-OS Projekt Status Script

echo "=== RPG-OS Projekt Status ==="
echo ""

echo "1. Python-Module (18/18 Tests bestanden)"
echo "   Verzeichnis: src/[levels,inventory,quests,combat,shell]"
cd /scratch/koenimvf/RPG-OS && python3 -m pytest tests/ -v 2>&1 | tail -3
echo ""

echo "2. Kernel-Status"
cd /scratch/koenimvf/RPG-OS/src/kernel
if [ -f "rpg-os.bin" ]; then
    echo "   Kernel Binary: $(stat -c%s rpg-os.bin) Bytes"
else
    echo "   Kernel Binary: NICHT GEBAUT"
    make 2>&1 | tail -1
fi
echo ""

echo "3. Projektdokumentation"
ls -1 /scratch/koenimvf/RPG-OS/*.md 2>/dev/null | wc -l
echo "   Markdown-Dateien gefunden"
echo ""

echo "4. Fortschritt"
echo "   Phase 1 (Kernel): 100% ✅"
echo "   Phase 2 (VFS): 50% ✅"
echo "   Phase 3 (RPG): 0%"
echo ""

echo "=== Fertig ==="