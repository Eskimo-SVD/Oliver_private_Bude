$info = @{
  AllNodes = @(
    @{
      NodeName = 'localhost'
      PSDscAllowPlainTextPassword = $true
      Credential = Get-Credential $env:username
      ConsoleTextColor = '0E'
    }
  )
}

Configuration SetPSConsoleTextColor
{
  Import-DscResource -ModuleName PSDesiredStateConfiguration

  Node $AllNodes.NodeName
  {
    Registry regKey
    {
      Key = 'HKEY_CURRENT_USER\Software\Microsoft\Command Processor'
      ValueName = 'DefaultColor'
      ValueData = $Node.ConsoleTextColor
      ValueType = 'DWORD'
      Ensure = 'Present'
      Force = $true
      Hex = $true
      PsDscRunAsCredential = $Node.Credential
    }
  }
}
 
$file = SetPSConsoleTextColor -ConfigurationData $info -OutputPath c:\dscConsole 
Start-DscConfiguration -Path c:\dscConsole -Wait -Verbose -ComputerName $info.AllNodes.NodeName -Force
