$scriptblock = 
{
    Write-Host 'Gebe Datum aus.' -ForegroundColor DarkGreen -BackgroundColor White
    Get-Date
}

$ergebnis = & $scriptblock
$ergebnis
