Measure-Command {
  $array = 1,2,3
  for ($x = 4; $x -lt 10000; $x ++)
  {
    $array += $x
  }
}
$array.Count