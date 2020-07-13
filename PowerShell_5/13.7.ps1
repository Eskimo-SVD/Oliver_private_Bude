$scriptblock = 
{
    # Rückgabewerte definieren:
    Write-Output "Hallo", (Get-Date)

    # Alles, was liegen gelassen wird, gehört auch dazu:
    123
    Get-Item -Path $env:windir
}

$ergebnis = & $scriptblock
