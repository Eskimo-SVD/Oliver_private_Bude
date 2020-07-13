#requires -Version 1

# PowerShell Profil kopieren
$profil = "$home\Documents\WindowsPowerShell"
$ziel = "$home\Documents\SicherheitskopiePSProfil"

$existiert = Test-Path -Path $profil
if (!$existiert)
{
	Write-Warning "Das Profil $profil existiert nicht - nichts zu kopieren!"
	return
}

Copy-Item -Path $profil -Destination $ziel -Recurse

explorer $ziel
