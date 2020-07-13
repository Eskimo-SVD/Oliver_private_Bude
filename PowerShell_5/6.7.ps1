Get-Service | 
  Select-Object -Property Name, DisplayName, Status |
  Out-Default

Get-Process | 
  Select-Object -Property Company, Name, Description |
  Out-Default  
