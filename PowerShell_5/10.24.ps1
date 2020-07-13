$text = 'wir müssen server1, server22 und server9 umbenennen.'

# Muster muss am Anfang (?i) enthalten, wenn die
# Groß- und Kleinschreibung ignoriert werden soll
# Das Muster beschreibt den Servernamen
$pattern = '(?i)server(\d{1,3})'

$code = 
{
  # Skriptblock empfängt jeden Treffer über seinen Parameter 
  param($match)
      
  # die Indexzahlen entsprechen den Indexzahlen, die beim
  # normalen -match-Operator in $Matches zurückgegeben würde:
  $alles = $match.Groups[0].Value
  $id = $match.Groups[1].Value

  # neuen Text aus diesen Informationen zusammenbauen:
  'VM_{0:000} (war mal {1})' -f [Int]$id, $alles
}

[RegEx]::Replace($text, $pattern, $code)
