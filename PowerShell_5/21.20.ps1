# alle Fehler abfangen:
$Backup = $ErrorActionPreference
$ErrorActionPreference = 'Stop'

trap [System.DivideByZeroException]
{
  Write-Warning 'Sie haben durch null dividiert'
  continue
}

trap [System.Management.Automation.ItemNotFoundException]
{
  Write-Warning "Ein Element wurde nicht gefunden: $_"
  continue
}

trap [Microsoft.PowerShell.Commands.ProcessCommandException]
{
  Write-Warning 'Sie haben Get-Process einen Prozessnamen genannt, aber solch ein Programm läuft nicht.'
  continue
}

trap [System.Management.Automation.RemoteException]
{
  Write-Warning "Es ist ein Problem beim Aufruf eines Konsolenbefehls aufgetreten: $_"
  continue
}

trap [System.Management.Automation.DriveNotFoundException]
{
  Write-Warning 'Laufwerk nicht gültig'
  continue
}

trap [System.UnauthorizedAccessException]
{
  Write-Warning 'Fehlende Zugriffsrechte'
  continue
}

trap [System.NotSupportedException]
{
  Write-Warning "Nicht unterstützt: $_"
  continue
}

trap
{
  Write-Warning ('Unbekannter Fehler: {0} (Typ: [{1}])' -f $_, $_.Exception.GetType().FullName)
  continue
}

Get-ChildItem -Path c:\gibtesnicht
Get-ChildItem -Path h:\
$null = New-Item -Path c:\windows\test -ItemType Directory
1/$null
Get-Process -Name gibtsnicht
net.exe user gibtsnicht

# vorheriges Fehlerverhalten wiederherstellen:
$ErrorActionPreference = $Backup
