Configuration createDSCFolder
{
  Import-DscResource –ModuleName 'PSDesiredStateConfiguration'

  File createFolder
  {
      Type = 'Directory'
      Ensure = 'Present'
      DestinationPath = 'c:\newfolderDSC'
      Force = $true
  }
}
