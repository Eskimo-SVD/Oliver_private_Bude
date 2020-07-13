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
