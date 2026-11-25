# RPG-OS
[![Tests](https://github.com/koenimvf/RPG-OS/actions/workflows/ci.yml/badge.svg)](https://github.com/koenimvf/RPG-OS)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Ein vollständig autarkes Betriebssystem mit RPG-Elementen.

## Features
- 🎮 **Level-System** - XP sammeln, Level aufsteigen
- 📝 **Quest-System** - Aufgaben für Systemverwaltung
- 🎒 **Inventar-System** - Ressourcen verwalten
- ⚔️ **Kampfsystem** - Konflikte um Ressourcen

## Architektur
```
RPG-OS/
├── src/
│   ├── core.py          # Hauptanwendung
│   ├── shell/           # Shell mit RPG-UI
│   ├── levels/          # XP/Level-System
│   ├── inventory/       # Inventar-Verwaltung
│   ├── quests/          # Quest-Engine
│   ├── combat/          # Kampfsystem
│   ├── system/          # Systemdienste
│   └── utils/           # Hilfsfunktionen
├── tests/               # Unit-Tests (18 Tests ✅)
├── Makefile             # Build-System
└── config.yaml          # Konfiguration
```

## Installation
```bash
cd /scratch/koenimvf/RPG-OS/
make bootstrap
pip install -e .
```

## Nutzung
```bash
rpg-os              # Startet RPG-OS Core
python3 -m shell    # Startet Shell
make test           # Führt Tests aus (18/18 ✅)
```

## API-Dokumentation

### Level-System
```python
from src.levels.main import create_level_system

levels = create_level_system()
levels.add_xp(50)  # Fügt XP hinzu
levels.level_up()  # Level-Aufstieg
```

### Inventar-System
```python
from src.inventory.main import create_inventory, Item

inv = create_inventory()
item = Item(name="Schwert", weight=3.0, quantity=1)
inv.add_item(item)
inv.list_items()
```

### Quest-System
```python
from src.quests.main import create_quest_log, Quest

log = create_quest_log()
quest = Quest(id="q1", name="Test", description="Beschreibung", xp_reward=50)
log.add_quest(quest)
log.complete_quest("q1")
```

### Kampfsystem
```python
from src.combat.main import Combatant

hero = Combatant(name="Held", hp=100, attack=15, defense=5)
enemy = Combatant(name="Gegner", hp=80, attack=12, defense=3)
hero.attack_target(enemy)
```

## Status
**0.1.0** - Core-Module mit Tests ✅

## Roadmap
- [ ] 0.2.0 - Kernel-Bootstrap
- [ ] 0.3.0 - Systemdienste
- [ ] 0.4.0 - Integration
- [ ] 1.0.0 - Release

## Lizenz
MIT License
