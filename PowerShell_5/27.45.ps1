Configuration SpoolerService
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'
  Service SpoolerService
  {
    Ensure = 'Present'
    Name = 'Spooler'
    StartupType = 'Automatic'
    State = 'Running'
  }
}
SpoolerService -OutputPath c:\SpoolerService
Publish-DscConfiguration -Path c:\SpoolerService -Verbose
