$message = 'Suchen Sie sich einen Ordner aus!'
$path = "$HOME\Documents"

$object = New-Object -ComObject Shell.Application
$folder = $object.BrowseForFolder(0, $message, 0, $path)
if ($folder -ne $null)
{
  $folder.self.Path
}
