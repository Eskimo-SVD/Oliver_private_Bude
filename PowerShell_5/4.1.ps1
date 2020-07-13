# sicherstellen, dass eine versteckte ISE Konsole vorhanden ist:
$null = cmd.exe /c echo

# Konsolen-Encoding korrigieren:
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8

# deutsche Umlaute erscheinen korrekt:
systeminfo.exe /FO CSV | ConvertFrom-CSV | Out-GridView
