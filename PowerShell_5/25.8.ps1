$code = {
  Start-Sleep -Seconds 2
  'Hello'
}

# neuen Thread erzeugen:
$newPowerShell = [powershell]::Create().AddScript($code)

# Thread asynchron starten:
$handle = $newPowerShell.BeginInvoke()

# auf Beendigung warten und währenddessen etwas
# anderes tun:
while ($handle.IsCompleted -eq $false) {
  Write-Host '.' -NoNewline
  Start-Sleep -Milliseconds 500
}
Write-Host ''

# Ergebnis aus anderem Thread abrufen:
$newPowerShell.EndInvoke($handle)
