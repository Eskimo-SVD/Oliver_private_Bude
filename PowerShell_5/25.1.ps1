$start = Get-Date

& $code1
& $code2
& $code3

$end = Get-Date
$timespan = $end - $start
$seconds = $timespan.TotalSeconds
Write-Host "Gesamtdauer: $seconds sec."
