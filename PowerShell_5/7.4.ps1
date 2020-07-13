Get-Process -id $pid |
  Format-Table -AutoSize | 
  Out-String -Width 5000 -Stream | 
  Select-Object -Skip 3
