$auswahl = [System.Management.Automation.Host.ChoiceDescription[]]('&Ja','&Nein')
$antwort = $Host.UI.PromptForChoice('Reboot', 'Darf das System jetzt neu gestartet werden?',$auswahl,1)
