$start = Get-Date

# drei Aufgaben definieren
$code1 = { Start-Sleep -Seconds 5; "A" }
$code2 = { Start-Sleep -Seconds 6; "B" }
$code3 = { Start-Sleep -Seconds 7; "C" }

# zwei Aufgaben in Hintergrundjobs verlagern und dort ausführen:
$job1 = Start-Job -ScriptBlock $code1 
$job2 = Start-Job -ScriptBlock $code2 

# die voraussichtlich längste Aufgabe in der eigenen PowerShell ausführen:
$result3 = & $code3 

# warten, bis alle Hintergrundjobs ihre Aufgabe erledigt haben:
$alljobs = Wait-Job $job1, $job2 

# Ergebnisse der Hintergrundjobs abfragen:
$result1 = Receive-Job $job1
$result2 = Receive-Job $job2

# Hintergrundjobs wieder entfernen
Remove-Job $alljobs

$end = Get-Date

# Ergebnisse ausgeben
$result1, $result2, $result3

$timespan = $end - $start
$seconds = $timespan.TotalSeconds
Write-Host "Gesamtdauer: $seconds sec."
