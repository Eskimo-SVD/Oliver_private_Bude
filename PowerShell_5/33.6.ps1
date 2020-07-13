function prompt
{
  $wid = [System.Security.Principal.WindowsIdentity]::GetCurrent()
  $prp = New-Object System.Security.Principal.WindowsPrincipal($wid)
  $adm = [System.Security.Principal.WindowsBuiltInRole]::Administrator
  $isAdmin = $prp.IsInRole($adm) 
  
  if ($isAdmin)
  {
    Write-Host '[ADMIN]' -ForegroundColor Red -NoNewline
  }
  else
  {
    Write-Host '[NONADMIN]' -ForegroundColor Green -NoNewline
  }
  
  # immer mindestens ein Zeichen ausgeben 
  'PS> '
  $host.UI.RawUI.WindowTitle = Get-Location
}
