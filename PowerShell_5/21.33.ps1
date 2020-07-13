$stichtag = Get-Date -Hour 0 -Minute 0 -Second 0
$anmeldungen = Get-EventLog -LogName Security -InstanceId 4624 -After $stichtag
$anmeldungen.Count
$anmeldungen | Out-GridView
