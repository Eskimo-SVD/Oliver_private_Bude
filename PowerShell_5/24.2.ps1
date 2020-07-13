# Pfadname zu einer neuen pssc-Datei festlegen
$Path = "$env:temp\jea1.pssc"

# Get-UserInfo liefert den Wert von $PSSenderInfo zurück
# darin ist der Name des aufrufenden Anwenders zu finden
$getUserInfo = @{
  Name='Get-UserInfo'

  ScriptBlock=
  { 
    $PSSenderInfo 
  }
}

# Datei anlegen
New-PSSessionConfigurationFile -Path $Path –SessionType RestrictedRemoteServer -LanguageMode NoLanguage –ExecutionPolicy Restricted -RunAsVirtualAccount -VisibleCmdlets Microsoft.PowerShell.Management\*-Service, Get-* -ModulesToImport Microsoft.* -FunctionDefinitions $getUserInfo 

# Endpunkt anlegen
Register-PSSessionConfiguration -Path $Path -Name JEA1 -Force

# JEA-Gruppe berechtigen
Set-PSSessionConfiguration -Name JEA1 -ShowSecurityDescriptorUI -Force
