$info = @{
  AllNodes = @(
    @{
      NodeName = 'localhost'
      Thumbprint =      '3C11ED594A9E34554B09614784FA555932498FF7'
      CertificateFile = 'C:\Users\Tobias\AppData\Local\Temp\DSCTestCertificate\DSCTestCert.cert'
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
    LocalConfigurationManager 
    { 
      CertificateId = $node.Thumbprint 
    }

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
