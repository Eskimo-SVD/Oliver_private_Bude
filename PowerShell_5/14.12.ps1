$daten = @'
Name, Vorname, ID
Weltner,Tobias,1
Schr�ter,Indra,2
Wolters,Patrik,3
'@

$Path = "$env:temp\testdaten.csv"
$daten | Set-Content -Path $Path -Encoding UTF8
