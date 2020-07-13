$path = "$env:temp\sample.log"
$muster = '(Server_\d{5})\s{1,}(\w{1,})'

Get-Content -Path $path |
  Where-Object { $_ -match $muster } |
  ForEach-Object { $matches[1], $matches[2] }
