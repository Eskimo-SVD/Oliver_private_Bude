# Code muss in einer echten PowerShell-Konsole ausgeführt werden,
# nicht im ISE-Editor!

# Gesamten Inhalt der Eigenschaft "BufferSize" lesen:
PS> $bufferSize = $Host.UI.RawUI.BufferSize

# das Objekt auf die sichtbare Breite einstellen.
# dies allein bewirkt keine Änderung der Konsole:
PS> $bufferSize.Width = $Host.UI.RawUI.WindowSize.Width

# das geänderte Objekt wieder zurück in die Eigenschaft
# "Buffersize" schreiben. Jetzt ändert sich die Pufferbreite:
$Host.UI.RawUI.BufferSize = $bufferSize
