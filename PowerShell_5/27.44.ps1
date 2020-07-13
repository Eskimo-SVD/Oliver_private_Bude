[DscLocalConfigurationManager()]
Configuration SetupPartialConfig
{
  PartialConfiguration SpoolerService
  {
    Description = 'Enables the Spooler Service'
    RefreshMode = 'Push'
  }

  PartialConfiguration TextFile
  {
    Description = 'Create a text file'
    RefreshMode = 'Push'
    DependsOn = '[PartialConfiguration]SpoolerService'
  }
}

# Metadata generieren
SetupPartialConfig -OutputPath c:\TestPartialConfigs

# LCM konfigurieren
Set-DscLocalConfigurationManager -Path c:\TestPartialConfigs -Verbose
