#requires -Version 1

$path = "$env:TEMP\data.txt"

Get-EventLog -LogName system -Newest 2 | 
  Format-Table -AutoSize -Wrap | 
  Export-Clixml -Path $path -Depth 5

notepad $path
