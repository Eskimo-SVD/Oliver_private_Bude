$scriptblock = 
{
    # R�ckgabewerte definieren:
    Write-Output "Hallo", (Get-Date)

    # Alles, was liegen gelassen wird, geh�rt auch dazu:
    123
    Get-Item -Path $env:windir
}

$ergebnis = & $scriptblock
