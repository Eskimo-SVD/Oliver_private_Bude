function Get-Alter 
{
  param
  (
    [Parameter(Mandatory=$true)]
    $datum
  )
  if (-not ($datum -as [DateTime])) {
    'Sie haben kein Datum angegeben!'
    break
  }
  $differenz = New-TimeSpan ($datum -as [DateTime])
  'Sie sind {0} Tage alt!' -f $differenz.Days
}
