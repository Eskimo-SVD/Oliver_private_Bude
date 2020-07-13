Configuration LCMDefaultConfig
{ 
    Param([string]$ComputerName)
    
    node ($ComputerName)
    {
        LocalConfigurationManager 
        {
            RebootNodeIfNeeded = $false 
        }
     }
}

# Metadatei für LCM generieren
$path = 'C:\LCMConfig'
$file = LCMDefaultConfig -OutputPath $path -ComputerName localhost

# Metadatei an LCM senden
Set-DscLocalConfigurationManager -Path $path -ComputerName localhost
