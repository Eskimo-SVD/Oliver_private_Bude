Configuration TestScriptResource
{
  Import-DscResource -ModuleName PSDesiredStateConfiguration

  Node localhost
  {
    Script customScript
    {
      GetScript = {
        # Registry ansprechen und Werte aus einem Schlüssel lesen:
        $key = 'Registry::HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion'
        $values = Get-ItemProperty -Path $key

        # für diese Konfiguration relevante Werte als Hashtable zurückliefern:
        $returnValue = @{
          RegisteredOwner = $values.RegisteredOwner
          RegisteredOrganization = $values.RegisteredOrganization
        }

        $returnValue
      }
      TestScript = {
        $RegisteredOwner = 'Tobias Weltner'
        $RegisteredOrganization = 'powertheshell.com'

        $key = 'Registry::HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion'
        $values = Get-ItemProperty -Path $key
        
        # entspricht diese den Wünschen?
        $wert1OK = $values.RegisteredOwner -eq $RegisteredOwner
        $wert2OK = $values.RegisteredOrganization -eq $RegisteredOrganization
        
        $wert1OK -and $wert2OK
      }
      
      SetScript = {
        $RegisteredOwner = 'Tobias Weltner'
        $RegisteredOrganization = 'powertheshell.com'

        # Registrierungsschlüssel, der geändert wird
        $key = 'Registry::HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion'
        Write-Verbose "Updating Owner Info: $RegisteredOwner $RegisteredOrganization"
        Set-ItemProperty -Path $key -Name RegisteredOwner -Value $RegisteredOwner
        Set-ItemProperty -Path $key -Name RegisteredOrganization -Value $RegisteredOrganization
      }
    }
  }
}
 
$file = TestScriptResource -ConfigurationData $info -OutputPath c:\dscTest 
Start-DscConfiguration -Path c:\dscTest -Wait -Verbose -ComputerName localhost -Force

# Erfolg der Konfiguration prüfen:
winver.exe
