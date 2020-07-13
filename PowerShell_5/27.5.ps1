Configuration SpoolerService
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'

  node localhost
  {
    Service SpoolerService
    {
      Ensure = 'Present'
      Name = 'Spooler'
      StartupType = 'Automatic'
      State = 'Running'
    }
  }
}

$file = SpoolerService -OutputPath c:\dscSpooler

Start-DscConfiguration -Path C:\dscSpooler -Wait -Verbose
