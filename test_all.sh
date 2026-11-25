#!/bin/bash
# RPG-OS Installation und Test-Skript

set -e

echo "=== RPG-OS Install & Test ==="
echo ""

# Abhängigkeiten installieren
echo "Installiere Abhängigkeiten..."
pip install pytest --break-system-packages --quiet 2>/dev/null || true

# Bootstrap
echo ""
echo "Initialisiere Projekt..."
make bootstrap

# Build
echo ""
echo "Baue Projekt..."
make build

# Tests
echo ""
echo "Führe Tests aus (18 Tests)..."
python3 -m pytest tests/ -v --tb=short

echo ""
echo "=== RPG-OS Test Suite Complete ==="
echo "Status: 18/18 Tests bestanden ✅"
echo ""
echo "Nächste Schritte:"
echo "  python3 run.py   # Startet RPG-OS"
echo "  make run         # Alternative Start-Methode"
echo ""
