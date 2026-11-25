"""
RPG-OS Combat System
Verwaltet Kampf-Logik bei Ressourcenkonflikten
"""

from dataclasses import dataclass
import random


@dataclass
class Combatant:
    """Ein Kampfteilnehmer"""
    name: str
    hp: int = 100
    attack: int = 10
    defense: int = 5
    
    def is_alive(self) -> bool:
        """Prüft ob noch am Leben"""
        return self.hp > 0
    
    def take_damage(self, damage: int) -> int:
        """Fügt Schaden zu (mit Verteidigung)"""
        actual_damage = max(1, damage - self.defense)
        self.hp -= actual_damage
        return actual_damage
    
    def attack_target(self, target: "Combatant") -> int:
        """Angreifen eines Ziels"""
        damage = random.randint(max(1, self.attack // 2), self.attack)
        actual = target.take_damage(damage)
        return actual


def calculate_win_chance(attacker: Combatant, defender: Combatant) -> float:
    """Berechnet Siegeswahrscheinlichkeit"""
    # Einfache Formel basierend auf Stats
    attack_power = attacker.attack * 2 - defender.defense
    win_chance = min(0.95, max(0.05, 0.5 + (attack_power - 5) / 20))
    return win_chance


def combat_round(attacker: Combatant, defender: Combatant) -> dict:
    """Führt eine Kampfrunde aus"""
    damage_dealt = attacker.attack_target(defender)
    
    return {
        "attacker": attacker.name,
        "defender": defender.name,
        "damage": damage_dealt,
        "attacker_hp": attacker.hp,
        "defender_hp": defender.hp
    }


def resolve_combat(combatants: list[Combatant]) -> Combatant | None:
    """Löst einen Kampf mit mehreren Teilnehmern"""
    if len(combatants) < 2:
        return combatants[0] if combatants else None
    
    alive = combatants.copy()
    
    while len(alive) > 1:
        # Zufälliger Angriff
        attacker = random.choice(alive)
        defenders = [c for c in alive if c != attacker]
        defender = random.choice(defenders)
        
        combat_round(attacker, defender)
        
        # Tote entfernen
        alive = [c for c in alive if c.is_alive()]
    
    return alive[0] if alive else None


def main():
    """Testet das Kampfsystem"""
    print("Testing Combat-System...")
    
    # Test 1: Einzelkampf
    hero = Combatant(name="Held", hp=100, attack=15, defense=5)
    enemy = Combatant(name="Gegner", hp=80, attack=12, defense=3)
    
    print(f"\nStart: {hero.name} HP: {hero.hp} | {enemy.name} HP: {enemy.hp}")
    
    while hero.is_alive() and enemy.is_alive():
        damage = combat_round(hero, enemy)
        print(f"  {damage['attacker']} trifft {damage['defender']} für {damage['damage']} Schaden")
        print(f"  HP: {hero.name}: {hero.hp} | {enemy.name}: {enemy.hp}")
    
    winner = hero if hero.is_alive() else enemy
    print(f"\n🏆 Gewinner: {winner.name}")
    
    # Test 2: Siegeswahrscheinlichkeit
    chance = calculate_win_chance(hero, enemy)
    print(f"\nSiegeswahrscheinlichkeit: {chance*100:.1f}%")
    
    print("✓ Kampf-System Test abgeschlossen!")


if __name__ == "__main__":
    main()
