# die Gr��e dieses Ordners soll ermittelt werden
$Path = 'c:\windows'

# es sollen alle Dateien ber�cksichtigt werden
# (ersetzen Sie dies z.B. durch '*.log', um nur solche
# Dateien zu z�hlen)
$Filter = '*'

$TotalSize = Get-ChildItem -Path $Path -Filter $Filter -File -ErrorAction SilentlyContinue -Recurse -Force | Measure-Object -Property Length -Sum |  Select-Object -ExpandProperty Sum

"Die Gesamtgr��e des Ordners $Path betr�gt $TotalSize Bytes."

$TotalSizeMB = $TotalSize / 1MB

'Die Gesamtgr��e des Ordners "{0}" betr�gt {1:n1} MB.' -f $Path, $TotalSizeMB
