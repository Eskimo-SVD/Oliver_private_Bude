do
{
  $datum = Read-Host -Prompt 'Datum eingeben'
} until ($datum -as [DateTime])

$differenz = New-TimeSpan $datum
'Sie sind {0:n0} Tage alt!' -f $differenz.Days
