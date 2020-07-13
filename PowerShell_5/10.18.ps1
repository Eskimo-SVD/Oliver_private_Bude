$path = "$env:temp\sample.log"
$muster = 'Server_\d{5}'

Get-Content -Path $path |
  Where-Object { $_ -match $muster } |
  ForEach-Object { $matches[0] }
