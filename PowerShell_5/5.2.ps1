$Path = $profile.CurrentUserAllHosts
$vorhanden = Test-Path -Path $Path

if (-not $vorhanden)
{
    $null = New-Item -Path $Path -ItemType File -Force
}
ise $Path
