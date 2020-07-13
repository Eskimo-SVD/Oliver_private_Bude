Configuration LocalUserConfig {

  Import-DscResource –ModuleName PSDesiredStateConfiguration

  Node localhost 
  {
    Group PSGroup 
    {
      Ensure = 'Present'
      GroupName = 'PowerShellUsers'
      MembersToInclude = 'Dozent'
      DependsOn = '[User]GroupMember'
    }

    User GroupMember {
      Ensure = 'Present'
      UserName = 'Dozent'
      PasswordNeverExpires = $true
    }
  }
}

$file = LocalUserConfig -OutputPath c:\DSCLocalUser 
Start-DscConfiguration -Path c:\DSCLocalUser -ComputerName localhost -Wait -Verbose
