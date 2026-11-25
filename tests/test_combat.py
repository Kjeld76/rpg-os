"""
Tests für das Kampfsystem
"""

import unittest
from src.combat.main import Combatant, combat_round, calculate_win_chance, resolve_combat


class TestCombatSystem(unittest.TestCase):
    """Tests für Kampfsystem"""
    
    def test_create_combatant(self):
        """Testet Erstellung"""
        combatant = Combatant(name="Held", hp=100, attack=15, defense=5)
        
        self.assertEqual(combatant.name, "Held")
        self.assertEqual(combatant.hp, 100)
        self.assertEqual(combatant.attack, 15)
        self.assertEqual(combatant.defense, 5)
        self.assertTrue(combatant.is_alive())
    
    def test_take_damage(self):
        """Testet Schaden"""
        hero = Combatant(name="Held", hp=100, defense=5)
        damage = hero.take_damage(20)
        
        self.assertEqual(damage, 15)  # 20 - 5 Verteidigung
        self.assertEqual(hero.hp, 85)
    
    def test_attack(self):
        """Testet Angriff"""
        hero = Combatant(name="Held", hp=100, attack=20, defense=5)
        enemy = Combatant(name="Gegner", hp=50, attack=10, defense=2)
        
        damage = hero.attack_target(enemy)
        
        # Angriff minimal: Attack/2 - Defense (min 1)
        min_damage = max(1, hero.attack // 2 - enemy.defense)
        max_damage = hero.attack - enemy.defense
        self.assertTrue(min_damage <= damage <= max_damage)
        self.assertTrue(enemy.is_alive())
    
    def test_win_chance(self):
        """Testet Siegeswahrscheinlichkeit"""
        strong = Combatant(name="Stark", hp=100, attack=30, defense=10)
        weak = Combatant(name="Schwach", hp=50, attack=5, defense=1)
        
        chance = calculate_win_chance(strong, weak)
        
        self.assertGreater(chance, 0.7)
    
    def test_combat_round(self):
        """Testet Kampfrunde"""
        hero = Combatant(name="Held", hp=100, attack=20, defense=5)
        enemy = Combatant(name="Gegner", hp=50, attack=10, defense=2)
        
        result = combat_round(hero, enemy)
        
        self.assertEqual(result["attacker"], "Held")
        self.assertEqual(result["defender"], "Gegner")
        self.assertIn("damage", result)


if __name__ == "__main__":
    unittest.main()
