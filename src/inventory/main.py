"""
RPG-OS Inventory System
Verwaltet das Inventar mit Slots und Gewicht
"""

from dataclasses import dataclass, field
from typing import Dict, List, Optional


@dataclass
class Item:
    """Ein Item im Inventar"""
    name: str
    weight: float
    quantity: int = 1
    description: str = ""
    
    def total_weight(self) -> float:
        """Gesamtgewicht des Items"""
        return self.weight * self.quantity


@dataclass
class Inventory:
    """Inventar-Verwaltung"""
    max_slots: int = 10
    max_weight: float = 100.0
    items: Dict[str, Item] = field(default_factory=dict)
    
    def add_item(self, item: Item) -> bool:
        """Fügt ein Item hinzu"""
        current_weight = sum(i.total_weight() for i in self.items.values())
        
        if len(self.items) >= self.max_slots:
            print("❌ Inventar voll (Slots)")
            return False
            
        if current_weight + item.total_weight() > self.max_weight:
            print("❌ Inventar voll (Gewicht)")
            return False
            
        if item.name in self.items:
            self.items[item.name].quantity += item.quantity
        else:
            self.items[item.name] = item
            
        print(f"✓ {item.name} hinzugefügt")
        return True
    
    def remove_item(self, name: str, quantity: int = 1) -> bool:
        """Entfernt ein Item"""
        if name not in self.items:
            print(f"❌ {name} nicht im Inventar")
            return False
            
        item = self.items[name]
        if item.quantity < quantity:
            print(f"❌ Nicht genug {name} (haben: {item.quantity})")
            return False
            
        item.quantity -= quantity
        
        if item.quantity <= 0:
            del self.items[name]
            
        print(f"✓ {quantity}x {name} entfernt")
        return True
    
    def list_items(self):
        """Zeigt alle Items an"""
        if not self.items:
            print("Inventar ist leer")
            return
            
        print("\n=== Inventar ===")
        total_weight = sum(i.total_weight() for i in self.items.values())
        
        for name, item in self.items.items():
            print(f"  {name} x{item.quantity} ({item.total_weight()}kg)")
            
        print(f"\nGesamtgewicht: {total_weight}/{self.max_weight}kg")
        print(f"Slots: {len(self.items)}/{self.max_slots}")
    
    def get_total_weight(self) -> float:
        """Gesamtgewicht des Inventars"""
        return sum(i.total_weight() for i in self.items.values())


def create_inventory(max_slots: int = 10, max_weight: float = 100.0) -> Inventory:
    """Erstellt ein neues Inventar"""
    return Inventory(max_slots=max_slots, max_weight=max_weight)


def main():
    """Testet das Inventar-System"""
    print("Testing Inventory-System...")
    
    inv = create_inventory(max_slots=5, max_weight=20.0)
    
    # Test Items hinzufügen
    sword = Item(name="Schwert", weight=3.0, quantity=1, description="Ein scharfes Schwert")
    shield = Item(name="Schild", weight=5.0, quantity=1, description="Holzschild")
    
    inv.add_item(sword)
    inv.add_item(shield)
    
    inv.list_items()
    
    # Test entfernen
    inv.remove_item("Schwert", 1)
    inv.list_items()
    
    print("✓ Inventar-System Test abgeschlossen!")


if __name__ == "__main__":
    main()
