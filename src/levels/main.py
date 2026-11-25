"""
RPG-OS Core
Kern-Modul für XP- und Level-Verwaltung
"""

from dataclasses import dataclass
from typing import Optional


@dataclass
class LevelSystem:
    """Verwaltet Level und XP"""
    level: int = 1
    xp: int = 0
    xp_required: int = 100
    
    def add_xp(self, amount: int) -> bool:
        """Fügt XP hinzu und prüft Level-Aufstieg"""
        self.xp += amount
        
        if self.xp >= self.xp_required:
            self.level_up()
            return True
        return False
    
    def level_up(self):
        """Level-Aufstieg"""
        self.level += 1
        self.xp_required = int(self.xp_required * 1.5)
        self.xp = 0
        print(f"🎉 Level aufgestiegen! Level {self.level} erreicht!")
    
    def get_progress(self) -> float:
        """Gibt XP-Fortschritt zurück (0.0-1.0)"""
        return self.xp / self.xp_required if self.xp_required > 0 else 1.0


def create_level_system() -> LevelSystem:
    """Erstellt ein neues Level-System"""
    return LevelSystem()


def main():
    """Testet das Level-System"""
    print("Testing Level-System...")
    
    system = create_level_system()
    
    # Test XP hinzufügen
    print(f"Start: Level {system.level}, XP: {system.xp}/{system.xp_required}")
    
    system.add_xp(50)
    print(f"Nach 50 XP: Level {system.level}, XP: {system.xp}/{system.xp_required}")
    
    system.add_xp(50)
    print(f"Nach weiteren 50 XP: Level {system.level}, XP: {system.xp}/{system.xp_required}")
    
    print("✓ Level-System Test abgeschlossen!")


if __name__ == "__main__":
    main()
