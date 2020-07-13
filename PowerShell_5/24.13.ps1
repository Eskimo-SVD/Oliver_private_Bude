# Name der Fähigkeit:
$Name = 'ADAdmin'

# Funktionen definieren:
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


# sichtbare Cmdlets definieren:
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
                


# Konfiguration definieren:
$Config = @{
    FunctionDefinitions = $getUserInfo, $resetADPassword
    VisibleCmdlets = $VisibleCmdlets
}

# Name des neuen Moduls:
$guid = [Guid]::NewGuid().toString('d')
$ModuleName = 'Role{0}_{1}' -f $Name,$guid
$modulePath = "$env:programfiles\WindowsPowerShell\Modules\$ModuleName"

# Modul herstellen:
New-Item -Path "$modulePath\RoleCapabilities" -ItemType Directory -Force
New-PSRoleCapabilityFile -Path "$modulePath\RoleCapabilities\$Name.psrc" @Config
New-ModuleManifest -Path "$modulePath\$ModuleName.psd1"
