$LCM = Get-WmiObject MSFT_Providers | Where-Object { $_.Provider -like 'dsccore' }
$id = $LCM.HostProcessIdentifier
Get-Process -Id $id
