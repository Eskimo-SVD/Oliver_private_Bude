try
{
  $null = New-Item -Path c:\willibald -ItemType Directory -ErrorAction Stop
}
catch [System.IO.IOException]
{
  Write-Warning "IO-Fehler: $_"
}
catch [System.Management.Automation.DriveNotFoundException]
{
  Write-Warning 'Laufwerk nicht g�ltig'
}
catch [System.UnauthorizedAccessException]
{
  Write-Warning 'Fehlende Zugriffsrechte'
}
catch [System.NotSupportedException]
{
  Write-Warning "Nicht unterst�tzt: $_"
}
catch
{
  Write-Warning ('Unbekannter Fehler: {0} (Typ: [{1}])' -f $_, $_.Exception.GetType().FullName)
}
