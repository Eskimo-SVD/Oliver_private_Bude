# Notepad starten
$notepad = Start-Process -FilePath notepad -PassThru

# alle aktuell laufenden Prozesse merken
$vorher = Get-Process | 
  Add-Member -MemberType NoteProperty -Name Status -Value entfernt -PassThru

# notepad beenden und Webseite öffnen:
$notepad | Stop-Process
Start-Process -FilePath http://www.tagesschau.de

# wieder alle aktuell laufenden Prozesse merken:
$nachher = Get-Process | 
  Add-Member -MemberType NoteProperty -Name Status -Value hinzugekommen -PassThru

# Prozesslisten vergleichen
Compare-Object -Reference $vorher -Difference $nachher -Property Name, ID -PassThru |
  Select-Object -Property Name, Id, Status
