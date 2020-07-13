configuration SpoolerWatch
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'
  
  service Spoolerüberwachung
  {
    Name = 'Spooler'
    StartupType = 'Automatic'
    State = 'Running'
    Ensure = 'Present'
  }
}

$file = SpoolerWatch -OutputPath C:\SpoolerConfig
