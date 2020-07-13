#requires -Version 3
function Get-ScriptVariableReport
{
  # Inhalt des aktuellen Skripts im ISE-Editor lesen:
  $text = $psISE.CurrentFile.Editor.Text

  # alle Variablen im Code in finden
  [System.Management.Automation.PSParser]::Tokenize($text, [ref]$null) |
  Where-Object { $_.Type -eq 'Variable' } |
  # Name der Variable finden
  ForEach-Object {
    # die Zeile, in der die Variable steht, als Text lesen:
    $psISE.CurrentFile.Editor.SetCaretPosition($_.StartLine,1)
    $psISE.CurrentFile.Editor.SelectCaretLine()

    $hash = [Ordered]@{
      Name = $_.Content
      Line = $_.StartLine
      Code = $psISE.CurrentFile.Editor.SelectedText.Trim()
    }

    # Informationen zurückliefern
    New-Object -TypeName PSObject -Property $hash
  }
}
