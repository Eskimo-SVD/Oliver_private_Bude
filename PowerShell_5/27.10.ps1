Configuration ClientServerConfig
{
  Import-DscResource -ModuleName PSDesiredStateConfiguration

  # diesen Teil nur für Server durchführen:
  node $AllNodes.Where{$_.Role -eq 'Server'}.NodeName
  {
    File ServerFile
    {
      Ensure = 'Present'
      DestinationPath = 'c:\DSC\serverfolder\info.txt'
      Contents = 'I am a server'
    }
  }

  # diesen Teil nur für Clients durchführen:
  node $AllNodes.Where{$_.Role -eq 'Client'}.NodeName
  {
    File ClientFile
    {
      Ensure = 'Present'
      DestinationPath = 'c:\DSC\clientfolder\info.txt'
      Contents = 'I am a client'
    }
  }

  # diesen Teil für alle Computer durchführen:
  node $AllNodes.NodeName
  {
    File AllFile
    {
      Ensure = 'Present'
      DestinationPath = 'c:\DSC\info.txt'
      Contents = 'I am a computer'
    }
  }
}

$file = ClientServerConfig -OutputPath c:\dscSpooler -ConfigurationData $info


Start-DscConfiguration -Path C:\dscSpooler -Wait -Verbose -ComputerName $info.AllNodes.NodeName -Credential PSRemoting 
