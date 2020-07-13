# häufig verwendete Editor-Einstellungen:
$psISE.Options.AutoSaveMinuteInterval = 1
$psISE.Options.IntelliSenseTimeoutInSeconds = 1
$psISE.Options.ShowWarningBeforeSavingOnRun = $false
$psISE.Options.Zoom = 100

# Liste zuletzt geöffneter Skriptdateien im Menü "Datei" löschen:
$psISE.Options.MruCount = 0
$psISE.Options.MruCount = 15

# Farben der Token für "Variablen" in der Konsole auf vordefinierte Farbe setzen:
$psISE.Options.ConsoleTokenColors['Variable'] = 'Red'
# Farben der Token für "Variablen" im Editor auf selbstdefinierte Farbe setzen:
$psISE.Options.TokenColors['Variable'] = '#90FF1012'

# Farben der Standardfehlermeldungen ändern
$psISE.Options.ErrorBackgroundColor = 'White'
$psISE.Options.ErrorForegroundColor = 'Red'
