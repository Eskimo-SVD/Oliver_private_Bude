$lottozahlen = 1..49 | Get-Random -Count 7
$zusatzzahl = $lottozahlen[0]
$zahlen = $lottozahlen[1..6] | Sort-Object

"Die Lottozahlen lauten $zahlen und die Zusatzzahl ist $zusatzzahl"
