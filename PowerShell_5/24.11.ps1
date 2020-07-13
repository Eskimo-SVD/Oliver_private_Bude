# Pfadname zu einer neuen pssc-Datei festlegen
$Path = "$env:temp\jeaAD.pssc"

# Get-UserInfo liefert den Wert von $PSSenderInfo zurück
# darin ist der Name des aufrufenden Anwenders zu finden
$getUserInfo = @{
  Name='Get-UserInfo'

  ScriptBlock=
  { 
    $PSSenderInfo 
  }
}


$resetADPassword = @{
  Name='Reset-ADPassword'
  
  ScriptBlock=
  {
    param($Identity)
    $NewPassword = Read-Host -Prompt 'Enter New Password' -AsSecureString
    # Reset the password
    ActiveDirectory\Set-ADAccountPassword -Identity $Identity -NewPassword $NewPassword -Reset
    # Require the user to reset at next logon
    ActiveDirectory\Set-ADUser -Identity $Identity -ChangePasswordAtLogon $true
  }
} 

 
$VisibleCmdlets = 'Get-ADUser',
'Unlock-ADAccount', 
@{ Name = 'Set-ADUser'; Parameters = @{ Name = 'Title'; ValidateSet = 'Manager', 'Engineer' }},
'Search-ADAccount',
@{ Name = 'Add-ADGroupMember'; Parameters = 
  @{Name = 'Identity'; ValidateSet = 'TestGroup'},
@{Name = 'Members'}},
@{ Name = 'Remove-ADGroupMember'; Parameters = 
  @{Name = 'Identity'; ValidateSet = 'TestGroup'},
@{Name = 'Members'}},
'Enable-ADAccount',
'Disable-ADAccount' 
                  


# Datei anlegen
New-PSSessionConfigurationFile -Path $Path –SessionType RestrictedRemoteServer -LanguageMode NoLanguage –ExecutionPolicy Restricted -RunAsVirtualAccount -VisibleCmdlets $VisibleCmdlets -FunctionDefinitions $resetADPassword, $getUserInfo

# Endpunkt anlegen
Register-PSSessionConfiguration -Path $Path -Name ADAdmin -ShowSecurityDescriptorUI -Force
