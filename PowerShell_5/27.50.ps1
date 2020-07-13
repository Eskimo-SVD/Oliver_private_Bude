configuration SpoolerWatch
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'
  
  service Spooler�berwachung
  {
    Name = 'Spooler'
    StartupType = 'Automatic'
    State = 'Running'
    Ensure = 'Present'
  }
}

$file = SpoolerWatch -OutputPath C:\SpoolerConfig
