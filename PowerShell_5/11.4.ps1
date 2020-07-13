Measure-Command {
  $text = 'Start'
  for ($x = 1; $x -lt 100000; $x ++)
  {
    $text += 'neuer Text'
  }
}