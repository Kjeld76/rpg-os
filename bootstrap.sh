#!/bin/bash
# RPG-OS Bootstrap Script
# Initialisiert das Projekt

set -e

echo "=== RPG-OS Bootstrap (v0.1.0) ==="
echo "Project: /scratch/koenimvf/RPG-OS"
echo ""

# Verzeichnisse erstellen
echo "Creating directory structure..."
mkdir -p src/kernel
mkdir -p src/shell
mkdir -p src/system
mkdir -p src/inventory
mkdir -p src/quests
mkdir -p src/levels
mkdir -p src/combat
mkdir -p src/utils
mkdir -p tests/unit
mkdir -p tests/integration

# Empty files für Git
touch src/kernel/.gitkeep
touch src/shell/.gitkeep
touch src/system/.gitkeep
touch src/inventory/.gitkeep
touch src/quests/.gitkeep
touch src/levels/.gitkeep
touch src/combat/.gitkeep
touch src/utils/.gitkeep
touch tests/.gitkeep

# Bootstrap complete
echo ""
echo "✓ Directory structure created"
echo "✓ .gitkeep files added"
echo ""
echo "=== Bootstrap Complete ==="
echo ""
echo "Next steps:"
echo "  make build   - Build the project"
echo "  make test    - Run test suite"
echo "  make run     - Start RPG-OS"
echo ""
echo "Happy Coding! 🎮"
