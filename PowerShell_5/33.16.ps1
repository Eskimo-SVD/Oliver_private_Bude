function Remove-ISEComment
{
  # Inhalt des aktuellen Skripts im ISE-Editor lesen:
  $text = $psISE.CurrentFile.Editor.Text

  # für die schnelle Bearbeitung des Textes diesen in einen "StringBuilder" laden:
  $sb = New-Object System.Text.StringBuilder $text

  # alle Kommentare im Code in umgekehrter Reihenfolge finden
  # (letzter Kommentar zuerst):
  $comments = [System.Management.Automation.PSParser]::Tokenize($text, [ref]$null) |
    Where-Object { $_.Type -eq 'Comment' } |
    Sort-Object -Property Start -Descending |
    # alle Textstellen im Editor entfernen
    ForEach-Object {
        $sb.Remove($_.Start, $_.Length)

    }

    # Aktualisierten Text in Editor ersetzen:
    $psISE.CurrentFile.Editor.Text = $sb.toString()
}
