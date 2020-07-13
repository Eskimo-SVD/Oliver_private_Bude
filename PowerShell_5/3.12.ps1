#requires -Version 1

# Pfadnamen definieren:
$desktop = "$home\Desktop"
$path = Join-Path -Path $desktop -ChildPath datei.txt

# Ergebnisse von Get-Process in Textdatei speichern:
Get-Process | Format-Table -AutoSize -Wrap | Out-File -FilePath $path -Width 120

# Ausgabedatei umbenennen
Rename-Item -Path $path -NewName prozesse.txt
