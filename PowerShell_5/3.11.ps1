#requires -Version 1

# PowerShell Profil kopieren
$profil = "$home\Documents\WindowsPowerShell"
$ziel = "$home\Documents\SicherheitskopiePSProfil"

$null = robocopy.exe $profil $Ziel /R:0 /S

explorer $ziel
