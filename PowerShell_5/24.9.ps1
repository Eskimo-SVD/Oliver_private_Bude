# Name der Fähigkeit:
$Name = 'Information'


# Konfiguration definieren:
$Config = @{
    VisibleExternalCommands = 'c:\windows\system32\systeminfo.exe', 'c:\windows\system32\netstat.exe'
    VisibleCmdlets = 'Get-WMIObject', 'Get-ACL'
}

# Name des neuen Moduls:
$guid = [Guid]::NewGuid().toString('d')
$ModuleName = 'Role{0}_{1}' -f $Name,$guid
$modulePath = "$env:programfiles\WindowsPowerShell\Modules\$ModuleName"

# Modul herstellen:
New-Item -Path "$modulePath\RoleCapabilities" -ItemType Directory -Force
New-PSRoleCapabilityFile -Path "$modulePath\RoleCapabilities\$Name.psrc" @Config
New-ModuleManifest -Path "$modulePath\$ModuleName.psd1"
