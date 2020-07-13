#requires -Version 1
$name = 'notepad'
$prozesse = Get-Process -Name $name -ErrorAction SilentlyContinue
$anzahl = $prozesse.Count 
$läuft = $anzahl -gt 0

if ($läuft)
{
  "Es werden $anzahl Instanzen von $name ausgeführt."
}
else
{
  "$name läuft nicht."
}
