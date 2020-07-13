# im ISE-Editor ausführen!

Import-Module -Name NetTCPIP
$base = (Get-Module -Name NetTCPIP).ModuleBase
$path = Join-Path -Path $base -ChildPath 'Test-NetConnection.psm1'

$file = $psise.CurrentPowerShellTab.Files.Add()
$file.Editor.Text = Get-Content -Path $path -Raw
$file.Editor.SetCaretPosition(1,1)
