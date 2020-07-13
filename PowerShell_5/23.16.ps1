# Anmeldeinformationen für den Benutzer angeben,
# unter dem der Endpunkt ausgeführt werden soll
$msg = 'Geben Sie das Konto an, unter dem dieser Endpunkt ausgeführt werden soll!'
$Credential = Get-Credential -UserName PSRemoting -Message $msg

# Pfadname zu einer neuen pssc-Datei festlegen
$Path = "$env:temp\jea1.pssc"

# eigene Funktionen festlegen

# Get-UserInfo liefert den Wert von $PSSenderInfo zurück
# darin ist der Name des aufrufenden Anwenders zu finden
$getUserInfo = @{
  Name='Get-UserInfo'

  ScriptBlock=
  { 
    $PSSenderInfo 
  }
}

# Restart-Computer startet nur die Computer neu, die in einer
# Whitelist zugelassen sind
$restartServer = @{
  Name='Restart-Server'

  ScriptBlock=
  { 
    param
    (
      [Parameter(Mandatory=$true)]
      [String[]]
      $ComputerName
    )
    
    # Liste der zugelassenen Servernamen:
    $WhiteList = 'server1', 'exch12', $env:COMPUTERNAME
    
    $ComputerName |
      Foreach-Object {
        # ist der Servername zugelassen?
        if ($WhiteList -notcontains $_)
        {
          Write-Warning "$_ kann nicht neu gestartet werden. Fehlende Berechtigungen."
        }
        else
        {
          $_
        } 
      } |
      Restart-Computer -WhatIf  # <- ACHTUNG: erst wenn -WhatIf entfernt wird, 
                                # werden Systeme tatsächlich neu gestartet!
  }
}

# Datei anlegen
New-PSSessionConfigurationFile -Path $Path –SessionType RestrictedRemoteServer -LanguageMode NoLanguage –ExecutionPolicy Restricted -FunctionDefinitions $getUserInfo, $restartServer 

# Endpunkt anlegen:
Register-PSSessionConfiguration -Name ServerAdmins -Path $Path -RunAsCredential $Credential -ShowSecurityDescriptorUI -Force
