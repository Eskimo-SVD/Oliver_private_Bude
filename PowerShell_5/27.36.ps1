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
