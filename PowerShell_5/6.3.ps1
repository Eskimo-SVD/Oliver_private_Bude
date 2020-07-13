$ergebnis = 1 | Select-Object -Property Name, BIOS, Datum
$ergebnis.Name = $env:COMPUTERNAME
$ergebnis.BIOS = Get-WmiObject -Class Win32_BIOS | Select-Object -ExpandProperty Version
$ergebnis.Datum = Get-Date

$ergebnis | Out-GridView -Title 'System-Informationen'
