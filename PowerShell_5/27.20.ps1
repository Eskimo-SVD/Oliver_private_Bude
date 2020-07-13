#requires -Version 5

$archive = Join-Path -Path $env:temp -ChildPath winScripts.zip
$target = Join-Path -Path $env:temp -ChildPath WinScripts

# Entblocken ist nur erforderlich für ZIP-Archive, die aus dem
# Internet oder anderen potentiell unsicheren Quellen heruntergeladen
# wurden und wird hier nur der Vollständigkeit halber aufgeführt:
Unblock-File -Path $archive

# Inhalt der ZIP-Datei auspacken und vorhandene Dateien ggfs.
# überschreiben (-Force)
Expand-Archive -Path $archive -DestinationPath $target -Force

# entpackten Ordner im Explorer anzeigen
explorer.exe $target
