# Pfadname zu einer neuen pssc-Datei festlegen
$Path = "$env:temp\jea3.pssc"

# Rollen definieren
$roles = @{
  'mycompany\JEA_Info' = @{RoleCapabilities = 'Information', 'Generic'}
  'mycompany\JEA_Service' = @{RoleCapabilities = 'ManageService', 'ManageLog', 'ADAdmin', 'Generic'}
}

# Datei anlegen
New-PSSessionConfigurationFile -Path $Path –SessionType RestrictedRemoteServer -LanguageMode NoLanguage –ExecutionPolicy Restricted -RunAsVirtualAccount -RoleDefinitions $roles 

# Endpunkt anlegen
Register-PSSessionConfiguration -Path $Path -Name JEA3 -Force
