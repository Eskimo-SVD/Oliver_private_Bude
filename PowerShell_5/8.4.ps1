# Code muss in einer echten PowerShell-Konsole ausgef�hrt werden,
# nicht im ISE-Editor!

# Gesamten Inhalt der Eigenschaft "BufferSize" lesen:
PS> $bufferSize = $Host.UI.RawUI.BufferSize

# das Objekt auf die sichtbare Breite einstellen.
# dies allein bewirkt keine �nderung der Konsole:
PS> $bufferSize.Width = $Host.UI.RawUI.WindowSize.Width

# das ge�nderte Objekt wieder zur�ck in die Eigenschaft
# "Buffersize" schreiben. Jetzt �ndert sich die Pufferbreite:
$Host.UI.RawUI.BufferSize = $bufferSize
