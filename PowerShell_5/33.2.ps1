$Path = $profile.CurrentUserAllHosts
$exists = Test-Path -Path $Path

# Profildatei nur anlegen, wenn sie noch nicht existiert
# -Force legt auch alle fehlenden Unterordner mit an:
if ($exists -eq $false)
{
    $null = New-Item -Path $path -ItemType File -Force
}

# Profildatei im ISE-Editor öffnen
ise $Path
