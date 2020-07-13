# Daten als XML serialisieren:
$Path = "$env:temp\prozesse.xml"
Get-Process | Select-Object Name, CPU | Export-Clixml $Path -Depth 1

# die Daten liegen nun als XML-Datei vor
# der Computer könnte nun neu gestartet 
# oder die Daten könnten auf einen anderen
# Computer transferiert werden

# Daten aus XML wiederherstellen:
$prozesse = Import-Clixml $Path
$prozesse | Sort-Object CPU | Out-GridView

# Größe der Datei bestimmen:
$size = (Get-Item -Path $Path).Length
Write-Warning "Dateigröße: $size Bytes."
