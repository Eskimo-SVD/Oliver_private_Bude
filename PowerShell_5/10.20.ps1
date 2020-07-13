$path = "$env:temp\sample.log"
$muster = '(?<Server>Server_\d{5})\s{1,}(?<Status>\w{1,})'

Get-Content -Path $path |
  Where-Object { $_ -match $muster } |
  ForEach-Object { 
    New-Object -TypeName PSObject -Property $matches |
    Select-Object -Property Server, Status
  }
