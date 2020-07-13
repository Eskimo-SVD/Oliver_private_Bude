$vorlage = 'Name: {{Vorname:Hans} {Nachname:Müller}}'
$ergebnis = 'Name: Tobias Weltner' | ConvertFrom-String -TemplateContent $vorlage
