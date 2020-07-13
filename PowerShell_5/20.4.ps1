Write-Debug 'Beginne'

$fixes = Get-HotFix

Write-Debug 'Vor Schleife'

foreach($fix in $fixes)
{
    Write-Debug 'Ausgabe einzelner Fix' -Verbose
    $fix.HotfixID
}

Write-Debug 'Fertig'
