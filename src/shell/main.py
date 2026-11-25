"""
RPG-OS Shell
Haupt-Shell für das RPG-basierte Betriebssystem
"""

import os
import sys

VERSION = "0.1.0"


def show_menu():
    """Zeige das Hauptmenü mit RPG-Info"""
    print(f"\n{'='*50}")
    print(f"  RPG-OS Shell v{VERSION}")
    print(f"{'='*50}")
    print("  Level: 1 | XP: 0/100")
    print("  Quests: 0 abgeschlossen")
    print(f"{'='*50}")
    print("\nVerfügbare Befehle:")
    print("  help      - Diese Hilfe anzeigen")
    print("  build     - Projekt bauen")
    print("  test      - Tests ausführen")
    print("  run       - RPG-OS starten")
    print("  levelup   - Level erhöhen (manuell)")
    print("  clear     - Bildschirm löschen")
    print("  exit      - Shell beenden")


def process_command(cmd: str) -> bool:
    """Verarbeignet einen Befehl"""
    cmd = cmd.strip().lower()
    
    if cmd in ("help", "h", "?"):
        show_menu()
        
    elif cmd == "build":
        print("Baue RPG-OS...")
        os.system("make build")
        
    elif cmd == "test":
        print("Führe Tests aus...")
        os.system("make test")
        
    elif cmd == "run":
        print("Starte RPG-OS...")
        os.system("make run")
        
    elif cmd == "levelup":
        print("Level erhöhen...")
        print("XP: 100/100 → Level 2!")
        
    elif cmd == "clear":
        os.system("clear" if os.name != "nt" else "cls")
        
    elif cmd in ("exit", "quit", "q"):
        print("Tschüss! 🎮")
        return False
        
    elif cmd == "":
        pass
        
    else:
        print(f"Unbekannter Befehl: {cmd}")
        print("Tippe 'help' für Hilfe")
        
    return True


def main():
    """Haupt-Shell-Schleife"""
    print("\nWillkommen bei RPG-OS!")
    show_menu()
    
    running = True
    while running:
        try:
            cmd = input("\n> ")
            running = process_command(cmd)
        except KeyboardInterrupt:
            print("\nAbbruch via Ctrl+C")
            running = False
        except EOFError:
            print("\nEOF - beende Shell")
            running = False
    
    print("Shell beendet.")


if __name__ == "__main__":
    main()
