#!/usr/bin/env python3
"""
RPG-OS - Vollständiges Start-Skript
"""

import sys
import os

# Verzeichnis wechseln
os.chdir(os.path.dirname(os.path.abspath(__file__)))

# src/ zum Path hinzufügen
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "src"))

from src.core import main

if __name__ == "__main__":
    main()
