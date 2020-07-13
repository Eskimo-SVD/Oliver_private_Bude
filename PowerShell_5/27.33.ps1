# Angaben zu Modul und Ressource:
$ModuleName = 'xConfigPersonalData'
$ResourceName = 'xSetOwnerInfo'
$parameters = @()
$parameters += New-xDscResourceProperty �Name RegisteredOwner �Type String �Attribute Key
$parameters += New-xDscResourceProperty �Name RegisteredOrganization �Type String �Attribute Key


# Default-Property hinzuf�gen
$parameters += New-xDscResourceProperty �Name Ensure �Type String �Attribute Write �ValidateSet 'Absent', 'Present'

# Modul und Ressource anlegen:
$ModulePath = "$env:ProgramFiles\WindowsPowerShell\Modules\$ModuleName"
New-xDscResource �Name $ResourceName -Property $parameters -Path $ModulePath

# Modulmanifest hinzuf�gen (Version, Beschreibung, etc.)
New-ModuleManifest -Path "$ModulePath\$ModuleName.psd1" -Author Tobias -Description 'Verwaltet pers�nliche Einstellungen wie z.B. Angaben �ber den Besitzer des Computers' -ModuleVersion 1.0

# Modul-Datei im ISE-Editor �ffnen
ise "$ModulePath\$ModuleName.psm1"
