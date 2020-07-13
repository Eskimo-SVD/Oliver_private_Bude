function Get-ScriptVariable
{
  # Inhalt des aktuellen Skripts im ISE-Editor lesen:
  $text = $psISE.CurrentFile.Editor.Text

  # alle Variablen im Code in finden
  [System.Management.Automation.PSParser]::Tokenize($text, [ref]$null) |
  Where-Object { $_.Type -eq 'Variable' } |
  Select-Object -ExpandProperty Content |
  Sort-Object -Unique
}
