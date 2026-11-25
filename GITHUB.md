# RPG-OS
[![Build Status](https://github.com/koenimvf/RPG-OS/workflows/CI/badge.svg)](https://github.com/koenimvf/RPG-OS)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Ein vollständig autarkes Betriebssystem mit RPG-Elementen.

## Features
- 🎮 XP-System pro Task
- 📝 Quest-System für Systemverwaltung
- 🎒 Inventar-Verwaltung
- ⚔️ Kampfsystem für Ressourcenkonflikte
- 📊 Level-System

## Schnellstart
```bash
cd /scratch/koenimvf/RPG-OS/
make bootstrap
make build
make run
```

## Projekt-Status
**0.1.0** - Core Kernel & Shell

## Konzept
Ein Betriebssystem, bei dem das Verwalten des Systems zu Level-Aufstiegen führt, Quests abgeschlossen werden können und ein Inventar verwaltet wird.

## Technologie
- **Kernel**: Rust/C
- **Shell**: Python/Go
- **Build**: Make/CMake

## Roadmap
- [x] 0.1.0 - Projektsetup
- [ ] 0.2.0 - Core Kernel
- [ ] 0.3.0 - Level-System
- [ ] 0.4.0 - Quest-System
- [ ] 0.5.0 - Inventar
- [ ] 1.0.0 - Release

## Lizenz
MIT License
