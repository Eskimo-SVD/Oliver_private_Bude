# Pipeline Streaming:
$ergebnis = Get-Service | Where-Object { $_.Status -eq 'Running' }

# klassischer Ansatz:
$liste = Get-Service
$ergebnis = foreach($element in $liste)
  {
    if ($element.Status -eq 'Running')
    {
      $element
    }
  }
