Configuration LCMConfigMonitor
{ 
    Param([string]$ComputerName)
    
    node ($ComputerName)
    {
        LocalConfigurationManager 
        {
            ConfigurationMode = 'ApplyOnly'   
        }
     }
}

# Metadatei für LCM generieren
$path = 'C:\LCMConfig'
$file = LCMConfigMonitor -OutputPath $path -ComputerName localhost

# Metadatei an LCM senden
Set-DscLocalConfigurationManager -Path $path -ComputerName localhost
