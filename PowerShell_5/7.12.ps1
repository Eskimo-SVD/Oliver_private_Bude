$path = "$env:temp\report.htm"
Get-Process | ConvertTo-Html Name, Company, CPU | Set-Content -Path $path -Encoding UTF8
Invoke-Item -Path $path
