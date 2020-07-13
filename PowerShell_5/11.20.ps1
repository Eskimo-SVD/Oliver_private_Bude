# COM-Objekt besorgen:
$wshell = New-Object -ComObject WScript.Shell

# Argumente vorbereiten:
$message = 'Ihr Rechner wird jetzt neu gestartet. Einverstanden?'
$title = 'Wichtig'

# Methode Popup() aufrufen:
$response = $wshell.Popup($message, 10, $title, (4+48))

# Ergebnis auswerten:
if ($response -ne 7)
{
  Restart-Computer -WhatIf
}
