$Version = @{Name='Version'; Expression={ $_.VersionInfo.ProductVersion }}

Get-ChildItem -Path c:\windows\system32 | 
  Where-Object { ($_.VersionInfo.ProductVersion -as [Version]) -gt '6.0.0.0' } |
  Select-Object -Property Name, $Version
