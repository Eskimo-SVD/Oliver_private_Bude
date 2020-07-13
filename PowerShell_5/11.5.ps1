Measure-Command {
  $text = [Text.StringBuilder]'Start'
  for ($x = 1; $x -lt 100000; $x ++)
  {
    $null = $text.Append('neuer Text')
  }
  $gesamttext = $text.ToString()
}