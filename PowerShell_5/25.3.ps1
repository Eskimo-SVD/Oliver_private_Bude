$code1 = { Get-Service }
$code2 = { Get-Process }
$code3 = { Get-Hotfix }

$start = Get-Date

$ergebnis1 = & $code1
$ergebnis2 = & $code2
$ergebnis3 = & $code3

$end = Get-Date
$timespan = $end - $start
$seconds = $timespan.TotalSeconds
Write-Host "Gesamtdauer: $seconds sec."
