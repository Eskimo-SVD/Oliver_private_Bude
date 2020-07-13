#requires -Version 3

# Zielordner muss existieren!
$zielordner = 'C:\LogFiles'
# Zielordner anlegen oder �berschreiben, falls vorhanden
# ACHTUNG: Ein vorhandener Zielordner wird komplett gel�scht!
$null = New-Item -Path $zielordner -ItemType Directory -Force

# alle .log-Dateien im Windows-Ordner finden...
Get-ChildItem -Path $env:windir -Filter *.log -Recurse -ErrorAction Ignore -File |
  # ...und Dateien in Zielordner kopieren
  Copy-Item -Destination $zielordner

# Zielordner �ffnen
explorer $zielordner
