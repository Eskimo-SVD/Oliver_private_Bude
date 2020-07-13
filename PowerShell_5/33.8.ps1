$Autor = '[Ihr Name]'
$Datum = Get-Date -Format 'yyyy-MM-dd'

$text = @"
########################
#
# Autor:   $Autor
# Version: 1.0
# Datum:   $datum
#
########################


"@

$file = $psise.CurrentPowerShellTab.Files.Add()
$file.Editor.Text = $text

# Cursorposition an den Anfang und dann an das
# Ende setzen, damit das Skript vollständig zu sehen ist:
$file.Editor.SetCaretPosition(1,1)
$file.Editor.SetCaretPosition($file.Editor.LineCount,1)
