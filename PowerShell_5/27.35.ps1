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
