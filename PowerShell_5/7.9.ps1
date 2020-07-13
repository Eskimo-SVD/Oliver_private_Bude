#requires -Version 3

# Daten als JSON serialisieren:
$Path = "$env:temp\prozesse.json"
Get-Process | Select-Object Name, CPU | ConvertTo-Json -Depth 1 | Set-Content -Path $Path

# die Daten liegen nun als JSON-Datei vor
# der Computer könnte nun neu gestartet 
# oder die Daten könnten auf einen anderen
# Computer transferiert werden

# Daten aus JSON wiederherstellen:
$prozesse = Get-Content -Path $Path -Raw | ConvertFrom-Json 
$prozesse | Sort-Object CPU | Out-GridView

# Größe der Datei bestimmen:
$size = (Get-Item -Path $Path).Length
Write-Warning "Dateigröße: $size Bytes."
