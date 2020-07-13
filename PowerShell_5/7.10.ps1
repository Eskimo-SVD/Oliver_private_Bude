#requires -Version 2

# Daten als CSV serialisieren:
$Path = "$env:temp\prozesse.csv"
Get-Process | Export-CSV -Path $Path

# die Daten liegen nun als CSV-Datei vor
# der Computer k�nnte nun neu gestartet 
# oder die Daten k�nnten auf einen anderen
# Computer transferiert werden

# Daten aus CSV wiederherstellen:
$prozesse = Import-CSV -Path $Path 
$prozesse | Sort-Object CPU | Out-GridView

# Gr��e der Datei bestimmen:
$size = (Get-Item -Path $Path).Length
Write-Warning "Dateigr��e: $size Bytes."
