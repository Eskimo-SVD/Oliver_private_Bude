Measure-Command {
  $array = 1,2,3
  $array = [Collections.ArrayList]$array
  for ($x = 4; $x -lt 100000; $x ++)
  {
    $null = $array.Add($x)
  }
}