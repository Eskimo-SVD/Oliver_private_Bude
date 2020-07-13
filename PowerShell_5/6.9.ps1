$liste = Get-Service
$liste.Where({$_.Status -eq 'Running'})
