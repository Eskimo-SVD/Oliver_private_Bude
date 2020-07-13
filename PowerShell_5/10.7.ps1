# Beispiel Lottozahlen
$lottozahlen = 1..49 | Get-Random -Count 7
$zusatzzahl = $lottozahlen[0]
$zahlen = $lottozahlen[1..6] | Sort-Object
'Die Lottozahlen lauten {0} und die Zusatzzahl ist {1}' -f ($zahlen -join ','), $zusatzzahl
# Beispiel PowerShell-Version
'Die PowerShell-Version lautet {0}' -f $host.Version
# Beispiel Benutzername
'{0}: angemeldeter Benutzer' -f $env:username