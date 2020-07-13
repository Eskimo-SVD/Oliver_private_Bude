#requires -Version 5

$archive = Join-Path -Path $env:temp -ChildPath winScripts.zip

# alle PowerShell-Skripts im gesamten Windows-Ordner finden
# (ersetzen Sie $env:windir durch $home, wenn Sie stattdessen alle 
# PowerShell-Skripts in Ihrem Benutzerprofil sichern wollen)
Get-ChildItem -Path $env:windir -Filter *.ps1 -Recurse -ErrorAction SilentlyContinue -File |
    # Get-ChildItem liefert trotz des Filters auch *.ps1xml Dateien, daher zusätzlich
    # hier ein clientseitiger Filter:
    Where-Object Extension -eq '.ps1' |
    # Dateien in ZIP-Datei schreiben und vorhandene ZIP-Datei
    # ggfs. überschreiben (-Update):
    Compress-Archive -DestinationPath $archive -CompressionLevel Optimal -Update

# angelegte oder aktualisierte ZIP-Datei im Explorer anzeigen
explorer "/select,$destinationPath"
