# RPG-OS - Vollständige Dokumentation

## Schnellstart
```bash
cd /scratch/koenimvf/RPG-OS/
make bootstrap
make build
make test          # 18/18 Tests bestanden
make run
```

## Projektübersicht
- **Status**: 0.1.0 - Core-Module entwickelt und getestet
- **Sprachen**: Python 3.11+
- **Tests**: 18 Unit-Tests (100% bestanden)
- **Lizenz**: MIT

## Kern-Module

### 1. Level-System (`src/levels/main.py`)
- XP sammeln und Level aufsteigen
- Automatische XP-Berechnung
- Progress-Tracking

### 2. Inventar-System (`src/inventory/main.py`)
- Slot-basierte Verwaltung
- Gewichtsbegrenzung
- Item-Hinzufügen/Entfernen

### 3. Quest-System (`src/quests/main.py`)
- Quest-Verwaltung
- XP-Belohnungen
- Quest-Log

### 4. Kampfsystem (`src/combat/main.py`)
- 1vs1-Kämpfe
- Siegeswahrscheinlichkeit
- Schadensberechnung

## Dateistruktur
```
RPG-OS/
├── src/
│   ├── core.py          # Hauptanwendung
│   ├── shell/main.py    # Shell mit RPG-UI
│   ├── levels/main.py   # Level-System
│   ├── inventory/main.py # Inventar
│   ├── quests/main.py   # Quest-System
│   ├── combat/main.py   # Kampfsystem
│   ├── system/          # Systemdienste
│   └── utils/           # Hilfsfunktionen
├── tests/               # Unit-Tests
├── Makefile             # Build-System
└── config.yaml          # Konfiguration
```

## API-Referenz

### Level-System API
```python
from src.levels.main import create_level_system

levels = create_level_system()  # Erstellt Level-System
levels.add_xp(50)               # XP hinzufügen
levels.level_up()               # Level-Aufstieg
levels.get_progress()           # Fortschritt (0.0-1.0)
```

### Inventar API
```python
from src.inventory.main import create_inventory, Item

inv = create_inventory(max_slots=10, max_weight=100.0)
item = Item(name="Schwert", weight=3.0, quantity=1)
inv.add_item(item)              # Item hinzufügen
inv.remove_item("Schwert", 1)   # Item entfernen
inv.list_items()                # Liste anzeigen
inv.get_total_weight()          # Gesamtgewicht
```

### Quest API
```python
from src.quests.main import create_quest_log, Quest

log = create_quest_log()
quest = Quest(id="q1", name="Test", description="Beschreibung", xp_reward=50)
log.add_quest(quest)
log.complete_quest("q1")
log.list_quests()
log.get_xp_total()              # Gesamt-XP
```

### Kampf API
```python
from src.combat.main import Combatant, calculate_win_chance

hero = Combatant(name="Held", hp=100, attack=15, defense=5)
enemy = Combatant(name="Gegner", hp=80, attack=12, defense=3)
hero.attack_target(enemy)       # Angreifen
calculate_win_chance(hero, enemy)  # Siegeswahrscheinlichkeit
```

## Build-System

### Makefile-Befehle
```bash
make bootstrap   # Projekt initialisieren
make build       # Projekt bauen
make test        # Tests ausführen
make run         # RPG-OS starten
make clean       # Aufräumen
```

## Tests
```bash
python3 -m pytest tests/ -v
# Ergebnis: 18 passed in 0.02s
```

## Konfiguration
`config.yaml` enthält:
- XP-Einstellungen
- Quest-Konfiguration
- Inventar-Limits
- Kampf-Optionen

## Nächste Schritte
- [ ] Kernel-Implementierung (C/Rust)
- [ ] Shell-Integration
- [ ] Boot-Sequence
- [ ] Systemdienste

## Lizenz
MIT License - siehe `LICENSE` Datei
