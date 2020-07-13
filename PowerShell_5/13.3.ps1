$eigenerProzess = Get-Process -id $pid
$fremderProzess = powershell.exe { Get-Process -id $pid }

$eigenerProzess
$fremderProzess
