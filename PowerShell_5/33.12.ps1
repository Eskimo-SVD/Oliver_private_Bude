function New-Script
{
  $Autor = '[Ihr Name]'
  $Datum = Get-Date -Format 'yyyy-MM-dd'

  $text = @"
########################
#
# Autor:   $Autor
# Version: 1.0
# Datum:   $datum
#
########################


"@

  $file = $psise.CurrentPowerShellTab.Files.Add()
  $file.Editor.Text = $text
  $file.Editor.SetCaretPosition(1,1)
  $file.Editor.SetCaretPosition($file.Editor.LineCount,1)
}

$null = $psISE.CurrentPowerShellTab.AddOnsMenu.Submenus.Add('Neues Skript', { New-Script }, 'CTRL+ALT+N')
