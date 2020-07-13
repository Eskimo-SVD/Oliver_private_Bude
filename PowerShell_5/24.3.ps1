function Get-SomeData
{
  $wid = [System.Security.Principal.WindowsIdentity]::GetCurrent()
  $prp = New-Object System.Security.Principal.WindowsPrincipal($wid)
  $adm = [System.Security.Principal.WindowsBuiltInRole]::Administrator
  $isAdmin = $prp.IsInRole($adm)  
  
  $info = [ordered]@{}
  $info.'Current User' = $env:USERDOMAIN + "\" + $env:username
  $info.'Is Admin?' = $isAdmin
  New-Object PSObject -Property $info
}
