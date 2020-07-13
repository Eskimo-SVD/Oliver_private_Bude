function Get-TargetResource
{
  [CmdletBinding()]
  [OutputType([System.Collections.Hashtable])]
  param
  (
    [Parameter(Mandatory=$true)]
    [AllowEmptyString()]
    [System.String]
    $RegisteredOwner = '',

    [Parameter(Mandatory=$true)]
    [AllowEmptyString()]
    [System.String]
    $RegisteredOrganization = '',

    [ValidateSet('Absent','Present')]
    [System.String]
    $Ensure
  )

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

function Set-TargetResource
{
  [CmdletBinding()]
  param
  (
    [Parameter(Mandatory=$true)]
    [AllowEmptyString()]
    [System.String]
    $RegisteredOwner = '',

    [Parameter(Mandatory=$true)]
    [AllowEmptyString()]
    [System.String]
    $RegisteredOrganization = '',

    [ValidateSet('Absent','Present')]
    [System.String]
    $Ensure
  )

  # Registrierungsschlüssel, der geändert wird
  $key = 'Registry::HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion'
  
  # Werte neu eintragen
  if ($Ensure -eq 'Present')
  {
    Write-Verbose "Updating Owner Info: $RegisteredOwner $RegisteredOrganization"
    Set-ItemProperty -Path $key -Name RegisteredOwner -Value $RegisteredOwner
    Set-ItemProperty -Path $key -Name RegisteredOrganization -Value $RegisteredOrganization
  }
  # Werte entfernen
  elseif ($Ensure -eq 'Absent')
  {
    Write-Verbose 'Clearing Owner Info'
    Clear-ItemProperty -Path $key -Name RegisteredOwner 
    Clear-ItemProperty -Path $key -Name RegisteredOrganization 
  }
}

function Test-TargetResource
{
  [CmdletBinding()]
  [OutputType([System.Boolean])]
  param
  (
    [Parameter(Mandatory=$true)]
    [AllowEmptyString()]
    [System.String]
    $RegisteredOwner = '',

    [Parameter(Mandatory=$true)]
    [AllowEmptyString()]
    [System.String]
    $RegisteredOrganization = '',

    [ValidateSet('Absent','Present')]
    [System.String]
    $Ensure
  )

  # aktuelle Konfiguration lesen
  $aktuell = Get-TargetResource -RegisteredOwner $RegisteredOwner -RegisteredOrganization $RegisteredOwner
    
  # entspricht diese den Wünschen?
  $wert1OK = $aktuell.RegisteredOwner -eq $RegisteredOwner
  $wert2OK = $aktuell.RegisteredOrganization -eq $RegisteredOrganization
    
  $wert1OK -and $wert2OK
}

Export-ModuleMember -Function *-TargetResource
