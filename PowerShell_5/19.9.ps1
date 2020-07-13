function Test-DotSourced
{
    $global:MyInvocation -eq $script:MyInvocation
}

if (Test-DotSourced)
{
    'Skript wurde dot-sourced im Aufruferkontext aufgerufen.'
}
else
{
    'Skript wurde isoliert im eigenen Kontext aufgerufen'
}
