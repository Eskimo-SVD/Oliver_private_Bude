try
{
  # der folgende Computer muss via Netzwerk erreichbar sein
  # (ggfs. Namen anpassen)
  $Computer = 'testcomputer'
  Get-WmiObject -Class Win32_OperatingSystem -ComputerName $computer -Credential Unbekannt
}
catch
{
  "Fehler aufgetreten: $_"
}
