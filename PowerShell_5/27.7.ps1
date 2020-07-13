$info =
@{
  AllNodes =
  @(
    @{
      NodeName = 'SERVER_B'
    }
  )
}

Configuration SpoolerService
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'

  node $AllNodes.NodeName
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

$file = SpoolerService -OutputPath c:\dscSpooler -ConfigurationData $info


Start-DscConfiguration -Path C:\dscSpooler -Wait -Verbose -ComputerName $info.AllNodes.NodeName 
