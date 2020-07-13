Configuration SpoolerService
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'
  Service SpoolerService
  {
    Ensure = 'Present'
    Name = 'Spooler'
    StartupType = 'Disabled'
    State = 'Stopped'
  }
}
SpoolerService -OutputPath c:\SpoolerService
Publish-DscConfiguration -Path c:\SpoolerService -Verbose
