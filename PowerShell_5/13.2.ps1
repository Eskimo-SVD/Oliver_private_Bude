$code = 
{
  param
  (
    [Parameter(Mandatory=$true,HelpMessage='Der Betrag in Dollar')]
    [Double]
    $Betrag,

    [Double]
    $Wechselkurs = 0.97
  )

  $Ergebnis = $Betrag * $Wechselkurs
  return $Ergebnis
}
