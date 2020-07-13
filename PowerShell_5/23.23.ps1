# Objekt in Textform hier speichern
$path = "$env:temp\dienst.txt"

# Spoolerdienst lokal abrufen
$dienstOriginal = Get-Service -Name Spooler, WUAUServ

# Zeitmessung
$start = Get-Date

# Objekt in Textform serialisieren
$dienstOriginal | Export-Clixml $path
# Objektkopie aus Textform deserialisieren
$dienstKopie = Import-Clixml $path

# Zeitmessung
$ende = Get-Date

# Analyse
$ausgabe = [Ordered]@{}

$ausgabe.Originaltyp = $dienstOriginal | 
                        Get-Member | 
                        Select-Object -ExpandProperty TypeName | 
                        Sort-Object -Unique

$ausgabe.'Deserialisierter Typ' = $dienstKopie | 
                        Get-Member | 
                        Select-Object -ExpandProperty TypeName | 
                        Sort-Object -Unique

$ausgabe.'Zeit (ms)' = [int]($ende - $start).TotalMilliseconds
$ausgabe.'Methoden im Original' = ($dienstOriginal | Get-Member -MemberType *Method).Count
$ausgabe.'Methoden in Kopie' = ($dienstKopie | Get-Member -MemberType *Method).Count
$ausgabe.Datenmenge = '{0:n1} KB' -f  ((Get-Item -Path $Path).Length / 1KB)

New-Object -TypeName PSObject -Property $ausgabe

# Textdatei öffnen
notepad $path
