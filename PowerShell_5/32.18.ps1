function New-LocalUserAccount 
{
  param
  (
    [Parameter(Mandatory=$true)]
    [string]
    $Name
  )
  
  # Lokales Benutzerkonto anlegen und
  # Fehler an PowerShell zurückliefern
  $ErrorActionPreference = 'Stop'
  $null = net user $Name /ADD 2>&1
}
