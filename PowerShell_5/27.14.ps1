$info = @{
  AllNodes = @(
    @{
      NodeName = 'localhost'
      PSDscAllowPlainTextPassword = $true
      Credential = Get-Credential "$env:userdomain\$env:username"
    }
  )
}

Configuration TestUserCredential
{
  Import-DscResource -ModuleName PSDesiredStateConfiguration

  Node $AllNodes.NodeName
  {
    Script customScript
    {
      PsDscRunAsCredential = $Node.Credential
      GetScript = '@{}'
      TestScript = '$false'
      SetScript = {        
        New-Item -ItemType File -Path c:\dscTestIdentity\identity.txt -Value "$env:userdomain\$env:username" -Force
      }
    }
  }
}
 
$file = TestUserCredential -ConfigurationData $info -OutputPath c:\dscTestIdentity 
Start-DscConfiguration -Path c:\dscTestIdentity -Wait -Verbose -ComputerName $info.AllNodes.NodeName -Force
notepad c:\dscTestIdentity\identity.txt
