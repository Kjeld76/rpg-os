"""
Tests für das Inventar-System
"""

import unittest
from src.inventory.main import Inventory, Item, create_inventory


class TestInventory(unittest.TestCase):
    """Tests für Inventar-System"""
    
    def test_create_inventory(self):
        """Testet Erstellung"""
        inv = create_inventory()
        self.assertEqual(inv.max_slots, 10)
        self.assertEqual(inv.max_weight, 100.0)
        self.assertEqual(len(inv.items), 0)
    
    def test_add_item(self):
        """Testet Item hinzufügen"""
        inv = create_inventory(max_slots=3, max_weight=20.0)
        
        sword = Item(name="Schwert", weight=5.0, quantity=1)
        result = inv.add_item(sword)
        
        self.assertTrue(result)
        self.assertEqual(len(inv.items), 1)
        self.assertEqual(inv.get_total_weight(), 5.0)
    
    def test_item_quantity(self):
        """Testet Item-Menge"""
        inv = create_inventory()
        
        sword = Item(name="Schwert", weight=5.0, quantity=1)
        inv.add_item(sword)
        inv.add_item(sword)
        
        self.assertEqual(inv.items["Schwert"].quantity, 2)
    
    def test_weight_limit(self):
        """Testet Gewichtsgrenze"""
        inv = create_inventory(max_weight=10.0)
        
        heavy_item = Item(name="Schweres Item", weight=15.0, quantity=1)
        result = inv.add_item(heavy_item)
        
        self.assertFalse(result)
    
    def test_slot_limit(self):
        """Testet Slot-Grenze"""
        inv = create_inventory(max_slots=2)
        
        item1 = Item(name="Item1", weight=1.0)
        item2 = Item(name="Item2", weight=1.0)
        item3 = Item(name="Item3", weight=1.0)
        
        inv.add_item(item1)
        inv.add_item(item2)
        result = inv.add_item(item3)
        
        self.assertFalse(result)


if __name__ == "__main__":
    unittest.main()
