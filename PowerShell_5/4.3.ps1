#requires -Version 1
$name = 'notepad'
$prozesse = Get-Process -Name $name -ErrorAction SilentlyContinue
$anzahl = $prozesse.Count 
$l�uft = $anzahl -gt 0

if ($l�uft)
{
  "Es werden $anzahl Instanzen von $name ausgef�hrt."
}
else
{
  "$name l�uft nicht."
}
