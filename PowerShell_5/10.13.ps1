$vorlage = 'Name: {{Vorname:Hans} {Nachname:M�ller}}'
$ergebnis = 'Name: Tobias Weltner' | ConvertFrom-String -TemplateContent $vorlage
