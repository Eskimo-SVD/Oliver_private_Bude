$Path = "$env:temp\Fehlerreport.txt"

Get-EventLog -LogName System -EntryType Error -Newest 5 |
  Format-Table -AutoSize -Wrap |
  Out-File -FilePath $Path -Width 150

Invoke-Item -Path $Path
