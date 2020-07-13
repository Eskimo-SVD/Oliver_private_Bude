function Find-VariableScope
{
  param
  (
    # Name der Variable, die untersucht werden soll:
    $VariableName='MyInvocation'
  )

  # falls versehentlich mit führendem "$" angegeben, dieses entfernen:
  $VariableName = $VariableName.TrimStart('$')

  # 11 Verschachtelungstiefen testen:
  ForEach ($level in (0..10))
  {
    try
    {
      # existiert die Variable im untersuchten Gültigkeitsbereich (Scope)?
      $variable = Get-Variable $VariableName -Scope $level -ErrorAction SilentlyContinue

      if ($variable -eq $null)
      {
        # nein:
        $value = '[not defined]'
      }
      else
      {
        # ja, Inhalt als Text ausgeben:
        $value = $variable.Value | Out-String
      }
    }
    catch
    {
      # falls ein terminierender Fehler auftritt, ist kein übergeordneter
      # Gültigkeitsbereich mehr vorhanden, also abbrechen:
      break
    }

    # Textmeldung zentriert ausgeben:
    '*' * 70
    $text = "Gültigkeitsbereich Nr. $level, Inhalt der Variable '$VariableName':"
    $text = $text.PadLeft([int]($text.Length + ((70 - $text.Length) / 2)))
    $text
    '*' * 70
    # Inhalt der Variable in diesem Gültigkeitsbereich ausgeben:
    $value
  }
}

$testvariable = 100
function testit
{
    $testvariable = 12
    Find-VariableScope testvariable
}

testit
