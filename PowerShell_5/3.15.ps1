#requires -Version 1

# RECENT Dateien l�schen
Get-ChildItem -Path "$env:appdata\Microsoft\Windows\Recent" -Filter *.lnk | 
  Remove-Item 

# TEMP Ordner l�schen
Get-ChildItem -Path $env:temp | Remove-Item  -Recurse -ErrorAction SilentlyContinue
