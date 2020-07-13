$start = Get-Date

$Version = @{Name='Version'; Expression={ $_.VersionInfo.ProductVersion }}

$dateien = Invoke-Command { Get-ChildItem -Path c:\windows\system32 } -Computername dell1

$dateien | 
  Where-Object { ($_.VersionInfo.ProductVersion -as [Version]) -gt '6.0.0.0' } |
  Select-Object -Property Name, $Version
  
$ende = Get-Date
$sekunden = ($ende-$start).TotalSeconds
Write-Warning "Gesamtdauer $sekunden sec."
