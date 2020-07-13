function Remove-ISEAlias
{
  # Inhalt des aktuellen Skripts im ISE-Editor lesen:
  $text = $psISE.CurrentFile.Editor.Text

  # für die schnelle Bearbeitung des Textes diesen in einen "StringBuilder" laden:
  $sb = New-Object System.Text.StringBuilder $text

  # alle Befehle im Code in umgekehrter Reihenfolge finden
  # (letzter Befehl zuerst):
  $befehle = [System.Management.Automation.PSParser]::Tokenize($text, [ref]$null) |
    Where-Object { $_.Type -eq 'Command' } |
    Sort-Object -Property Start -Descending |
      # alle Aliase auflösen
      ForEach-Object {
        $befehl = $text.Substring($_.Start, $_.Length)
        $befehlstyp = @(try {Get-Command $befehl -ErrorAction 0} catch {})[0]

        if ($befehlstyp -is [System.Management.Automation.AliasInfo])
        {
          $sb.Remove($_.Start, $_.Length)
          $sb.Insert($_.Start+1, $befehlstyp.ResolvedCommandName)
        }

    # Aktualisierten Text in Editor ersetzen:
    $psISE.CurrentFile.Editor.Text = $sb.toString()
  }
}
