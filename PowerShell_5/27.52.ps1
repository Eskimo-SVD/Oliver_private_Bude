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

# Metadatei f�r LCM generieren
$path = 'C:\LCMConfig'
$file = LCMConfigMonitor -OutputPath $path -ComputerName localhost

# Metadatei an LCM senden
Set-DscLocalConfigurationManager -Path $path -ComputerName localhost
