"""
Tests für das Quest-System
"""

import unittest
from src.quests.main import Quest, QuestLog, create_quest_log


class TestQuestSystem(unittest.TestCase):
    """Tests für Quest-System"""
    
    def test_create_quest(self):
        """Testet Erstellung"""
        quest = Quest(id="q1", name="Test Quest", description="Beschreibung", xp_reward=50)
        
        self.assertEqual(quest.id, "q1")
        self.assertEqual(quest.name, "Test Quest")
        self.assertEqual(quest.completed, False)
    
    def test_create_quest_log(self):
        """Testet Erstellung"""
        log = create_quest_log()
        self.assertEqual(len(log.quests), 0)
        self.assertEqual(len(log.completed_quests), 0)
    
    def test_add_quest(self):
        """Testet Quest hinzufügen"""
        log = create_quest_log()
        quest = Quest(id="q1", name="Test Quest", xp_reward=50)
        
        result = log.add_quest(quest)
        
        self.assertTrue(result)
        self.assertEqual(len(log.quests), 1)
    
    def test_complete_quest(self):
        """Testet Quest abschließen"""
        log = create_quest_log()
        quest = Quest(id="q1", name="Test Quest", xp_reward=50)
        log.add_quest(quest)
        
        result = log.complete_quest("q1")
        
        self.assertTrue(result)
        self.assertTrue(quest.completed)
        self.assertIn("q1", log.completed_quests)
        self.assertEqual(log.get_xp_total(), 50)
    
    def test_xp_calculation(self):
        """Testet XP-Berechnung"""
        log = create_quest_log()
        
        quest1 = Quest(id="q1", name="Quest 1", xp_reward=50)
        quest2 = Quest(id="q2", name="Quest 2", xp_reward=100)
        
        log.add_quest(quest1)
        log.add_quest(quest2)
        log.complete_quest("q1")
        log.complete_quest("q2")
        
        self.assertEqual(log.get_xp_total(), 150)


if __name__ == "__main__":
    unittest.main()
