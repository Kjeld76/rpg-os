"""
Tests für das Level-System
"""

import unittest
from src.levels.main import LevelSystem, create_level_system


class TestLevelSystem(unittest.TestCase):
    """Tests für Level-System"""
    
    def test_create_level_system(self):
        """Testet Erstellung"""
        system = create_level_system()
        self.assertEqual(system.level, 1)
        self.assertEqual(system.xp, 0)
        self.assertEqual(system.xp_required, 100)
    
    def test_add_xp(self):
        """Testet XP hinzufügen"""
        system = create_level_system()
        
        result = system.add_xp(50)
        self.assertFalse(result)
        self.assertEqual(system.xp, 50)
        
        result = system.add_xp(50)
        self.assertTrue(result)
        self.assertEqual(system.level, 2)
        self.assertEqual(system.xp, 0)
        self.assertEqual(system.xp_required, 150)
    
    def test_level_progress(self):
        """Testet Fortschritt"""
        system = create_level_system()
        
        system.add_xp(50)
        self.assertEqual(system.get_progress(), 0.5)


if __name__ == "__main__":
    unittest.main()
