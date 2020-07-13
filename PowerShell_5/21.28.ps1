function Get-Alter 
{
  param
  (
    [Parameter(Mandatory=$true)]
    $datum
  )
  if (-not ($datum -as [DateTime])) {
    Throw "'$datum' ist kein gültiges Datum."
  }
  $differenz = New-TimeSpan ($datum -as [DateTime])
  'Sie sind {0:n0} Tage alt!' -f $differenz.Days
}
