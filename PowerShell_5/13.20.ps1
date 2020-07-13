PS> $delegate = { [Version]$_ }
PS> '10.10.100.1', '2.99.1.13', '100.84.12.99' | Sort-Object -Property $delegate
2.99.1.13
10.10.100.1
100.84.12.99
