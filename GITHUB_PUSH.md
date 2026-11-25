# RPG-OS - GitHub Repository Setup

## Vor dem Push

### 1. Git-Repository initialisieren (falls noch nicht geschehen)
```bash
cd /scratch/koenimvf/RPG-OS
git init
```

### 2. .gitignore erstellen
```
# Build-Ausgabe
*.o
*.bin
*.iso
test.iso

# QEMU
*.qcow2
qemu.log

# IDE/Editor
.vscode/
.idea/
*.swp
*.swo

# Logs
*.log

# OS-Spezifisch
.DS_Store
Thumbs.db

# Temporär
tmp/
temp/
```

### 3. Remote hinzufügen
```bash
# Beispiel: GitHub-Repository
git remote add origin https://github.com/USERNAME/rpg-os.git

# Oder SSH-Variante
git remote add origin git@github.com:USERNAME/rpg-os.git
```

### 4. Dateien hinzufügen und commiten
```bash
# Alle Dateien hinzufügen
git add .

# Commit
git commit -m "Initial commit: RPG-OS with D&D 5e integration"
```

### 5. Pushen
```bash
# Branch auf GitHub erstellen und pushen
git push -u origin main

# Oder master (je nach Default-Branch)
git push -u origin master
```

## GitHub Repository Erstellen

1. Gehe zu https://github.com/new
2. Repository-Name eingeben: `rpg-os`
3. Public oder Private wählen
4. "Initialize this repository with a README" (optional)
5. "Create repository"

## Nach dem Push

### Branch-Schutz aktivieren (empfohlen)
1. Gehe zu Settings > Branches
2. "Add rule" für `main` oder `master`
3. "Require pull request reviews" aktivieren
4. "Require status checks" hinzufügen

### Releases erstellen
1. Gehe zu Releases > "Draft a new release"
2. Tag erstellen: `v1.0.0-alpha`
3. Release-Notes schreiben
4. `rpg-os.iso` als Asset hochladen

## Tipps

- Nutze `.gitignore` für Build-Ausgabe
- Commit-Frequency: nach jeder funktionierenden Komponente
- Branch-Strategie: `main` (stable), `dev` (development)
- Releases: nach jeder major Änderung
