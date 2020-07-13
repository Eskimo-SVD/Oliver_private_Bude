$xml = New-Object xml
$xml.Load("$env:temp\mitarbeiter.xml")
$xml.Belegschaft.Mitarbeiter
