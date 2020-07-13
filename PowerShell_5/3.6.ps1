# nach einem Stichwort fragen
$stichwort = Read-Host -Prompt 'Nach welchem Wort in Ihrem Skript suchen Sie'
Write-Host 'Suche läuft...' -NoNewline

# Skripts mit diesem Stichwort finden
$resultat = Get-ChildItem -Path $home -Filter *.ps1 -Recurse -ErrorAction SilentlyContinue |
  Select-String -Pattern $stichwort -List |
  Select-Object -Property LineNumber, Line, FileName, Path 

# Anzahl der Ergebnisse melden
$anzahl = $resultat.Count
Write-Host "$anzahl Ergebnisse."
  
# Nur wenn Skripts gefunden wurden, im GridView anzeigen...
if ($anzahl -gt 0)
{
  $resultat |
    Out-GridView -Title 'Datei aussuchen' -OutputMode Multiple |
    Select-Object -ExpandProperty Path |
    Foreach-Object { 
      # ...und jedes gefundene Skript mit der ISE öffnen:
      ise $_ 
    }
}
