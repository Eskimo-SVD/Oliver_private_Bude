$scriptblock = 
{
    Get-Date

    return 100

    'Dieser Teil wird nicht mehr erreicht'
}

$ergebnis = & $scriptblock
