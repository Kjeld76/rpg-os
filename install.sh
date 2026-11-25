#!/bin/bash
# RPG-OS Install-Script

set -e

echo "=== RPG-OS Installation ==="
echo ""

# Abhängigkeiten prüfen
echo "Prüfe Abhängigkeiten..."
python3 --version
make --version

# Python-Abhängigkeiten installieren
echo ""
echo "Installiere Python-Pakete..."
pip install -e . --quiet

# System vorbereiten
echo ""
echo "Bereite System vor..."
make bootstrap

echo ""
echo "=== Installation Complete ==="
echo ""
echo "Verwende 'rpg-os' für den Start"
