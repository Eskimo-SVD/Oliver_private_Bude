$ips = 1..255 | ForEach-Object { "192.168.2.$_" }
$job = Test-Connection $ips -ErrorAction SilentlyContinue -Count 1 -AsJob
$null = Wait-Job $job
Receive-Job $job | Where-Object { $_.ResponseTime -ne $null } | 
    Select-Object Address, ResponseTime |
    Sort-Object -Property { $_.Address -as [Version] }

Remove-Job $job
