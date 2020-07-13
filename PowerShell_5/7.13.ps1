$path = "$env:temp\report.hta"

$style = @'
 <title>Laufende Prozesse</title>
 <style>
  body { background-color:#EEEEEE; }
  body,table,td,th { font-family:Tahoma; color:Black; Font-Size:10pt; padding: 15px; }
  th { font-weight:bold; background-color:#AAFFAA; text-align: left;}
  td { background-color:#EEFFEE; }
 </style>
'@

Get-Process | 
  ConvertTo-Html Name, Company, CPU -Head $style  | 
  Set-Content -Path $Path -Encoding UTF8

Invoke-Item -Path $Path
