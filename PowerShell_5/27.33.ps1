# Angaben zu Modul und Ressource:
$ModuleName = 'xConfigPersonalData'
$ResourceName = 'xSetOwnerInfo'
$parameters = @()
$parameters += New-xDscResourceProperty –Name RegisteredOwner –Type String –Attribute Key
$parameters += New-xDscResourceProperty –Name RegisteredOrganization –Type String –Attribute Key


# Default-Property hinzufügen
$parameters += New-xDscResourceProperty –Name Ensure –Type String –Attribute Write –ValidateSet 'Absent', 'Present'

# Modul und Ressource anlegen:
$ModulePath = "$env:ProgramFiles\WindowsPowerShell\Modules\$ModuleName"
New-xDscResource –Name $ResourceName -Property $parameters -Path $ModulePath

# Modulmanifest hinzufügen (Version, Beschreibung, etc.)
New-ModuleManifest -Path "$ModulePath\$ModuleName.psd1" -Author Tobias -Description 'Verwaltet persönliche Einstellungen wie z.B. Angaben über den Besitzer des Computers' -ModuleVersion 1.0

# Modul-Datei im ISE-Editor öffnen
ise "$ModulePath\$ModuleName.psm1"
