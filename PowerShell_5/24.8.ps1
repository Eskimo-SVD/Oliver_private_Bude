# Name der Fähigkeit:
$Name = 'Generic'


# private Funktion definieren:
$GetUserInfo = @{
  Name = 'Get-UserInfo'
  ScriptBlock = { $PSSenderInfo } 
}

# Konfiguration definieren:
$Config = @{
    FunctionDefinitions = $GetUserInfo
}

# Name des neuen Moduls:
$guid = [Guid]::NewGuid().toString('d')
$ModuleName = 'Role{0}_{1}' -f $Name,$guid
$modulePath = "$env:programfiles\WindowsPowerShell\Modules\$ModuleName"

# Modul herstellen:
New-Item -Path "$modulePath\RoleCapabilities" -ItemType Directory -Force
New-PSRoleCapabilityFile -Path "$modulePath\RoleCapabilities\$Name.psrc" @Config
New-ModuleManifest -Path "$modulePath\$ModuleName.psd1"
