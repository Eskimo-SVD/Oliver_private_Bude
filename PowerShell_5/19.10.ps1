# prüfen, ob das Skript vom Anwender korrekt aufgerufen wurde:
if ($global:MyInvocation -ne $script:MyInvocation)
{
    Write-Warning 'Starten Sie das Skript dotsourced, um die darin enthaltenen Funktionen nutzen zu können!'
    break
}

function New-Function
{
  'Ich bin eine neue Funktion!'
}

Write-Host 'Funktion New-Function ist nun einsatzbereit.' -ForegroundColor Green
