$shell = New-Object -ComObject WScript.Shell

$LinkFile = 'Windows PowerShell.lnk'
$Desktop = $shell.SpecialFolders.Item('Desktop')

$Path = Join-Path -Path $Desktop -ChildPath $LinkFile

# Pfad zum AKTUELLEN PowerShell-Host ermitteln:
$TargetPath = (Get-Process -id $pid).Path

# Link-Datei anlegen:
$shortcut = $shell.CreateShortcut($path)
# erstes Icon in der EXE-Datei verwenden:
$shortcut.IconLocation = '{0},{1}' -f $TargetPath, 0
$shortcut.TargetPath = $TargetPath

$shortcut.Save()
