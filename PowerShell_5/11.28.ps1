# Guid erzeugen
$guid = [guid]"{DCB00C01-570F-4A9B-8D69-199FDBA5723B}"

# Typ finden
$type = [type]::GetTypeFromCLSID($guid)

# COM-Objekt anlegen:
$netzwerk = [Activator]::CreateInstance($type)

# Hashtables für die auszulesenden Eigenschaften definieren:
$name = @{Name='Name'; Expression={ $_.GetName() }}
$beschreibung = @{Name='Beschreibung'; Expression={ $_.GetDescription() }}
$kategorie = @{Name='Kategorie'; Expression={ $_.GetCategory() }}

$netzwerk.GetNetworkConnections() | 
  ForEach-Object { $_.GetNetwork() } | 
    Select-Object $Name, $Beschreibung, $kategorie, isConnectedToInternet
