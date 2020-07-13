# Inhalt des Windowsordners untersuchen
Get-ChildItem -Path $env:windir |
  # alle Eigenschaften finden
  Get-Member -MemberType *Property | 
  # die sich ändern lassen
  Where-Object { $_.Definition -like '*set;*' } | 
  Select-Object -Property * | 
  Sort-Object Name | 
  Out-GridView
