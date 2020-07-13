$start = Get-Date

# gesamte Logik als Skriptblock verpacken...
$code = 
{
  $Version = @{Name='Version'; Expression={ $_.VersionInfo.ProductVersion }}

  Get-ChildItem -Path c:\windows\system32 | 
  Where-Object { ($_.VersionInfo.ProductVersion -as [Version]) -gt '6.0.0.0' } |
  Select-Object -Property Name, $Version
}

# ...und dann komplett auf der Serverseite ausführen:
$dateien = Invoke-Command $code -Computername dell1
 
$ende = Get-Date
$sekunden = ($ende-$start).TotalSeconds
Write-Warning "Gesamtdauer $sekunden sec."
