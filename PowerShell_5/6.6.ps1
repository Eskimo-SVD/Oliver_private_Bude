# Workaround für PowerShell Version 1,2,3,4:

Get-Process | 
  Select-Object -Property Name, Id |
  Format-Table -AutoSize

Get-Process | 
  Select-Object -Property Id |
  Format-Table -AutoSize
