$path = "$HOME\Documents\WindowsPowerShell\Modules\MySystemTools\mysystemtools.psd1"
$content = Get-Content -Path $path -Raw
$info = Invoke-Expression $content

$info
