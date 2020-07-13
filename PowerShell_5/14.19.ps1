function Download-File
{
  param
  (
    [Parameter(Mandatory = $true, ValueFromPipeline=$true)]
    [String]
    $Url,

    [Parameter(Mandatory = $true)]
    [String]
    $DestinationFolder,
    
    [Switch]
    $Force,
    
    [Switch]
    $Open,
    
    [Switch]
    $PassThru
  )

  # dies nur EINMAL am Anfang prüfen:
  begin
  {
    # Sicherstellen, dass der Zielordner existiert
    $existiert = Test-Path -Path $DestinationFolder
    if ($existiert -eq $false) 
    {
      $null = New-Item -Path $DestinationFolder -ItemType Directory
    }
  }

  # dies für ALLE einlaufenden URLs machen:
  process
  {
    # Datei-Zielname aus Link extrahieren:
    $filename = Split-Path -Path $Url -Leaf
    $destinationPath = Join-Path -Path $DestinationFolder -ChildPath $filename

    # Bild herunterladen
    try
    {
      # falls nicht überschrieben werden soll, zuerst prüfen, ob die Datei
      # schon existiert, und gegebenenfalls einen neuen Dateinamen erstellen
      if (!$Force)
      {
        $destinationPath = Get-NewFileNameIfPresent -Path $destinationPath
      }
      Invoke-WebRequest -Uri $Url -OutFile $destinationPath -ErrorAction Stop
      if ($PassThru) { $destinationPath }
    }
    catch
    {
      Write-Warning "$Url wurde nicht gefunden."
    }
  }
  
  end
  {
    if ($Open)
    {
      explorer $destinationFolder
    }
  }
}
