#requires -Version 3

# Zielordner muss existieren!
$zielordner = 'C:\Testbilder'
# Zielordner anlegen oder überschreiben, falls vorhanden
# ACHTUNG: Ein vorhandener Zielordner wird komplett gelöscht!
$null = New-Item -Path $zielordner -ItemType Directory -Force

# alle .log-Dateien im Windows-Ordner finden...
Get-ChildItem -Path $env:windir -Filter *.jpg -Recurse -ErrorAction SilentlyContinue -File |
  # ...und Dateien in Zielordner kopieren
  Copy-Item -Destination $zielordner

# Zielordner öffnen
explorer $zielordner
