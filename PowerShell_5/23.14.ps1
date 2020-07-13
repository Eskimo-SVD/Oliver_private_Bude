# Pfadname zu einer neuen pssc-Datei festlegen
$Path = "$env:temp\DruckerAdmin.pssc"

# Datei anlegen
New-PSSessionConfigurationFile -Path $Path –SessionType RestrictedRemoteServer -LanguageMode NoLanguage –ExecutionPolicy Restricted –ModulesToImport PrintManagement -VisibleFunctions Get-Printer, Add-Printer

# Dateiinhalt anzeigen
notepad $path
