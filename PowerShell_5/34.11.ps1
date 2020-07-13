# Prozess unsichtbar starten
$prozess = New-Object -TypeName AppManager.AppInstance('notepad.exe', $true)

# etwas warten
Start-Sleep -Seconds 2

# Prozess anzeigen und maximieren
$prozess.Maximize()
