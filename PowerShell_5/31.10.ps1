Add-Type -AssemblyName PresentationFramework

$dialog = New-Object -TypeName Microsoft.Win32.OpenFileDialog
$dialog.Title = 'Datei aussuchen'
$dialog.Filter = 'Alles|*.*|PowerShell|*.ps1'
$dialog.InitialDirectory = "$home\Documents"
$result = $dialog.ShowDialog()

if ($result -eq $true)
{
  $dialog.FileName
}
