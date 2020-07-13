function Add-FromHistory
{
    $command = Get-History |
      Sort-Object -Property CommandLine -Unique |
      Sort-Object -Property ID -Descending |
      Select-Object -ExpandProperty CommandLine |
      Out-GridView -Title 'Wählen Sie einen Befehl!' -PassThru |
      Out-String

    $psISE.CurrentFile.Editor.InsertText($command)
}

try
{
$null = $pSISE.CurrentPowerShellTab.AddOnsMenu.Submenus.Add('Aus Befehlshistorie einfügen', {Add-FromHistory},
'SHIFT+ALT+H')
} catch {}
Set-Alias -Name afh -Value Add-FromHistory -ErrorAction SilentlyContinue
