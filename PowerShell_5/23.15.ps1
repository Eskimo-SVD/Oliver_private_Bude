# Pfadname zu einer neuen pssc-Datei festlegen
$Path = "$env:temp\DruckerAdmin.pssc"

# erlaubte Befehle definieren
$stopComputer = @{
  Name = 'Stop-Computer'
  Parameters = @{Name = 'Force'}
}

$stopService = @{
  Name = 'Stop-Service'
  Parameters = @{Name = 'Name'; ValidateSet = 'Spooler', 'WebClient' }
}

$getWMIObject = @{
  Name = 'Get-WMIObject'
  Parameters = @{Name = 'Class'; ValidatePattern = 'Win32_.*' }, @{Name = 'ComputerName'; ValidatePattern = 'server\d{1,4}' }
}



# Datei anlegen
New-PSSessionConfigurationFile -Path $Path –SessionType RestrictedRemoteServer -LanguageMode NoLanguage –ExecutionPolicy Restricted -VisibleCmdlets $stopservice, $stopcomputer, $getWMIObject

# Endpunkt anlegen
Register-PSSessionConfiguration -Path $Path -Name ServerAdmins -Force
