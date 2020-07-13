# Pfadname zu einer neuen pssc-Datei festlegen
$Path = "$env:temp\jea2.pssc"

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
New-PSSessionConfigurationFile -Path $Path –SessionType RestrictedRemoteServer -LanguageMode NoLanguage –ExecutionPolicy RemoteSigned -RunAsVirtualAccount -VisibleCmdlets Microsoft.PowerShell.Management\* -FunctionDefinitions $getUserInfo -VisibleProviders FileSystem

# Endpunkt anlegen
Register-PSSessionConfiguration -Path $Path -Name JEA2 -Force

# JEA-Gruppe berechtigen
Set-PSSessionConfiguration -Name JEA2 -ShowSecurityDescriptorUI -Force
