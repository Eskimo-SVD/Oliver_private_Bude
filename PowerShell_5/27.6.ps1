$Computer = 'SERVER_B'

Configuration SpoolerService
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'

  node $Computer
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

Start-DscConfiguration -Path C:\dscSpooler -Wait -Verbose -ComputerName $Computer 
