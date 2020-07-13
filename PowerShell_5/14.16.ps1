function Get-NewFilenameIfPresent
{
  param
  (
    [Parameter(Mandatory=$true)]
    [String]
    $Path
  )

  $NewPath = $Path
  $Counter = 0
  
  # so lange an den Dateinamen eine Zahl anhängen, bis
  # die Datei nicht mehr existiert:
  While (Test-Path -Path $NewPath)
  {
    # neuen Dateinamen erzeugen
    $Counter++
    $parts = $Path.Split('.')
    $parts[-2]+= "($Counter)"
    $NewPath = $parts -join '.'
  }
  
  return $NewPath
}
