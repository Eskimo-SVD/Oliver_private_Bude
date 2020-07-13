function Test-Parameter
{
  param
  (
    [PSObject]
    $Information
  )
  
  $Information.Name = 'Willibald'
}

$objekt = New-Object -TypeName PSObject -Property @{ Name = 'Weltner'; ID = 12 }

$objekt
Test-Parameter -Information $objekt
$objekt
