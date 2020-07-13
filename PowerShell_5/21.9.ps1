try
{
    # Cmdlet-Fehler, ben�tigt ErrorAction=Stop
    $ErrorActionPreference = 'Stop'
    Get-ChildItem -Path GibtEsNicht
}
catch
{
    "Fehler entdeckt: $_"
}

try
{
    # Konsolenbefehl-Fehler ben�tigt ErrorAction=Stop
    # und Umleitung des Fehlerkanals
    $ErrorActionPreference = 'Stop'
    net user GibtEsNicht 2>&1
}
catch
{
    "Fehler entdeckt: $_"
}

try
{
    # .NET-Fehler ben�tigt keine besondere ErrorAction
    [System.Net.DNS]::GetHostByName('gibtesnicht')
}
catch
{
    "Fehler entdeckt: $_"
}
