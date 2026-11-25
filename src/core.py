#!/usr/bin/env python3
"""
RPG-OS Core
Hauptanwendung für RPG-OS
"""

import sys
import os

# src/ zum Path hinzufügen
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from src.levels.main import create_level_system
from src.inventory.main import create_inventory
from src.quests.main import create_quest_log
from src.combat.main import Combatant
from src.utils.helpers import format_xp, clamp


def main():
    """Startet RPG-OS"""
    print("="*50)
    print("  RPG-OS Core v0.1.0")
    print("="*50)
    print()
    
    # Systeme initialisieren
    levels = create_level_system()
    inventory = create_inventory(max_slots=10, max_weight=100.0)
    quest_log = create_quest_log()
    
    print("Systeme initialisiert:")
    print(f"  - Level-System (Level {levels.level})")
    print(f"  - Inventar (Slots: 0/10)")
    print(f"  - Quest-Log (0 Quests)")
    print()
    
    # Test-Kampf
    print("Test-Kampf...")
    hero = Combatant(name="Held", hp=100, attack=15, defense=5)
    enemy = Combatant(name="Gegner", hp=80, attack=12, defense=3)
    
    print(f"  {hero.name} vs {enemy.name}")
    print(f"  XP für Sieg: 100")
    print()
    
    print("✓ RPG-OS gestartet!")
    print()
    print("Verfügbare Module:")
    print("  levels   - XP und Level-System")
    print("  inventory - Gegenstände")
    print("  quests   - Aufgaben")
    print("  combat   - Kampfsystem")
    print()
    print("Nächster Schritt: make build")


if __name__ == "__main__":
    main()
