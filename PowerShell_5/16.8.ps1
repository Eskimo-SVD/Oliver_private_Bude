function Get-W�rfelErgebnis
{
  param
  (
    [ValidateRange(1,3)]
    [Int]
    $W�rfe = 1
  )

  for($x=1; $x -le $W�rfe; $x++) 
  {
    Get-Random -Minimum 1 -Maximum 7  
  }
}
