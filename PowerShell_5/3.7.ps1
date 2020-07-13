#requires -Version 3
# Datei anlegen:
$desktop = "$home\Desktop"
$original = Join-Path -Path $desktop -ChildPath 'original.txt'
$kopie = Join-Path -Path $desktop -ChildPath 'kopie.txt'

"Hallo Welt" | Set-Content -Path $original


# Sicherheitskopie erstellen:
Copy-Item -Path $original -Destination $kopie

# die zwei zuletzt geänderten Dateien auf dem Desktop auflisten:
Get-ChildItem -Path $desktop -File | 
  Sort-Object -Property LastWriteTime -Descending | 
  Select-Object -First 2
