$ladezustand = Get-WmiObject -Class Win32_Battery |
  Measure-Object -Property EstimatedChargeRemaining -Average |
  Select-Object -ExpandProperty Average 

$alarm = $ladezustand -lt 10

if ($ladezustand -eq $null)
{
  'Kein Akku vorhanden.'
}
elseif ($alarm -eq $true)
{
  'Hier könnte eine Alarmmeldung oder Aktion stehen'
}
else
{
  'Alles in Ordnung.'
}
