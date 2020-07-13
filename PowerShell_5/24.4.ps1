$Code = @'

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

'@

New-Item -Path "$env:ProgramFiles\WindowsPowerShell\Modules\Microsoft.Angriff\Microsoft.Angriff.psm1" -ItemType File -Value $Code -Force
