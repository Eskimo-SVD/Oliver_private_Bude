# Hinweis: wenn Sie den lokalen Computer abfragen wollen,
# muss dieses Skript mit Administrator-Rechten ausgef�hrt 
# werden

# diesen Computer mit aktueller Identit�t abfragen
$Computer1 = 'dell1'

# diesen Computer mit dem Benutzerkonto "PSRemoting" abfragen
# (Konto muss auf dem Computer existieren und �ber Adminrechte verf�gen)
$Computer2 = 'tobiasair1'
$Credential2 = Get-Credential -Credential PSRemoting

# ein leeres Array anlegen:
$Sessions = @()
# nacheinander beliebig viele manuell konfigurierte Sessions hinzuf�gen
$Sessions += New-PSSession -ComputerName $Computer1
$Sessions += New-PSSession -ComputerName $Computer2 -Credential $Credential2

# Code, der in den Sessions ausgef�hrt werden soll:
$code = 
{
  # Systeminventar als CSV generieren und in Objekte wandeln:
  $Spaltennamen = 'Hostname',
  'Betriebssystemname',
  'Betriebssystemversion',
  'Betriebssystemhersteller',
  'Betriebssystemkonfiguration',
  'BetriebssystemBuildtyp',
  'RegistrierterBenutzer',
  'RegistrierteOrganisation',
  'ProduktID',
  'Installationsdatum',
  'Systemstartzeit',
  'Systemhersteller',
  'Systemmodell',
  'Systemtyp',
  'Prozessor',
  'BIOSVersion',
  'WindowsVerzeichnis',
  'SystemVerzeichnis',
  'Startgeraet',
  'Systemgebietsschema',
  'Eingabegebietsschema',
  'Zeitzone',
  'GesamterPhysischerSpeicher',
  'Verf�gbarerPhysischerSpeicher',
  'VirtuellerArbeitsspeicherMax',
  'VirtuellerArbeitsspeicherVerf�gbar',
  'VirtuellerArbeitsspeicherVerwendet',
  'Auslagerungsdateipfad',
  'Domaene',
  'Anmeldeserver',
  'Hotfixes',
  'Netzwerkkarte',
  'HyperV'
                    


  systeminfo.exe /FO CSV | 
  Select-Object -Skip 1 |
  ConvertFrom-CSV -Header $Spaltennamen
}

# Code in allen Sessions gleichzeitig ausf�hren:
Invoke-Command -ScriptBlock $code -Session $sessions | 
  Out-GridView -Title System�bersicht

# Sessions am Ende entfernen
Remove-PSSession -Session $Sessions
