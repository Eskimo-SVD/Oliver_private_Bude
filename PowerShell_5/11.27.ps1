# Guid erzeugen
$guid = [guid]"{DCB00C01-570F-4A9B-8D69-199FDBA5723B}"

# Typ finden
$type = [type]::GetTypeFromCLSID($guid)

# COM-Objekt anlegen:
$netzwerk = [Activator]::CreateInstance($type)

$netzwerk
