# dieser Ordner soll existieren:
$Path = 'c:\neuerordner'

# prüfen, ob Ordner schon vorhanden ist:
$existiert = Test-Path -Path $Path

# ausgehend davon Ordner anlegen, wenn er fehlt:
if (!$existiert)
{
    # Ergebnis von New-Item an $null zuweisen,
    # weil das Ergebnis nicht gebraucht wird
    $null = New-Item -Path $Path -ItemType Directory
    Write-Warning 'Neuer Ordner angelegt'
}
else
{
    Write-Warning "Ordner '$path' war bereits vorhanden."
}
