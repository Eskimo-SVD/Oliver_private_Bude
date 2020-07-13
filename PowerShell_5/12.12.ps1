function Test-ReturnValue
{
  param
  (
    $Anzahl = 1
  )

  1..$Anzahl |
    ForEach-Object {  'ich wurde einfach liegengelassen' }
}
