$ergebnis = Get-Service | Group-Object -Property Status -AsHashTable -AsString

# alle laufenden Dienste abrufen
$ergebnis.Running

# alle gestoppten Dienste abrufen
$ergebnis.Stopped
