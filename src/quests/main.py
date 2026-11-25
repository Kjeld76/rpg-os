"""
RPG-OS Quest System
Verwaltet Quests und Aufgaben
"""

from dataclasses import dataclass, field
from datetime import datetime
from typing import Dict, List, Optional


@dataclass
class Quest:
    """Eine Quest/Aufgabe"""
    id: str
    name: str
    description: str = ""
    xp_reward: int = 50
    completed: bool = False
    created_at: datetime = field(default_factory=datetime.now)
    
    def complete(self) -> bool:
        """Markiert die Quest als abgeschlossen"""
        self.completed = True
        print(f"✅ Quest '{self.name}' abgeschlossen!")
        return True


@dataclass
class QuestLog:
    """Quest-Verwaltung"""
    quests: Dict[str, Quest] = field(default_factory=dict)
    completed_quests: List[str] = field(default_factory=list)
    
    def add_quest(self, quest: Quest) -> bool:
        """Fügt eine Quest hinzu"""
        if quest.id in self.quests:
            print(f"❌ Quest '{quest.id}' existiert bereits")
            return False
            
        self.quests[quest.id] = quest
        print(f"✅ Quest '{quest.name}' hinzugefügt")
        return True
    
    def complete_quest(self, quest_id: str) -> bool:
        """Markiert eine Quest als abgeschlossen"""
        if quest_id not in self.quests:
            print(f"❌ Quest '{quest_id}' nicht gefunden")
            return False
            
        quest = self.quests[quest_id]
        quest.complete()
        self.completed_quests.append(quest_id)
        return True
    
    def list_quests(self):
        """Zeigt alle Quests an"""
        if not self.quests:
            print("Keine Quests verfügbar")
            return
            
        print("\n=== Quest-Log ===")
        active = [q for q in self.quests.values() if not q.completed]
        completed = [q for q in self.quests.values() if q.completed]
        
        if active:
            print("\nAktive Quests:")
            for quest in active:
                print(f"  • {quest.name} (XP: {quest.xp_reward})")
        
        if completed:
            print(f"\nAbgeschlossene Quests: {len(completed)}")
    
    def get_xp_total(self) -> int:
        """Gesamt-XP aus abgeschlossenen Quests"""
        return sum(self.quests[q].xp_reward for q in self.completed_quests)


def create_quest_log() -> QuestLog:
    """Erstellt ein neues Quest-Log"""
    return QuestLog()


def main():
    """Testet das Quest-System"""
    print("Testing Quest-System...")
    
    log = create_quest_log()
    
    # Test Quests hinzufügen
    quest1 = Quest(id="q1", name="Erstes Mal", description="Erste Schritte", xp_reward=50)
    quest2 = Quest(id="q2", name="Build Test", description="Projekt bauen", xp_reward=100)
    
    log.add_quest(quest1)
    log.add_quest(quest2)
    
    log.list_quests()
    
    # Test Quest abschließen
    log.complete_quest("q1")
    log.list_quests()
    
    print(f" Gesamt-XP: {log.get_xp_total()}")
    print("✓ Quest-System Test abgeschlossen!")


if __name__ == "__main__":
    main()
